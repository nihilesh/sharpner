#include <iostream>
#include <assert.h>
#include <memory>
using namespace std;

class MyClass {
    public:
        void foo() {
            cout << "This is foo" << endl;
        }
        MyClass() {
            cout << "MyClass constructed" << endl;
        }
        ~MyClass() {
            cout << "MyClass destructed" << endl;
        }

};

template<class T>
class myunique_ptr{
    private:
        T * _ptr;
    public:
        explicit myunique_ptr(T *t): _ptr(t){}
        // myunique_ptr(const myunique_ptr<T>& u) = delete; implicitly delete when move constructor is defined.
        myunique_ptr(myunique_ptr<T>&& u): _ptr(move(u._ptr)){}
        myunique_ptr& operator = (const myunique_ptr& u) = delete; 
        ~myunique_ptr() { delete _ptr; _ptr=nullptr;}

        T& operator * (){
            return *_ptr;
        }
        T* operator -> (){
            return _ptr;
        }
};

template<class T>
class myshared_ptr{
    private:
        pair<T*, int>* _ptr;
    public:
        myshared_ptr(): _ptr(new pair<T*, int>(NULL, 0)) {
            cout << "myshared_ptr(), refcount: " << 0 << endl;
        }
        explicit myshared_ptr(T* t): _ptr(new pair<T*, int>(t, 1)) {
            cout << "myshared_ptr(T *t), refcount: " << 1 << endl;
        }
        myshared_ptr(const myshared_ptr<T>& sp): _ptr(sp._ptr) {_ptr->second++;
            cout << "myshared_ptr(const myshared_ptr<T>& sp), refcount: " << _ptr->second << endl;
        }
        myshared_ptr(myshared_ptr<T>&& spr): _ptr(move(spr._ptr)) {
            cout << "myshared_ptr(myshared_ptr<T>&& spr), refcount: " << _ptr->second << endl;
        }
        myshared_ptr& operator = (const myshared_ptr<T>& ptr) {
            _ptr = ptr._ptr;
            _ptr->second++;
            cout << "operator = , refcount: " << _ptr->second << endl;
            return *this;
        }
        ~myshared_ptr() {
            cout << "~myshared_ptr " << endl;
            if (!_ptr) return;
            if (_ptr->second) { 
                _ptr->second--;
                cout << "refcount: " << _ptr->second << endl;
            } 
            if (!_ptr->second) {
                cout << "refcount 0" << endl;
                delete _ptr->first;
                delete _ptr;
                _ptr = NULL;
            }
        }
        T& operator * (){
            cout << "oeprator *" << endl;
            assert(_ptr && "empty pointer");
            return *(_ptr->first);
        }
        T* operator -> (){
            cout << "oeprator ->" << endl;
            assert(_ptr && "empty pointer");
            return _ptr->first;
        }

};

int 
main(){
    {
        cout << "Standard unique_ptr" << endl;
        unique_ptr<MyClass> uptr(new MyClass);
        //unique_ptr<MyClass> uptr1 = new MyClass;
        //unique_ptr<MyClass> uptr;
        uptr->foo();
    }
    {
        cout << "My unique_ptr" << endl;
        //myunique_ptr<MyClass> uptr;
        myunique_ptr<MyClass> uptr(new MyClass);
        //myunique_ptr<MyClass> uptr1 = new MyClass;
        //myunique_ptr<MyClass> uptr2 = uptr;
        uptr->foo();
    }
    {
        cout << "Standard shared_ptr" << endl;
        shared_ptr<MyClass> sp1;
        {
            shared_ptr<MyClass> sp(new MyClass);
            sp1 = sp;
        }
        sp1->foo();
    }
    {
        cout << "My shared_ptr" << endl;
        myshared_ptr<MyClass> sp1;
        {
            myshared_ptr<MyClass> sp(new MyClass);
            sp1 = sp;
        }
        sp1->foo();
    }
    getchar();
    return 0;
}