#ifndef STACK_H
#define STACK_H

#include "linked_list.h"
#include <iostream>

class Stack {

  friend class LinkedList;

  public:
  void push(std::string val) {
    input->insert_back(val);
  }
  std::string pop() {
    return input->remove_front();
  }
  bool isEmpty() {
    if (!input->head) {
      return true;
    }
    return false;
  }

 private:
  LinkedList* input = new LinkedList();
};

#endif

