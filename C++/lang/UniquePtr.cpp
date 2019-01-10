#include <iostream>
#include <cstdlib>

template <class T>
class UniquePtr {
private:
		T *ptr;
public :
		~UniquePtr() {
			delete ptr;
			ptr = NULL;
		}

		UniquePtr(T *ptr): ptr(ptr) {}
};




int main() {
	return 0;
}
