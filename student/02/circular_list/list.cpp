#include "list.hh"
#include <iostream>
#include <memory>

using namespace std;

// Constructor
List::List() : first_(nullptr), last_(nullptr) {}

// Inserts the given element at the beginning of the list.
List::~List() {
    if (first_) {
        last_->next = nullptr;
        while (first_) {
            first_ = first_->next;
        }
    }
}

// Inserts the given element at the beginning of the list.
void List::insert_at_the_beginning(int i){
    shared_ptr<List_item> new_item = make_shared<List_item>();
    new_item->data = i;
    if (!first_){
        first_ = new_item;
        last_ = new_item;
        last_->next = first_;
    }
    else{
        new_item->next = first_;
        first_ = new_item;
        last_->next = first_;
    }
}

// Inserts the given element at the end of the list.
void List::insert_at_the_end(int i){
    shared_ptr<List_item> new_item = make_shared<List_item>();
    new_item->data = i;
    if (!first_) {
        first_ = new_item;
        last_ = new_item;
        last_->next = first_;
    }
    else{
        last_->next = new_item;
        last_ = new_item;
        last_->next = first_;
    }
}

// Removes the first element of the list.
// If the list is empty, does nothing.
void List::remove_first(){
    if (!first_) return;
    if (first_ == last_){
        first_ = nullptr;
        last_ = nullptr;
        return;
    }
    first_ = first_->next;
    last_->next = first_;
}

// Removes the last element of the list.
// If the list is empty, does nothing.
void List::remove_last(){
    if (!first_) return;
    if (first_ == last_){
        first_ = nullptr;
        last_ = nullptr;
        return;
    }
    shared_ptr<List_item> temp = first_;
    while (temp->next != last_){
        temp = temp->next;
    }
    temp->next = first_;
    last_ = temp;
}

// Prints the text "List elements:" and after that prints the elements
// of the list, all in the same line, separated by an empty space.
// If there are no elements in the list, prints the text "No elements".
void List::print(){
    if (!first_){
        cout << "No elements" << endl;
        return;
    }
    cout << "List elements: ";
    shared_ptr<List_item> temp = first_;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first_);
    cout << endl;

}
