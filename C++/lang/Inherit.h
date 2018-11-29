/*
 * Inherit.h
 *
 *  Created on: Sep 16, 2018
 *      Author: atul
 */

#ifndef INHERIT_H_
#define INHERIT_H_
using namespace std;

class A {
public:
    A(){
        cout << "A's constructor" << endl;
    }
    ~A(){
        cout << "A's destructor" << endl;
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
};

class C : public B {
public:
    C(){
        cout << "C's constructor" << endl;
    }
    ~C(){
        cout << "C's destructor" << endl;
    }
};


int main(){
    A a;
    B b;
    C c;
}

#endif /* INHERIT_H_ */
