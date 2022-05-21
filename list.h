#ifndef _LIST_H_
#define _LIST_H_
#include <ostream>

struct Node {
    int value;
    Node* next;
    Node(int data, Node* nextNode);
    Node(int data);
    Node();
};

class list {
public:
    list();
    ~list();
    Node* pop();
    void printList();
    void push(int data);
    void pushBack(int data);
    Node* popBack();
    Node* search(int k);
    list& operator=(const list& right);
    int getSize();
    Node* getHead();
    bool isEmpty();
    void setHead(Node* newHead);
    list(const list& s);
//    friend ostream &operator<<(ostream &output, const list &s);

private:
    int size;
    Node* head;
};
/*
ostream &operator<<(ostream &output, const list &s) {
        if(s.size == 0)
	    {
	        output << "List is empty" << "\n";
            return;
	    }
	    Node* node = s.head;
        output << node->value << " ";
	    node = node->next;
        while(node != nullptr)
	    {
	        output << node->value << " ";
		    node = node->next;
	    }
	    output << "\n";
}
*/
#endif