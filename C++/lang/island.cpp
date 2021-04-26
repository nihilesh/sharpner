#include <iostream>
#include <vector>
using namespace std;
using node = pair<int, int>;

class IslandFinder
{

    IslandFinder(const vector<vector<int>> metrix) : metrix(metrix) {}
    vector<vector<int>> metrix;
    int rows = metrix.size();
    int cols = metrix[0].size();
};

int main()
{
    vector<vector<int>> metrix{{1, 1, 0, 0, 0},
                               {0, 1, 0, 0, 1},
                               {1, 0, 0, 1, 1},
                               {0, 0, 0, 0, 0},
                               {1, 0, 1, 0, 1}};
    vector<vector<pair<int, int>>> IslandFinder(metrix);
}
