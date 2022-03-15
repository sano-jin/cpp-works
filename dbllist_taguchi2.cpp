// A complete working C++ program to
// demonstrate all insertion methods
#include <iostream>

using namespace std;

// A linked list node
class Node {
public:
  int data;
  Node *next;
  Node *prev;
  Node(int d) : data(d) {}
};

/* Given a reference (pointer to pointer)
to the head of a list
and an int, inserts a new node on the
front of the list. */
void push(Node *&head_ref, Node *&last_ref, int new_data) {
  /* 1. allocate node */
  Node *new_node = new Node(new_data);

  /* 3. Make next of new node as head
  and previous as nullptr */
  new_node->next = head_ref;
  new_node->prev = nullptr;

  /* 4. change prev of head node to new node */
  if (head_ref != nullptr) {
    head_ref->prev = new_node;
  } else {
    /* 4. change last node to new node */
    last_ref = new_node;
  }

  /* 5. move the head to point to the new node */
  head_ref = new_node;
  cout << head_ref->data << endl;
}

/* Given a node as prev_node, insert
a new node after the given node */
void insertAfter(Node *&prev_node, int new_data) {
  /*1. check if the given prev_node is nullptr */
  if (prev_node == nullptr) {
    cout << "the given previous node cannot be nullptr\n";
    return;
  }

  /* 2. allocate new node */
  Node *new_node = new Node(new_data);

  /* 4. Make next of new node as next of prev_node */
  new_node->next = prev_node->next;

  /* 5. Make the next of prev_node as new_node */
  prev_node->next = new_node;

  /* 6. Make prev_node as previous of new_node */
  new_node->prev = prev_node;

  /* 7. Change previous of new_node's next node */
  if (new_node->next != nullptr) {
    new_node->next->prev = new_node;
  } else {
    // prev_node is last_ref when new_node->next is nullptr
    prev_node = new_node;
  }
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(Node *&head_ref, Node *&last_ref, int new_data) {
  /* 1. allocate node */
  Node *new_node = new Node(new_data);

  /* 2. This new node is going to be the last node, so
      make next of it as nullptr*/
  new_node->next = nullptr;

  /* 3. If the Linked List is empty, then make the new
      node as head */
  if (head_ref == nullptr) {
    new_node->prev = nullptr;
    head_ref = new_node;
    last_ref = new_node;
    return;
  }

  /* 4. Change the next of last node */
  last_ref->next = new_node;

  /* 5. Make last node as previous of new node */
  new_node->prev = last_ref;

  last_ref = new_node;

  return;
}

// This function prints contents of
// linked list starting from the given node
void printList(Node *node) {
  Node *last;
  cout << "\nTraversal in forward direction \n";
  while (node != nullptr) {
    cout << " " << node->data << " ";
    last = node;
    node = node->next;
  }

  cout << "\nTraversal in reverse direction \n";
  while (last != nullptr) {
    cout << " " << last->data << " ";
    last = last->prev;
  }
  cout << endl;
}

/* Driver program to test above functions*/
int main() {
  /* Start with the empty list */
  Node *head = nullptr;

  /* end with the empty list */
  Node *last = nullptr;

  push(head, last, 9);

  // Insert 6. So linked list becomes 6->nullptr
  append(head, last, 6);

  // Insert 7 at the beginning. So
  // linked list becomes 7->6->nullptr
  push(head, last, 7);
  cout << "Created DLL is: ";
  printList(head);

  // Insert 1 at the beginning. So
  // linked list becomes 1->7->6->nullptr
  push(head, last, 1);
  cout << "Created DLL is: ";
  printList(head);

  // Insert 4 at the end. So linked
  // list becomes 1->7->6->4->nullptr
  append(head, last, 4);
  cout << "Created DLL is: ";
  printList(head);

  // Insert 8, after 7. So linked
  // list becomes 1->7->8->6->4->nullptr
  insertAfter(head->next, 8);

  cout << "Created DLL is: ";
  printList(head);

  return 0;
}

// This is code is contributed by rathbhupendra
