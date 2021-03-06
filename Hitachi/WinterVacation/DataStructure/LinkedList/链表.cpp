#include "pch.h"
#include <iostream>
using namespace std;

class Link
{
public:
	class Node
	{
	public:
		int data;
		Node *next;
	};
	Node *head = new Node;
	Node *now = head;
	void linkOut()
	{
		out(head);
	}
	Link()
	{
		head->next = NULL;
	}
	void join(Link *p)
	{
		Node *t = head;
		while (t->next) t = t->next;
		t->next = p->head->next;
	}
	//增(头插法)
	void add(int n)
	{
		Node *newNode = new Node;
		newNode->data = n;
		newNode->next = head->next;
		head->next = newNode;
	}
	//删
	void del(int id)
	{
		Node *t = head;
		for (int i = 0; i < id-1; i++)
		{
			t = t->next;
		}
		Node *p = t->next;
		t->next = p->next;
		delete p;
	}
	//改
	void cha(int id, int data)
	{
		Node *t = head;
		for (int i = 0; i < id; i++)
		{
			t = t->next;
		}
		t->data = data;
	}
	//查
	int find(int data)
	{
		Node *p = head;
		for(int i = 0; p->next; i++)
		{
			p = p->next;
			if (p->data == data)return i+1;
		}
		return 0;
	}
	//输出
	void out(Node *p)
	{
		p = p->next;
		if (p)
		{
			cout << p->data << ' ';
			out(p);
		}
	}
};

int main()
{
	Link *link1 = new Link;
	Link *link2 = new Link;
	link1->add(1);
	link1->add(11);
	link2->add(2);
	link2->add(22);
	link1->join(link2);
	link1->del(1);
	link1->add(3);
	link1->cha(2,4);
	if (link1->find(5))
	{
		cout << '#' << link1->find(5) << '#';
	}
	else
	{
		cout << "没找到";
	}
	link1->linkOut();
	delete link1;
	delete link2;
}

