#include <iostream>
using namespace std;

#define debug(m) cout << m << endl

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode *head){
        ListNode *rn = NULL , *n = head;
        while(n){
            if (!rn){
                rn = new ListNode(n->val);
            }else{
                ListNode *m = new ListNode(n->val);
                m->next = rn;
                rn = m;
            }
            n = n->next;
        }
        return rn;
    }
    
    void operate(ListNode *head, void (*op)(void*)){
        while(head){
            ListNode *tmp = head->next;
            op((ListNode*)head);
            head = tmp;
        }
    }

    void free_list(ListNode *head){
        operate(head, free);
    }

    void print_list(ListNode *head){
        operate(head, [](void* n){
            cout << ((ListNode*)n)->val;
        });
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode *rhead = reverseList(head);
        ListNode *n = head;
        ListNode *rn = rhead;
        cout << "orig list: "; print_list(head); cout << endl;
        cout << "reverse list: "; print_list(rhead); cout << endl;
        while(n){
            if (n->val != rn->val){
                debug("mismatch: " << n->val << " != " << rn->val);
                break;
            }
            n = n->next;
            rn = rn->next;
        }
        free_list(rhead);
        debug("n: " << n << " rn: " << rn);
        return n ? false: true;
    }
};

int main(){
    ListNode *root = new ListNode(0);
    root->next = new ListNode(0);
    Solution s;
    cout << (s.isPalindrome(root) ? "true": "false") << endl;
}