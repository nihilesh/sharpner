#include<iostream>
#include <limits.h>

using namespace std;

#define debug(m) cout << m << endl;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool _validate_subtree(TreeNode* root, int *min, int *max) {
        if (!root){
            debug("Invalid root - null");
            return true;
        } 

        *min = root->val;
        *max = root->val;

        if (!root->left && !root->right) {
            debug("leaf node " << root->val << "min: " << *min << " max: " << *max);
            return true;   
        }
        
        if (root->left){
            debug("processing left node for: " << root->val);
            int left_min=INT_MIN, left_max=INT_MAX;
            if (!_validate_subtree(root->left, &left_min, &left_max)) {
                debug("left subtree invalid");
                return false;
            } 
            if (left_min > left_max){
                debug("left subtree range is invalid: min: " << left_min <<" max: " << left_max);
                return false;
            }
            if (root->val <= left_max){
                debug("left subtree greater than root: " << root->val << " min: " << left_min << " max: " << left_max);
                return false;
            }

            debug("left subtree valid: root:" << root->val << " min: " << left_min << " max: " << left_max);
            *min = left_min;
        }else {
            *min = root->val;
        }
        if (root->right){
            int right_min=INT_MAX, right_max=INT_MAX;
            if (!_validate_subtree(root->right, &right_min, &right_max)) {
                debug("right subtree invalid");
                return false;
            }
            if (right_min > right_max) {
                debug("right subtree range is invalid: min: " << right_min <<" max: " << right_max);
                return false;
            }
            if (root->val >= right_min) {
                debug("right subtree greater than root: " << root->val << "min: " << right_min << " max: " << right_max);
                return false;
            }
            *max = right_max;
        } else {
            *max = root->val;
        }
        if (*min > *max) {
            debug("Invalid subtree, min(" << *min << " ) !< max( "<< *max << ")");
            return false;
        }
        debug("valid subtree: " << root->val << " min: " << *min << " max: " << *max);
        return true;
            
    }
    
    bool isValidBST(TreeNode* root) {
        int left_min=0, right_max=0;
        return _validate_subtree(root, &left_min, &right_max);
    }
};

#include <queue>

class LevelOrderTree {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if (!root) return v;
        q.push(root);
        q.push(NULL);
        vector<int> vv;
        while(!q.empty()){
            debug("queue size: " << q.size());
            TreeNode *n = q.front(); q.pop();
            debug("queue size: " << q.size());
            if (n == NULL) {
                debug("end of level");
                if (vv.empty()) break;
                v.push_back(vv);
                vv.clear();
                q.push(NULL);
                continue;
            }
            vv.push_back(n->val);
            debug("value append: " << n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
    }
};

#include <algorithm>

int main(){
    TreeNode root(2);
    root.left = new TreeNode(1);
    root.right = new TreeNode(3);
    Solution s;
    cout << (s.isValidBST(&root) ? "true" : "false") << endl;
    // delete

    LevelOrderTree l;
    auto v = l.levelOrder(&root);
    cout << "[";
    for_each(v.begin(), v.end(), [](vector<int>&v) {
        cout << "[";
        for_each(v.begin(), v.end(), [] (int& i){
            cout << i << ", ";
        });
        cout << "]" << endl;
    });
    cout << "]" << endl;
}