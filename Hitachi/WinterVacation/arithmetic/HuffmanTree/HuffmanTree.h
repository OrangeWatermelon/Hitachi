#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Node
{
public:
	char key;
	int p;
	Node *left;
	Node *right;
};

class HuffmanTree
{
public:
	//字母对应编码
	map<char, string> encodeb;
	map<char, int> encoded;
	//待编码的字符串
	string data;
	//字母表
	map<char, int> alphabet;
	//字母表
	vector<Node> alp;
	//根节点
	Node *head = new Node;
	HuffmanTree(string str);
	void CreateHuffmam();
	void EncodeTree(Node *,string);
	string EncodeStr(string str);
	string DecodeStr(string str);
	void OutEncode();
private:
	void SortAlp();
	void probability();
};