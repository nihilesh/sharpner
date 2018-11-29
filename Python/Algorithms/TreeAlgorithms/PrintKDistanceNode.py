'''
Refer: http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/

Consider the tree shown in diagram
               20
        8               22
4               12
            10      14

Input: target = pointer to node with data 8.
       root = pointer to node with data 20.
       k = 2.
Output : 10 14 22

If target is 14 and k is 3, then output
should be "4 20"

Solution:
    Use counter parameter.
    a. Search the matching node with in-order search.
    b. assign counter 0 at the matched stack.
    c. increment counter for subtree walk.
    c. when matched k, print and return.
    d. For parent tree, return 0, increment counter per pop
        increment counter per downstream walk.
'''

tree = []