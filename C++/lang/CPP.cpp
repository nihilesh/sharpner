//============================================================================
// Name        : CPP.cpp
// Author      : Atul Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

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
	// vector<int> v = { 1, 2, 3 };
	// for (auto i : v) {
	// 	cout << i << endl;
	// }
	// cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	// practice_vector();
	unsigned int n = true;
	cout << "n = " << n;
	return 0;
}
