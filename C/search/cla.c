#include <stdlib.h>
#include <stdio.h>

typedef struct Node_Def {
    int val;
    struct Node_Def *left;
    struct Node_Def *right;
} Node;

Node *
new_node(int val) {
    Node *n = malloc(sizeof(Node));
    n->left = n->right = NULL;
    n->val = val;
    return n;
}

Node *
 lca(Node *root, int n1, int n2) {
    if (!root) return NULL;
    if (root->val == n1 || root->val == n2) return root;
    Node *l = lca(root->left, n1, n2);
    Node *r = lca(root->left, n1, n2);
    if (l && r) return root;
    return l ? l: r;
}

int main(){
    return 0;
}
