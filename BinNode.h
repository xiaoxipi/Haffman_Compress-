#pragma once

#include<iostream>
using namespace std;
class BinNodeFrequency
{
private:
	double frequency;
	int number;
	BinNodeFrequency* rightChild;
	BinNodeFrequency* leftChild;
	BinNodeFrequency* parent;
public:
	BinNodeFrequency() { rightChild = leftChild=parent = NULL; frequency = 0; number = -1; }
	BinNodeFrequency(double f, BinNodeFrequency*r=NULL, BinNodeFrequency*l=NULL, BinNodeFrequency*p=NULL,int n=-1) : number(n),frequency(f), rightChild(r), leftChild(l),parent(p) {}
	friend bool operator>(const BinNodeFrequency&a, const BinNodeFrequency&b);
	friend bool operator>=(const BinNodeFrequency&a, const BinNodeFrequency&b);
	friend bool operator<(const BinNodeFrequency&a, const BinNodeFrequency&b);
	friend bool operator<=(const BinNodeFrequency&a, const BinNodeFrequency&b);
	BinNodeFrequency operator=(const  BinNodeFrequency&a);
	double Frequency() { return frequency; }
	BinNodeFrequency* RightChild() { return rightChild; }
	BinNodeFrequency* LeftChild() { return leftChild; }
	void setNumbner(int n) { number = n; }
	void setFrequency(double freq) { frequency = freq; }
	int Number() { return number; }
	int getNumber() { return number; }
	double getFrequency() { return frequency; }
	void setRight(BinNodeFrequency*r)
	{
		rightChild = r;
	}
	void setLeft(BinNodeFrequency*l)
	{
		leftChild = l;
	}
	BinNodeFrequency* Parent() { return parent; }
	void setParent(BinNodeFrequency* p) { parent = p; }
};

BinNodeFrequency BinNodeFrequency::operator=(const BinNodeFrequency&a)
{
	if (&a != this)
	{
		number = a.number;
		frequency = a.frequency;
		rightChild = a.rightChild;
		leftChild = a.leftChild;
		parent = a.parent;
	}
	return  *this;
}

bool operator>(const BinNodeFrequency&a, const BinNodeFrequency&b)
{
	return a.frequency > b.frequency;
}

bool operator>=(const BinNodeFrequency&a, const BinNodeFrequency&b)
{
	return a.frequency >= b.frequency;
}

bool operator<(const BinNodeFrequency&a, const BinNodeFrequency&b)
{
	return a.frequency < b.frequency;
}

bool operator<=(const BinNodeFrequency&a, const BinNodeFrequency&b)
{
	return a.frequency <= b.frequency;
}