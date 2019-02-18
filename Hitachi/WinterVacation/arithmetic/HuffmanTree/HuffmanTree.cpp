#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include "HuffmanTree.h"
using namespace std;

HuffmanTree::HuffmanTree(string str)
{
	data = str;
	for (int i = 0; i < alp.size(); i++)
	{
		alp[i] = { '@',0,NULL,NULL};
	}
}

//计算概率
void HuffmanTree::probability()
{
	for (string::iterator it = data.begin(); it != data.end(); it++)
	{
		alphabet[*it] = count(data.begin(), data.end(), *it) * 1000 / data.length();
	}
}

//创建HuffmanTree
void HuffmanTree::CreateHuffmam()
{
	probability();
	for (map<char, int>::iterator it = alphabet.begin(); it != alphabet.end(); it++)
	{
		Node n = {it->first,it->second,NULL,NULL};
		alp.push_back(n);
	}
	while (alp.size() > 1)
	{
		SortAlp();
		Node *left = new Node;
		Node *right = new Node;
		*left = { alp[alp.size() - 1].key,alp[alp.size() - 1].p,alp[alp.size() - 1].left,alp[alp.size() - 1].right};
		*right = { alp[alp.size() - 2].key,alp[alp.size() - 2].p,alp[alp.size() - 2].left,alp[alp.size() - 2].right};
		*head = { '@',alp[alp.size() - 2].p + alp[alp.size() - 1].p,left,right};
		alp.erase(alp.end() - 2, alp.end());
		alp.push_back(*head);
	}
	EncodeTree(head,"");
	
}

//输出编码
void HuffmanTree::OutEncode()
{
	for (map<char, string>::iterator it = encodeb.begin(); it != encodeb.end(); it++)
	{
		cout << it->first << ':' << it->second << endl;
	}
}

//对字符串编码
string HuffmanTree::EncodeStr(string str)
{
	string encode = "";
	char *cstr = (char *)str.c_str();
	for (int i = 0; i < str.size(); i++)
	{
		encode += encodeb[cstr[i]];
	}
	return encode;
}

//对字符串进行解码
string HuffmanTree::DecodeStr(string str)
{
	string decode = "";
	Node *p = head;
	char *cstr = (char *)str.c_str();
	for (int i = 0; i < str.size(); i++)
	{
		if (p->left != NULL)
		{
			if (cstr[i] == '0') p = p->left;
			if (cstr[i] == '1') p = p->right;
		}
		if (p->left == NULL)
		{
			decode += p->key;
			p = head;
		}
	}
	return decode;
}

//进行编码HuffManTree
void HuffmanTree::EncodeTree(Node *head,string str)
{
	if (head != NULL)
	{
		EncodeTree(head->left,str+'0');
		if (head->left == NULL)
		{
			encodeb[head->key] = str;
		}
		EncodeTree(head->right,str+'1');
	}
}

//对字母概率排序
void HuffmanTree::SortAlp()
{
	for (int i = 0; i < alp.size(); i++)
		for (int j = i + 1; j < alp.size(); j++)
		{
			if (alp[i].p < alp[j].p)
			{
				Node tmp = alp[i];
				alp[i] = alp[j];
				alp[j] = tmp;
			}
		}
	/*for (vector<pair<char, int>>::iterator it = alp.begin(); it != alp.end(); it++)
	{
		cout << it->second << ' ';
	}*/
}