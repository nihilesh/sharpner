#include<cstdlib>
#include<iostream>

typedef struct Node_ {
	void* data;
    struct Node_ *left;
    struct Node_ *right;
} Node;

Node* 
new_node(const void *value) {
	Node n = malloc(sizeof(Node);
	n->data = value;
    n->left = NULL;
    n->right = NULL;
	return n;	
}

void
append(Node *root, int value) {
	assert(root);
	if (root->data >= value) {
		if !(root->left){
			root->left = new_node(value);
			return;
		} 
		append(root->left, value);
	} 
	if (root->data < value) {
		if !(root->right){
			root->right = new_node(value);
			return;
		} 
		append(root->right, value);
	}
	return;
}

Node *
create_tree(int* array, int len){
	assert(array && array+len-1 && "invalid parameter/s");
	Node *root = new_node(array);
	for (int i=1; i < len; i++) {
		append(root, array[i]);
	}
}

void
print_bf(Node* tree){
	queue;
    queue.push(tree);
	while(!queue.isEmpty()) {
		n = queue.pop()
		print(n);
		queue.push(n->left);
		queue.push(n->right);
	}	
}

void
print_df(Node* tree){
    stack;
    stack.push(tree);
    while(!stack.isEmpty()) {
        n = stack.pop()
        print(n);
        stack.push(n->right);
        stack.push(n->left);
    }
}


int main() {
	Node *tree = create_tree([1, 20, 4, 5, 19, 30, 40], 7);
    print_bf(tree);	
    return 0;
}

