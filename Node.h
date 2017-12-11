#pragma once

#include<iostream>
using namespace std;


class Frequency_Node
{
public:
	int number;
	double frequency;

public:
	Frequency_Node() {}
	Frequency_Node(int n, double f) { number = n; frequency = f; }
	friend bool operator >(Frequency_Node &a, Frequency_Node &b) { return a.frequency > b.frequency; }
	friend bool operator <(Frequency_Node &a, Frequency_Node &b) { return a.frequency < b.frequency; }
	friend bool operator >=(Frequency_Node &a, Frequency_Node &b) { return a.frequency >= b.frequency; }
	friend bool operator <=(Frequency_Node &a, Frequency_Node &b) { return a.frequency <= b.frequency; }
	Frequency_Node& operator=(const Frequency_Node& a);

};

Frequency_Node& Frequency_Node::operator=(const Frequency_Node&a)
{
	if (&a != this)
	{
		number = a.number;
		frequency = a.frequency;
	}
	return *this;
}
