#include <iostream>
#include <string>

#define debug(s)  cout << s << endl;

using namespace std;

int _get_depth(const string& s, int* pos){
    debug("_get_depth(" << s << "," << *pos << ")");
    int depth = 0;
    if (*pos >= s.length()-1){
        debug("Reached end of string");
        return depth; 
    }
    char c = s[*pos];
    if (c == 'l'){
        debug("Reached leaf on pos " << *pos);
        *pos = *pos+1;
        return depth;
    }
    if (c == 'n'){
        debug("processing node at pos: " << *pos);
        int lpos = *pos;
        *pos = *pos+1;
        int left_depth = _get_depth(s, pos);
        int right_depth = _get_depth(s, pos); 
        depth = left_depth > right_depth ? left_depth: right_depth;
        debug("depth at pos " << lpos << " is left = " << left_depth << " right = " << right_depth << " depth: " << depth);
    }
    return depth + 1;
    debug("returning depth: " << depth);
}

int get_depth(string s){
    debug("get_depth(" << s << ")");
    int depth = 0;
    if (s.length() < 2){
        debug("String length less than 2");
        return s.length();
    }
    int pos = 0;
    depth = _get_depth(s, &pos);
    return depth;
}

int main() {
    string s = "nlnnlnln";
    cout << get_depth(s) << endl;
    return 0; 
}
