#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        cout << "Find palindrome in : " << s << endl;
        if (s.length() < 2 ) {
            cout << "Length less than 2" << endl;
            return s;
        }
        const char* str = s.c_str();
        std::string max_pal;
        const char *pos=str+1, *rpos=str;
        bool repeat = false;
        for (int idx=0; 
             idx < s.length()-1;
             pos=str+idx+1, rpos=str+idx) {
            cout << "Processing index:" << idx << endl;
            std::string pal;
            bool first = true;
            while(rpos >= str && pos < str+s.length()){
                if (*pos != *rpos || (repeat && first)) {
                    cout << "pos != rpos: " << *pos << " != " << *rpos << endl;
                    if (!first) {
                        cout << "not first, no more palindrome, so far collected: " << pal << endl;
                        break;
                    }
                    pal.append(1, *rpos);
                    rpos--; first=false; repeat=false;
                    continue;
                }
                if (first){
                    repeat = true;
                }
                pal.append(1, *pos);
                pal.insert(0, 1, *rpos);
                pos++; rpos--;first=false; 
            }
            if (pal.length() > max_pal.length()) {
                cout << "Pal found is max: " << pal << endl;
                max_pal = pal;
            }
            if (repeat){//first matched
                cout << "Repeat is set to true, skip index" << endl;
                if (max_pal.length() > ((s.length()-idx-1)*2+1)) {
                    cout << "No more possibility of finding pal: " << ((s.length()-idx-1)*2+1) << ">" << max_pal.length() << endl;
                    break;
                }
            } else {
                cout << "Repeat is false, next index" << idx << endl;
                if (max_pal.length() > ((s.length()-idx-2)*2+1)) {
                    cout << "No more possibility of finding pal: " << ((s.length()-idx-1)*2+1) << ">" << max_pal.length() << endl;
                    break;
                }
                idx++;
            }
        }
        return max_pal;
    }
};


class Solution2 {
    public:
        string longestPalindrome(string s) {
            cout << "Searching string: " << s << endl;
            if (s.length() < 2){
                return s;
            }
            int max_len = 0, p_start=0, p_end=0;
            for (int i=0; i < s.length()-1; i++) {
                int len_0 = get_palindrom_len(s, i, i+1);
                int len_1 = get_palindrom_len(s, i-1, i+1);
                int len = len_0 > len_1 ? len_0 : len_1; 
                if (len >= max_len){
                    max_len = len;
                    if (len == len_0){
                        p_start = i-len+1;
                        p_end = i + len;
                    } else {
                        p_start = i - len;
                        p_end = i + len;
                    }
                }
                cout << "Index " << i << " max_len= " << max_len << " p_start: " << p_start << " p_end: " << p_end << endl;
            }
            return s.substr(p_start, (p_end-p_start+1));
        }

        int get_palindrom_len(const string& s, int lhs, int rhs) {
            int len = 0;
            for (len=0; lhs >= 0 && rhs < s.length() && s[lhs] == s[rhs]; lhs--, rhs++, len++){
                cout << "lhs=" << s[lhs] << " == " << s[rhs] << endl;
            }
            return len;
        }

};

int main(){
    vector<string> v{"cbbd", "babad", "a", "aa", "bab", "abab"};
    Solution2 sol;
    for (auto iter=v.begin(); iter!=v.end(); iter++){
        cout << sol.longestPalindrome(*iter) << endl;
    }
}
