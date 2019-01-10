#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> visited;
        int max=0, begin = 0;
        int pos = 0;
        while(pos < s.length()) {
            if (visited.find(s[pos]) == visited.end()) {
                visited[s[pos]] = pos;
            } else {
                int len = pos - begin;
                max = len > max ? len : max;
                pos = visited[s[pos]];
                begin = pos+1;
                visited.clear();
            }
            pos++;
        }
        int len =  begin == 0 ? pos : pos - begin;
        max = max > len ? max: len;
        return max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str("abacdef");
    cout << "String: " << str << endl;
    cout << "Longest unique substring length: " << s.lengthOfLongestSubstring(str)<< endl;

    return 0;
}

a = [0, 2] = 2
b = [1] = len-1
c = [2]
d = 3
e=4
f=5

2 = a
