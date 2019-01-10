/*
 * Inherit.h
 *
 *  Created on: Sep 16, 2018
 *      Author: atul
 */

#ifndef INHERIT_H_
#define INHERIT_H_
#include <iostream>

using namespace std;

class A {
public:
    A(){
        cout << "A's constructor" << endl;
    }
    virtual ~A(){
        cout << "A's destructor" << endl;
    }
    virtual void foo() {
        cout << "A's foo" << endl;
    }
};

class B : public A {
public:
    B(){
        cout << "B's constructor" << endl;
    }
    ~B(){
        cout << "B's destructor" << endl;
    }
    void foo() {
        cout << "B's foo" << endl;
    }
};

class C : public B {
public:
    C(){
        cout << "C's constructor" << endl;
    }
    ~C(){
        cout << "C's destructor" << endl;
    }
    void foo() {
        cout << "C's foo" << endl;
    }
};


int main(){
    {
        cout << endl << "a as A : " << endl;
        A a;
        a.foo();
        cout << endl << "b as A : "<< endl;
        B b;
        b.foo();
        cout << endl << "c as A : "<< endl;
        C c;
        c.foo();
        cout << endl;
    }
    {
        cout << endl << "*ap as A ptr: " << endl;
        A *ap = new A;
        ap->foo();
        delete ap;
        cout << endl << "*ap as B ptr: " << endl;;
        ap = new B;
        ap->foo();
        delete ap;
        cout << endl << "*ap as C ptr: " << endl;;
        ap = new C;
        ap->foo();
        delete ap;
        cout << endl;
    }
}

#endif /* INHERIT_H_ */
