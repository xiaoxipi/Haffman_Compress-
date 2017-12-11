#pragma once

#include"MinHeap.h"
#include"BinNode.h"
#include"Node.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


 class BinNode
{
public:
	 int parent;
	 int leftChild;
	 int rightChild;
	 int ch;
	 long frequency;
	 BinNode()
	 {
		 parent = -1;
		 leftChild = -1;
		 rightChild = -1;
		 ch = -1;
		 frequency = -1;
	 }
	 friend bool operator==(BinNode&a, BinNode&b) { return a.frequency == b.frequency; }
	 friend bool operator>=(BinNode&a, BinNode&b) { return a.frequency >= b.frequency; }
	 friend bool operator<=(BinNode&a, BinNode&b) { return a.frequency <= b.frequency; }
	 friend bool operator<(BinNode&a, BinNode&b) { return a.frequency < b.frequency; }
	 friend bool operator>(BinNode&a, BinNode&b) { return a.frequency > b.frequency; }
	 BinNode& operator=(BinNode&a)
	 {
		 if (&a != this)
		 {
			 parent = a.parent;
			 leftChild = a.leftChild;
			 rightChild = a.rightChild;
			 ch = a.ch;
			 frequency = a.frequency;
		 }
		 return *this;
	 }
 };

 void getRefl(BinNode* tree,int root, int& cur, string s, string *refl)
 {
	 if (tree[root].leftChild == -1)
	 {
		 refl[tree[root].ch] = s;
		 cur++;
	 }
	 else
	 {
		 getRefl(tree, tree[root].leftChild, cur, s + "1", refl);
		 getRefl(tree, tree[root].rightChild, cur, s + "0", refl);
	 }
 }


int MyPow(int a, int b)
{
	int all = 1;
	for (int i = 0; i < b; i++)
		all *= a;
	return all;
}

void RunCompress()
{
	string inpath, outpath;
	cout << "Please input sourse file name:";
	cin >> inpath;
	//inpath = "test.txt";
	ifstream infile;
	infile.open(inpath);
	if (!infile)
	{
		cout << "open the file: " << inpath << " error!" << endl;
		return;
	}
	cout << "please outoput sourse file name:";
	cin >> outpath;
	//outpath = "2.txt";
	ofstream outfile;
	outfile.open(outpath);
	if (!outfile)
	{
		cout << "open the file: " << outpath << " error!" << endl;
		return;
	}
	long* charfrequency = new long[256];
	for (int i = 0; i < 256; i++)charfrequency[i] = 0;
	char c;
	while (infile.get(c))
	{
		charfrequency[int(c)]++;
	}
	infile.close();
	infile.open(inpath);


	int number = 0;
	for (int i = 0; i < 256; i++)
	{
		if (charfrequency[i] != 0)
		{
			number++;
		}
	}
	BinNode* havechar = new BinNode[number];
	int cur = 0;
	for (int i = 0; i < 256; i++)
	{
		if (charfrequency[i] != 0)
		{
			havechar[cur].ch = i;
			havechar[cur].frequency = charfrequency[i];
			cur++;
		}
	}
	BinNode* tree = new BinNode[number * 2 - 1];
	MinHeap<BinNode> minheap;
	minheap.GetElem(havechar, number);
	minheap.BuildHeap();
	int treebuild = number * 2 - 2;
	while (minheap.GetSize() != 1)
	{
		tree[treebuild--] = minheap.GetMin();
		tree[treebuild--] = minheap.GetMin();
		BinNode next;
		next.frequency = tree[treebuild + 1].frequency + tree[treebuild + 2].frequency;
		next.rightChild = treebuild + 2;
		next.leftChild = treebuild + 1;
		minheap.AddElem(next);
	}
	tree[treebuild] = minheap.GetMin();
	for (int i = 0; i < 30; i++)
	{
		outfile << " ";
	}
	outfile << "\n";
	for (int i = 0; i < 2 * number - 1; i++)
	{
		outfile << tree[i].ch << " " << tree[i].leftChild << " " << tree[i].rightChild << "\n";
	}
	string* compress = new string[256];
	cur = 0;
	string s = "";
	getRefl(tree, 0, cur, s, compress);
	s = "";
	long compressall = 0;
	while (infile.get(c))
	{
		s += compress[int(c)];
		compressall += compress[int(c)].length();
		if (s.length() >= 8)
		{
			int charint = 0;
			for (int i = 0; i <= 7; i++)
			{
				s[i];
				charint += (s[i]-48)*MyPow(2, 7 - i);
			}
			s.replace(0, 8, "");
			outfile << unsigned char(charint);
		}
	}
	if (s.length() != 0)
	{
		int charint = 0;
		for (int i = 0; i < s.length(); i++)
		{
			charint += (s[i]-48)*MyPow(2, 7 - i);
		}
		outfile << unsigned char(charint);
	}
	outfile.seekp(ios::beg);
	outfile << compressall<<"\n"<<2*number-1;
	outfile.close();
	infile.close();
	infile.open(outpath);

}


string Change(int ch)
{
	string s = "";
	for (int i = 0; i < 8; i++)
	{
		if (ch / MyPow(2, 7 - i) == 1)
		{
			s += "1";
			ch -= MyPow(2, 7 - i);
		}
		else
		{
			s += "0";
		}
	}
	return s;
}




void RunDeCompress()
{
	string inpath, outpath;
	cout << "Please input code file name:";
	cin >> inpath;
	//inpath = "2.txt";
	ifstream infile;
	ofstream outfile;
	infile.open(inpath);
	if (!infile)
	{
		cout << "input code file :" << inpath << " error!" << endl;
		system("pause");
		return;
	}
	cout << "Please output code file name:";
	cin >> outpath;
	//outpath = "3.txt";
	outfile.open(outpath);
	if (!outfile)
	{
		cout << "output code file :" << outpath << " error!" << endl;
		system("pause");
		return;
	}
	long all;
	infile >> all;
	int node;
	infile >> node;
	int* ch = new int[node];
	int* left = new int[node];
	int*right = new int[node];
	for (int i = 0; i <node; i++)
	{
		infile >> ch[i] >> left[i] >> right[i];
	}
	char c;
	c = infile.get();
	int intch;
	string s = "";
	int cur = 0;
	while (all>=8 &&(!infile.eof()))
	{
		c = infile.get();
		intch = int(c);
		//cout << c;
		if (intch < 0)
		{
			intch += MyPow(2, 8);
		}

		
		all -= 8;
		
		s += Change(intch);
		while (s.length() >0)
		{
			if (s[0] == '1')
			{
				cur = left[cur];
			}
			else if (s[0] == '0')
			{
				cur = right[cur];
			}
			s.replace(0, 1, "");
			if (ch[cur] != -1)
			{
				outfile << unsigned char(ch[cur]);
				//cout << char(ch[cur]);
				cur = 0;
			}
		}
	}
	if (all != 0)
	{
		c=infile.get();
		//cout << s << endl;
		intch = int(c);
		if (intch < 0)
		{
			intch += MyPow(2, 8);
		}
		for (int i = 0; i < all%8; i++)
		{
			if (intch / MyPow(2, 7 - i) == 1)
			{
				s += "1";
				intch -= MyPow(2, 7 - i);
			}
			else
			{
				s += "0";
			}
		}
	}
	while (s.length() >0)
	{
		if (s[0] == '0')
		{
			cur = right[cur];
		}
		else if (s[0] == '1')
		{
			cur = left[cur];
		}
		s.replace(0, 1, "");
		if (ch[cur] != -1)
		{
			outfile << unsigned char(ch[cur]);
			cur = 0;
		}
	}
	infile.close();
	outfile.close();
}

