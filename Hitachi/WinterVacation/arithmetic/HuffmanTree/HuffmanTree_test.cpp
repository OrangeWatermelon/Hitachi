//链表实现HuffmanTree
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "HuffmanTree.h"
using namespace std;

int main()
{
	string str = "nicetomeetyou";
	HuffmanTree demo(str);
	demo.CreateHuffmam();
	demo.OutEncode();
	string encode_str = demo.EncodeStr(str);
	string decode_str = demo.DecodeStr(encode_str);
	cout << "源字符串：" << str << endl;
	cout << "编码后：" << encode_str << endl;
	cout << "解码后：" << decode_str << endl;
}
