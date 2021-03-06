#include "pch.h"
#include <iostream>
#define MAXLENTH 100
using namespace std;

class SeqList
{
public:
	int data[MAXLENTH];
	int lenth;
	SeqList()
	{
		this->lenth = 0;
	}
};

//增删改查
void add(SeqList*,int);//添加新元素到最后
void del(SeqList*,int);//通过id删除元素
void cha(SeqList*,int,int);//通过id修改元素
int find(SeqList*, int);//通过内容查找元素，并将查找到的id内容返回，如果为0则没找到

int main()
{
	SeqList *seqlist = new SeqList;
	add(seqlist,1);
	add(seqlist, 5);
	add(seqlist, 2);
	del(seqlist,2);
	add(seqlist, 6);
	cha(seqlist, 2, 5);
	int a = find(seqlist,6);
	delete seqlist;
	return 0;
}

void add(SeqList* seqlist, int data)
{
	if (seqlist->lenth >= 100)
	{
		cout << "顺序表已满，添加数据失败";
		return;
	}
	seqlist->data[seqlist->lenth] = data;
	seqlist->lenth++;
}

void del(SeqList* seqlist, int id)
{
	if (seqlist->lenth <= 0)
	{
		cout << "顺序表为空，删除失败";
		return;
	}
	id--;
	while (id < seqlist->lenth)
	{
		seqlist->data[id] = seqlist->data[id+1];
		id++;
	}
		
	seqlist->lenth--;
}
void cha(SeqList* sl, int id, int data)
{
	sl->data[id - 1] = data;
}
int find(SeqList* sl, int data)
{
	for (int i = 0; i < sl->lenth; i++)
	{
		if (sl->data[i] == data) return i + 1;
	}
	return 0;
}