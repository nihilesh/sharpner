
/*
  Breadth first walk thro
  1. Graph - node {value, children[]}
  2. Queue - linked-list [ FIFO ]
  3. enqueue(q, root)
  4. while !q.isEmpty() {
         Node *n = dequeue(q);
         Node *child = n->children;
         while child {
            queue.enqueue(child);
         }
         fn(n);
     }
*/
