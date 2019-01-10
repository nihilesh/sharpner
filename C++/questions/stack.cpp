#include <iostream>
#include <vector>
#include <array>
#include <stdlib.h>
#include <assert.h>

using namespace std;


template <typename T>
class Stack {
    private:
        T *_stack;
        int _pos;
        size_t capacity;
        const static long unsigned int INCREMENT = 4;

    public:
        Stack(): _pos(-1), capacity(1) {
            _stack = static_cast<T*>(malloc(sizeof(T)*capacity));
            assert(_stack && "insufficient memory");
        }
        virtual ~Stack() {
            free(_stack);
        }
        bool empty() {
            return _pos < 0;
        }
        bool full() {
            assert(capacity && "initial capacity can not be 0");
            return _pos >= (int)capacity-1;
        }
        void resize(){
            capacity = capacity + INCREMENT;
            _stack = static_cast<T*>(realloc(_stack, sizeof(T)*capacity));
            assert(_stack && "Insufficient memory");
        }
        T& pop() {
            assert(!empty());
            return _stack[_pos--];
        }
        void push(T t) {
            if (full()){
                resize();
            }
            _stack[++_pos]=t;
        }

        class iterator {
            private:
                T *ptr;
            public:
                iterator(T* data):  ptr(data) {}
                typedef iterator self_type;
                typedef T& reference;
                typedef T* pointer;
                reference operator *(){return *ptr;}
                pointer operator ->(){return ptr;}
                reference operator++ (){ ptr++; return *this;}
                self_type operator++ (int junk){ ptr++; return *this;}
                bool operator == (self_type& rhs){return ptr == rhs.ptr;}
                bool operator != (const self_type& rhs){return ptr != rhs.ptr;}
        };

        iterator begin(){ return iterator(_stack);}
        iterator end(){return iterator(_stack+_pos+1);}

};

int main(){
    { // vector is stack
        vector<int> v;
        cout << "initially:" << endl;
        cout << "size: " << v.size() << "\n";
        cout << "capacity: " << v.capacity() << "\n";
        cout << "max_size: " << v.max_size() << "\n";
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        cout << "After pushing 3 elements:" << endl;
        cout << "size: " << v.size() << "\n";
        cout << "capacity: " << v.capacity() << "\n";
        cout << "max_size: " << v.max_size() << "\n";
        while(!v.empty()){
            cout << " " << v.back();
            v.pop_back();
        }
        cout << endl;
        cout << "After poping 3 elements" << endl;
        cout << "size: " << v.size() << "\n";
        cout << "capacity: " << v.capacity() << "\n";
        cout << "max_size: " << v.max_size() << "\n";
    }
    { //Mystack
        cout << endl << "MyStack" << endl;
        Stack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        // while(!s.empty()){
        //     cout << " " << s.pop();
        // }
        for(auto iter=s.begin(); iter!=s.end(); iter++){
            cout << " " << *iter;
        }
        cout << endl;
    }
    return 0;
}