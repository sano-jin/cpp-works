class Node {
  int key;
  int data;
  Node *prev = nullptr;
  Node *next;
  Node(int k, int d) : key(k), data(d) {}
}

// insert link at the last location
void insertLast(Node **head_ref, Node **last_ref, int key, int data) {
  // create a new node
  Node *node = new Node(key, data);

  if (*head_ref == nullptr) {
    // make it the last node
    *head_ref = node;
  } else {
    // make node as a new last node
    *last_ref->next = node;

    // mark old last node as prev of new node
    node->prev = *last_ref;
  }

  // point last to new last node
  *last_ref = node;
}
