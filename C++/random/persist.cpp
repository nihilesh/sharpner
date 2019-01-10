#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <array>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <assert.h>

using namespace std;

template <class T, size_t n=10>
class PersistentSeries {
    private:
        string _name;
        int _fd;

        const char* STORAGE_PATH = "/tmp";
        string _filepath;
        size_t _filesize;

        uint _head;
        uint _tail;
        size_t _size;
        T* _arr;


        void
        allocate_persistent_memory() {

            _fd = open(_filepath.c_str(), O_RDWR | O_CREAT | O_APPEND, (mode_t)0660);
            if (_fd == -1)
            {
                perror("Error opening file for writing");
                exit(EXIT_FAILURE);
            }

            /* Stretch the file size to the size of the (mmapped) collection size */
            off_t result = lseek(_fd, _filesize - 1, SEEK_SET);
            if (result == -1)
            {
                close(_fd);
                perror("Error calling lseek() to 'stretch' the file");
                assert(false && "Error calling lseek() to 'stretch' the file");
            }

            result = write(_fd, "", 1);
            if (result != 1)
            {
                close(_fd);
                perror("Error writing last byte of the file");
                assert(false && "Error writing last byte of the file");
            }

            /* Now the file is ready to be mmapped.
            */
            _arr = (T *) mmap(NULL, _filesize, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
            if (_arr == MAP_FAILED)
            {
                close(_fd);
                perror("Error mmapping the file");
                assert(false && "Error mmapping the file");
            }
            close(_fd);
        }

    public:
        PersistentSeries(string name): _name(name), _head(0),_tail(0),_size(n){
            _filepath = STORAGE_PATH +  string("/") + _name + string(".bin");
            _filesize = sizeof(T) * n;

            // Allocate shared memory by name of PersistentSeries
            allocate_persistent_memory();
        }

        PersistentSeries(string name, array<T, n>& arr): PersistentSeries(){
            for (auto iter=arr.begin(); iter!=arr.end(); iter++){
                enqueue(*iter);
            }
        }

        ~PersistentSeries() {
            munmap((void*) _arr, sizeof(T)*n);
        }

        uint len(){
            if (_tail > _head) {
                return _tail - _head;
            }
            return _size - _head + _tail;
        }

        bool isFull(){
            return _head + 1 == _tail;
        }

        bool isEmpty(){
            return _tail == _head;
        }

        void enqueue(const T& t) {
            if (isFull()){
                dequeue();
            }
            _arr[_head++ % _size] = t;
        }

        T* dequeue(){
            if (isEmpty()){
                return NULL;
            }
            return &_arr[_tail++];
        }

        size_t 
        size() const {
            return _size;
        }

        friend
        ostream & operator << (ostream& out, const PersistentSeries<T, n>& arr_q) {
                out << "[";
                for (uint i=0; i<arr_q.size(); i++) {
                    out << arr_q._arr[i] << ((i < arr_q.size()-1) ? ", " : "");
                }
                out << "]";
                return out;
        }


};

int main(){
    PersistentSeries<int, 10> series("test");
    std::cout << "Initial series data: " << series << endl;
    
    while(true) {
        int i = 0;
        cout << "In loop doing stuff... feel free to kill any time, will retain the data" << endl;
        cout << "Enter number to append to series:"; 
        cin >> i;
        series.enqueue(i);
        std::cout << "Updated series data: " << series << endl << endl;
    }
    return 0;
}
