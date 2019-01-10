//============================================================================
// Name        : CPP.cpp
// Author      : Atul Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
	int i;
	Node(int i):i(i) {}
	Node(const Node&): i(0) {};
	friend ostream& operator << (ostream& os, const Node& n);
};

ostream& operator << (ostream& os, const Node& n) {
	os << n.i;
	return os;
}


void practice_vector(){
	vector<Node> g;
	for (int i = 0; i < 10; i++) {
		Node n(i);
		cout << n;
		g.push_back(n);
	}
	cout << "vector = ";
	for (auto i = g.begin(); i != g.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	cout << "reverse vector = ";
	for (auto i = g.rbegin(); i != g.rend(); i++) {
		cout << *i << " ";
	}
	cout << endl;

}


int main() {
	vector<int> v = { 1, 2, 3 };
	for (auto i : v) {
		cout << i << endl;
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	practice_vector();
	signed int y = -1;
	unsigned int z = y;
	signed int i = z;
	unsigned int j = i;
	cout << "j = " << j << endl;
        double d = 1.12345678;
	uint64_t ui = 10000;
	int64_t  vv = ui/d;
	cout << "vv = " << vv << endl;
        cout << "ceil 5/1.11..15times = " << std::ceil(5/1.111111111111111) << endl; 
        cout << "ceil 5/1.11..15times2 = " << std::ceil(5/1.1111111111112) << endl; 
	return 0;
}
