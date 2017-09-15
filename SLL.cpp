#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class SLL {

private: 
  /*
   * Node Declaration
   */
  struct node {
    int value;
    struct node * next;
  };
  node * head;

public:
  // Constructor
  SLL() {
    head = NULL;
  }
  SLL(int value) {
    head->value = value;
    head->next = NULL;
  }
  // Alternative definition for constructor
  //SLL(): head(NULL) {};

  node * create_node(int value) {
    struct node *temp;
    temp = new(struct node);
    if (temp == NULL) {
      cout<<"Memory not allocated "<<endl;
      return 0;
    } else {
      temp->value = value;
      temp->next = NULL;
      return temp;
    }
  }

  void insert_begin(int value) {
    node * temp = create_node(value);
    temp->next = head;
    head = temp;
  }

  void remove_duplicates() {
    node *n0, *n1;
    n0 = head;
    int value;
    while (n0->next != NULL) {
      n1 = n0->next;
      if (n0->value == n1->value) {
        n0->next = n1->next;
      }
      n0 = n1;
    }
  }

  void print_all() {
    node * n = head;
    while (n != NULL) {
      cout << n->value << endl;
      n = n->next;
    }
  }
};

main() {
  SLL sll;
  sll.insert_begin(1);
  sll.insert_begin(1);
  sll.insert_begin(2);
  sll.insert_begin(2);
  sll.insert_begin(4);
  sll.print_all();
  cout << endl;
  sll.remove_duplicates();
  sll.print_all();

  return 0;
}