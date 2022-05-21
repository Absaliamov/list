#include "list.h"
#include <iostream>
using namespace std;

Node::Node(int data, Node* nextNode)
{
    this->value = data;
    this->next = nextNode;
}
Node::Node(int data)
{
    this->value = data;
	this->next = nullptr;
}
Node::Node()
{
	this->next = nullptr;
}

list::list()
{
    size = 0;
	head = nullptr;
}

list::~list()
{
	if(size == 0)
	{
		return;
	}
	Node* tail = new Node(0);
	while(head)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
	delete tail;
}

void list::pushBack(int data)
{
	if(size == 0)
	{
		head = new Node(data);
		size = 1;
		return;
	}
	Node* tail = head;
	while(tail->next != nullptr)
	{
		tail = tail->next;
	}
	tail->next = new Node(data);
	size += 1;
}

void list::printList()
{
	if(size == 0)
	{
		cout << "List is empty" << "\n";
		return;
	}
	Node* node = head;
	cout << node->value << " ";
	node = node->next;
	while(node != nullptr)
	{
		cout << node->value << " ";
		node = node->next;
	}
	cout << "\n";
}

Node* list::pop()
{
	if(size == 0)
	{
		cout << "List is empty\n";
		return nullptr;
	}
	Node* ans = head;
	head = head->next;
	size -= 1;
	return ans;
}

Node* list::popBack()
{
	if(size == 0)
	{
		cout << "List is empty\n";
		return nullptr;
	}
	Node* tail = head;
	while(tail->next != nullptr)
	{
		tail = tail->next;
	}
	size -= 1;
	return tail;
}

bool list::isEmpty()
{
	if(size == 0)
		return 1;
	return 0;
}

Node* list::search(int k)
{
	if(size == 0)
	{
		cout << "List is empty\n";
		return nullptr;
	}
	Node* tail = head;
	if(size < k)
	{
		cout << "Element with number " << k << " doesn't exist\n";
		return nullptr;
	}
	while(k != 1)
	{
		tail = tail->next;
		--k;
	}
	return tail;
}

void list::push(int data)
{
	if(size == 0)
	{
		head = new Node(data);
		size += 1;
		return;
	}
	Node* tail = new Node(data, head);
	setHead(tail);
	size += 1;
}

list& list::operator=(const list& right)
{
	if(size == 0)
	{
		this->size = right.size;
		this->head = right.head;
		return *this;
	}
	if((this->size == right.size) && (this->head == right.head))
	{
		return *this;
	}
	this->size = right.size;
	this->head = right.head;
	return *this;
}

void list::setHead(Node* newHead)
{
	head = newHead;
}

list::list(const list& s)
{
	this->size = s.size;
	this->head = new Node(s.head->value, s.head->next);
}

int main()
{
	list l1 = list();
	l1.push(2);
	l1.push(3);
	list l2(l1);
	l1.printList();
	l1.~list();
	l2.~list();
	return 0;
}