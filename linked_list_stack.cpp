/**                                                                                                                                                                          
Name: Samantha Cortes                                                                                                                                                        
pengo ID: scortes                                                                                                                                                            
Email: samantha2002c@gmail.com                                                                                                                                               
File Name: linked_list.h                                                                                                                                                     
Assignment #1: Review; Linked List                                                                                                                                           
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

class LinkedList {

  friend class Stack;
  public:

  /** Default constructor.                                                                                                                                                   
  Constructs an empty list */
  LinkedList() {}

  /** Destroys each of the contained elements,                                                                                                                               
  and deallocates all memory allocated by                                                                                                                                    
  this list. */
  ~LinkedList() {
    LinkNode* temp = head;

    while(head) {
      temp = head;
      head = temp->next;
      delete temp; temp = 0;
    }
    this->tail = nullptr;
  }

  //  Prepends a copy of `val` to this list.                                                                                                                                 
  void insert_front(std::string val) {
    LinkNode* new_node = new LinkNode();
    new_node->data = val;

    if (this->size == 0) {
      this->head = this->tail = new_node;
    }
    else {
      new_node->next = this->head;
      this->head->prev = new_node;
      this->head = new_node;
    }
    this->size += 1;
  }

  // Appends a copy of `val` to this list.                                                                                                                                           
  void insert_back(std::string val) {
    LinkNode* new_node = new LinkNode();
    new_node-> data = val;

    if (this->size == 0) {
      this->head = this->tail = new_node;
    }
    else {
      this->tail->next = new_node;
      new_node->prev = this->tail;
      this->tail = new_node;
    }
    this->size +=1;
  }

  // Deletes first value in list.                                                                                                                                                    
  std::string remove_front() {
    std::string return_val = this->head->data;
    if (this->size == 1) {
      LinkNode* to_delete = this->head;
      this->head = nullptr;
      this->tail = nullptr;
      this->size = 0;
      delete to_delete;
    }
    else {
      LinkNode* temp = this->head;
      this->head = this->head->next;
      this->head->prev = nullptr;
      delete temp;
      this->size -= 1;
    }
    return return_val;
  }
  // Deletes the last value in list.                                                                                                                                                 
  std::string remove_back() {
    std::string return_string = this->tail->data;
    if (this->size == 1) {
      LinkNode* to_delete = this->head;
      this->head = nullptr;
      this->tail = nullptr;
      this->size = 0;
      delete to_delete;
    } else {
      LinkNode* temp = this->tail;
      this->tail = this->tail->prev;
      this->tail->next = nullptr;
      delete temp;
      this->size -= 1;
    }
    return return_string;
  }

  void print() const {
    LinkNode* word;

    word = head;
    while(word != nullptr) {
      std::cout << word->data << std::endl;
      word = word->next;
    }
  }

 private:
  class LinkNode {
    friend class LinkedList;
    friend class Stack;

  public:
    std::string data;
    LinkNode* next = nullptr;
    LinkNode* prev = nullptr;
  };
  int size = 0;
  LinkNode* head = nullptr;
  LinkNode* tail = nullptr;
};
#endif
