//
// Created by Gianmarco Rossi on 05/04/23.
//

#ifndef DLIST_DLIST_H
#define DLIST_DLIST_H


class List {
private:
    class Node {
    public:
        double value;
        Node *next;
        Node *prev;

        Node() : value(0), next(nullptr), prev(nullptr) { }
        Node(double value) : value(value), next(nullptr), prev(nullptr){ }

        Node &operator = (const Node& other);
        bool operator == (const Node& other) const;
        bool operator != (const Node& other) const;

        ~Node() = default;
    };

    Node *head;
    Node *tail;

public:
    class iterator {
    private:
        List::Node *it;
    public:
        iterator() : it(nullptr) { }
        iterator(Node *node) : it(node) { }

        iterator &operator ++ ();
        const iterator operator ++ (int);
        bool operator == (const iterator& other) const;
        bool operator != (const iterator& other) const;
        iterator &operator * ();
        Node *operator -> () const;


        ~iterator() = default;

        Node &node();

        friend class List::Node;
    };

    List() : head(nullptr), tail(nullptr) { }
    List(double value);

    void push(double value);
    void append(double value);
    double pop();

    void show();

    iterator begin();
    iterator end();
};

#endif //DLIST_DLIST_H
