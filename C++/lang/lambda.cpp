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

using namespace std;

int main() {
	std::array<std::string, 3> str_array {{"1", "2", "3"}};
	std::string o_str;
	std::for_each(str_array.begin(), str_array.end(), [&o_str](string s){ o_str += s + "-"; });
	o_str.pop_back();
	cout << "Concatenated string: " << o_str << std::endl;
}


