//
// Created by Gianmarco Rossi on 02/04/23.
//



class List {
public:
    class Node {
    public:
        double value;
        Node *next;
        Node() : value(0), next(nullptr) { }
        Node(const double value, Node* next) : value(value), next(next) { }
        Node(const double value) : value(value), next(nullptr) { }
        Node(Node *p_node) : value(p_node->value), next(p_node->next) { }
        Node &operator = (const Node& other);
        bool operator == (const Node& other) const;
        bool operator == (const Node* other) const;
        List::Node &operator ++ ();
        List::Node operator ++ (int);
        ~Node();
    };
    class iterator {
    public:
        List::Node *p_it;
        iterator() : p_it(nullptr) { }
        iterator(List::Node *p_it) : p_it(p_it) { }
        bool operator == (const List::iterator &other) const;
        bool operator != (const List::iterator &other) const;
        List::iterator &operator ++ () const;
        List::iterator operator ++ (int)

    };

    List() : head(nullptr) { }
    List(Node &head): head(&head) { }

    void push(double value);
    void push(const Node& node);

    void append(double value);
    void append(const Node& other);
    void append(const List& other);

    Node *pop();

    void show() const;

    List::iterator begin();
    List::iterator end();
    ~List();

private:
    Node *head;
//    Node *tail;
};