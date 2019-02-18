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
	//��ĸ��Ӧ����
	map<char, string> encodeb;
	map<char, int> encoded;
	//��������ַ���
	string data;
	//��ĸ��
	map<char, int> alphabet;
	//��ĸ��
	vector<Node> alp;
	//���ڵ�
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