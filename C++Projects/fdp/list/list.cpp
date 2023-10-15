//
// Created by Gianmarco Rossi on 03/04/23.
//

#include <iostream>
#include "list.h"

// List::Node operator overload
List::Node &List::Node::operator=(const List::Node& other) {
    if (this == &other) {
        return *this;
    } else {
        this->value = other.value;
        this->next = other.next;
        return *this;
    }
}
bool List::Node::operator == (const List::Node& other) const {
    if (this->value == other.value && this->next == other.next) {
        return true;
    } else {
        return false;
    }
}
bool List::Node::operator == (const List::Node* other) const {
    if (this->value == other->value && this->next == other->next) {
        return true;
    } else {
        return false;
    }
}
List::Node &List::Node::operator ++ () {
    return (Node &) this->next;
}
List::Node List::Node::operator ++ (int) {
    Node temp = *this;
    ++(*this);
    return temp;
}

// List method
void List::push(const double value) {
    if (this->head == nullptr) {
        this->head = new Node(value);
    } else {
        auto *h_node = new Node(value);
        h_node->next = this->head;
        this->head = h_node;
    }
}
void List::push(const Node& other) {
    if (this->head == nullptr) {
        this->head = new Node(other.value);
    } else {
        this->head = new Node(other.value, this->head);
    }
}
void List::append(const double value) {
    if (this->head == nullptr) {
        this->head = new Node(value);
    } else {
        Node *node = this->head;
        Node *prev = nullptr;
        while (node != nullptr) {
            prev = node;
            node = node->next;
        }
        node = new Node(value);
        if (prev != nullptr) {
            prev->next = node;
        }
    }
}
void List::append(const Node& other) {
    Node *node = this->head;
    Node *prev = nullptr;
    while (node != nullptr) {
        prev = node;
        node = node->next;
    }
    node = new Node(other.value);
    prev->next = node;
}
void List::append(const List& other) {
    Node *node = this->head;
    Node *node_other = other.head;
    if (node == nullptr) {
        node = new Node(node_other->value);
    }
    while (node->next != nullptr) {
        node = node->next;
    }
    while (node_other != nullptr) {
        node->next = new Node(node_other->value);
        node_other = node_other->next;
        node = node->next;
    }
}
List::Node *List::pop() {
    if (this->head == nullptr) {
        return {};
    } else {
        Node *node = this->head;
        Node *prev = nullptr;
        while (node->next != nullptr) {
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        return node;
    }
}
void List::show() const {
    Node *node = this->head;
    while (node != nullptr) {
        if (node->next == nullptr) {
            std::cout << node->value;
        } else {
            std::cout << node->value << " -> ";
        }
        node = node->next;
    }
    std::cout << std::endl;
}
List::~List() {
    for (Node *node = this->head; node != nullptr;) {
        Node *prev = node;
        node = node->next;
        delete prev;
    }
}
// List iterator methods
List::iterator List::begin() {
    return {this->head};
}
List::iterator List::end() {
    return {this->head};
}

// List::iterator operator overload
bool List::iterator::operator == (const List::iterator &other) const {
    if (this->p_it == other.p_it) {
        return true;
    } else {
        return false;
    }
}
bool List::iterator::operator != (const List::iterator &other) const {
    return this->p_it != other.p_it;
}
List::iterator &List::iterator::operator ++() const {
    return (iterator &) this->p_it->next;
}
List::iterator List::iterator::operator ++(int) {
    iterator temp = *this;
    ++*this;
    return temp;
}
