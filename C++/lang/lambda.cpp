/*
 * lambda.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: atul
 */
#include <cstdlib>
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	std::array<std::string, 3> str_array {{"1", "2", "3"}};
	std::string o_str;
	std::for_each(str_array.begin(), str_array.end(), [&o_str](string s){ o_str += s + "-"; });
	o_str.pop_back();
	cout << "Concatenated string: " << o_str << std::endl;
	vector<vector<int>> f;

	for(int i = 0; i < 10 ; i++) {
		vector<int> v = vector<int>();
		cout << &v << endl;
		f.push_back(v);
	}
	for_each(f.begin(), f.end(), [](vector<int>& v){
		cout << &v << endl;
	});

}


