//
// Created by Gianmarco Rossi on 05/04/23.
//
#include <iostream>
#include "dlist.h"
// List::Node overload
List::Node &List::Node::operator = (const Node& other) {
    if (this == &other) {
        return *this;
    } else {
        this->value = other.value;
        this->next = other.next;
        this->prev = other.prev;
        return *this;
    }
}
bool List::Node::operator == (const Node& other) const {
     if (this->value == other.value &&
         this->next == other.next &&
         this->prev == other.prev) {
         return true;
     } else  {
         return false;
     }
}
bool List::Node::operator != (const Node& other) const {
    if (this->value != other.value ||
        this->next != other.next ||
        this->prev != other.prev) {
        return true;
    } else {
        return false;
    }
}

// List::iterator overload
List::iterator &List::iterator::operator ++ () {
    this->it = this->it->next;
    return *this;
}
const List::iterator List::iterator::operator ++ (int) {
    const auto temp = this;
    ++*this;
    return *temp;
}
bool List::iterator::operator == (const iterator& other) const {
    if (this->it == other.it) {
        return true;
    } else {
        return false;
    }
}
bool List::iterator::operator != (const List::iterator &other) const {
    if (this->it != other.it) {
        return true;
    } else {
        return false;
    };
}
List::iterator &List::iterator::operator * () {
    return *this;
}
List::Node *List::iterator::operator -> () const {
    return this->it;
}

List::Node &List::iterator::node() {
    return *(this->it);
}

// List Constructor
List::List(double value) {
    this->head = new Node(value);
    this->tail = head;
}

// List methods iterator
List::iterator List::begin() {
    return {this->head};
}

List::iterator List::end() {
    if (this->tail != nullptr) {
        return {this->tail->next};
    } else {
        auto it = this->begin();
        for (it; it->next != nullptr; it++) { }
        this->tail = &it.node();
        return it->next;
    }
}
// List methods
void List::push(double value) {
    auto temp = new Node(value);
    temp->next = this->head;
    this->head = temp;
}
void List::append(double value) {
    auto temp = new Node(value);
    if (this->tail == nullptr && this->head == nullptr) {
        this->head = this->tail = temp;
    } else {
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }
}
double List::pop() {
    if (this->tail != nullptr) {
        double temp = this->tail->value;
        List::Node *new_tail = this->tail->prev;
        new_tail->next = nullptr;
        delete this->tail;
        this->tail = new_tail;
        return temp;
    } else {
        auto end = this->end();
        return end->value;
    }
}

void List::show() {
    auto it = this->begin();
    for (it; it != this->end(); ++it) {
        std::cout << it->value << " -> ";
    }
    std::cout << std::endl;
}
