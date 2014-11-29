template <class T> class Stack {

    struct Item {
        T val;
        Item* next;
        Item(T v) : val(v), next(0) {}
        Item(T v, Item* n) : val(v), next(n) {}
    };

    Item* head;

    Stack(const Stack& s) {}
    Stack& operator=(const Stack& s) {}

public:
    Stack() : head(0) {}
    ~Stack();
    T pop();
    void push(T val);
    void append(T val);
};
