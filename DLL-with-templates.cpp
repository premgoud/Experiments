#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "template_DLL.hpp"

// Constructors & Destructors
template<class T>
DLL<T>::DLL(const T &val) {
  Node *newNode = new Node(val);
  head = newNode;
  tail = head;
}

template<class T>
DLL<T>::~DLL() {
  //std::cout << "Deleting, deallocating memory." << std::endl;
  Node *n = head;
  while (n != NULL) {
    head = n->next;
    delete n;
    n = head;
  }
}

// Public Functions
template<class T>
void DLL<T>::insertToHead(T val) {
  Node *n = new Node(val);
  n->next = head;
  if (head != NULL) {
    head->prev = n;
  }
  head = n;
  if (tail == NULL) {
    tail = head;
  }
}

template<class T>
void DLL<T>::insertAtPosition(int pos, T val) {
  if (val < 0) {
    std::cout << "Input positive pos!" << std::endl;
    return;
  }
  
  if (pos == 0) {
    insertToHead(val);
    return;
  }

  Node *n = new Node(val);
  Node *curr = head;
  Node *prevNode = NULL;
  Node *nextNode = NULL;

  while (pos > 0) {
    if (curr == NULL) {
      std::cout << "Out of bounds." << std::endl;
      return;
    }
    prevNode = curr;
    curr = curr->next;
    if (curr == NULL) {
      nextNode = NULL;
    } else {
      nextNode = curr->next;
    }
    pos--;
  }

  n->prev = prevNode;
  prevNode->next = n;

  n->next = nextNode;
  if (nextNode != NULL) {
    nextNode->prev = n;
  }
}

template<class T>
void DLL<T>::insertToTail(T val) {
  Node *n = new Node(val);
  n->prev = tail;
  if (tail != NULL) {
    tail->next = n;
  }
  tail = n;
  if (head == NULL) {
    head = tail;
  }
}

template<class T>
int DLL<T>::length() {
  if (head == NULL) {
    return 0;
  }
  
  int length = 0;
  while (head != NULL) {
    head = head->next;
    length++;
  }
  return length;
}

template<class T>
void DLL<T>::reverse() {
  if (head == NULL || head->next == NULL) {
    return;
  }

  Node *n;
  tail = head;
  while (head->next != NULL) {
    n = head->next;

    head->next = head->prev;
    if (head->prev != NULL) {
      std::cout << "Here" << std::endl;
      head->prev = n;
    }
    
    if (n->next != NULL) {
      std::cout << "THere" << std::endl;
      n->prev = n->next;
    }
    n->next = head;
  }
  head = n;
}

template<class T>
void DLL<T>::print() {
  Node *n = head;
  int pos = 1;
  while(n != NULL) {
    std::cout << "Value at " << pos << " is: " << n->value << std::endl;
    n = n->next;
    pos++;
  }
  std::cout << std::endl;
}

main() {
  // 2 ways of calling the constructors for DLL.
  DLL<int> dll1;
  DLL<int> dll2(3);

  dll1.insertAtPosition(0, 10);
  dll1.insertAtPosition(1, 11);
  dll1.print();

  dll1.reverse();
  dll1.print();

  // dll1.insertAtPosition(3, 12);
  // dll1.print();

  // dll1.insertToHead(1);
  // dll1.print();
  // dll1.insertToTail(2);
  // dll1.insertToTail(3);
  // dll1.print();

  // Testing for length
  // std::cout << "The length of the list is: " << dll1.length() << std::endl;

  return 0;
}