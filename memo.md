```
void append(Node *&head_ref, Node *&last_ref, int new_data) {
  /* 1. allocate node */
  Node *new_node = new Node(new_data);
  new_node->next = nullptr;

  /* 2. If the Linked List is empty, then make the new
   *    node as head */
  if (head_ref == nullptr) {
    new_node->prev = nullptr;
    head_ref = new_node;
    last_ref = new_node;
    return;
  }

  /* 3. Change the next of last node */
  last_ref->next = new_node;

  /* 4. Make last node as previous of new node */
  new_node->prev = last_ref;

  /* 5. Set the pointer to the last node */
  last_ref = new_node;

  return;
}
```
