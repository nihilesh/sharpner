#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

class Statistics {
	int drops;
	int total;

public:
	Statistics(int drops, int total): drops(drops), total(total){}
	const int
	getDrops() const {
		return drops;
	}
	const int
	getTotal() const {
		return total;
	}
};


int main() {;
	typedef const int (Statistics::* Fn) () const;
	const map<int, Fn> statsMap = {
			{1, &Statistics::getDrops},
			{2, &Statistics::getTotal},
	};

	Statistics s(5, 10);

	for (auto iter=statsMap.begin(); iter != statsMap.end(); iter++){
		cout << "id " << iter->first << " function: " << ((&s)->*(iter->second))() << endl;
	}
	return 0;
}
