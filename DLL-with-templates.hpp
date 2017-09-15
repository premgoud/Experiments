#pragma once

template<class T>
class DLL {

// Private
private:

  // Node Struct
  struct Node {
    // Properties
    T value;
    Node *next;
    Node *prev;

    // Constuctors
    Node (const T &inVal): value(inVal), next(), prev() {}
    Node (const Node &inNode): value(inNode->value), next(inNode->next), prev(inNode->next) {}
  };

  // Properties
  Node *head;
  Node *tail;

// Public
public:

  // Constructors
  DLL(): head(NULL), tail(NULL) {};
  DLL(const T &val); 
  DLL(const DLL<T> &inDLL); 
  ~DLL();

  // Public Functions
  void insertToHead(T val);
  void insertAtPosition(int pos, T val);
  void insertToTail(T val);
  //void updateAtPosition(int pos, T val);
  //void deleteAtPosition(int pos);
  //void deleteValue(int pos);
  int length();
  //int search(T val);
  void reverse();
  //void merge_sort();
  void print();
};