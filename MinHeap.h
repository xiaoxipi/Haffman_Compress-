#pragma once

#include<iostream>
using namespace std;
#define MaxSize 100

template<class ElemType>
class MinHeap
{
private:
	ElemType *Array;
	int MaxDauflt;
	int size;
public:
	MinHeap(int M = MaxSize);
	void GetElem(ElemType* a, int n);
	void ShiftDown(int n);
	void ShiftUp(int n);
	void BuildHeap();
	ElemType GetMin();
	bool IsEmpty();
	void Show();
	void AddElem(ElemType a);
	int GetSize() { return size; }
};


template<class ElemType>
void MinHeap<ElemType>::AddElem(ElemType a)
{
	if (size < MaxSize)
	{
		Array[size] = a;
		size++;
		ShiftUp(size - 1);
	}
	else
	{
		cout << "error!" << endl;
		system("pause");
		exit(1);
	}
}

template<class ElemType>
void MinHeap<ElemType>::Show()
{
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}

template<class ElemType>
MinHeap<ElemType>::MinHeap(int M = MaxSize)
{
	MaxDauflt = M;
	size = 0;
	Array = new ElemType[MaxDauflt];
}

template<class ElemType>
void MinHeap<ElemType>::GetElem(ElemType *a, int n)
{
	if (n > MaxDauflt||n<=0)
	{
		cout << "³¬½ç£¡" << endl;
		system("pause");
		exit(0);
	}
	else
	{
		size = n;
		for (int i = 0; i < n; i++)
		{
			Array[i] = a[i];
		}
	}
}

template<class ElemType>
bool MinHeap<ElemType>::IsEmpty()
{
	return size == 0;
}

template<class ElemType>
void MinHeap<ElemType>::ShiftDown(int n)
{
	while (2 * n+2  <= size)
	{
		if (2 * n + 2 == size)
		{
			if (Array[2 * n + 1] < Array[n])
				Swap(Array, n, 2 * n + 1);
			break;
		}
		else
		{
			if (Array[2 * n + 1] > Array[2 * n + 2])
			{
				if (Array[n] > Array[2 * n + 2])
				{
					Swap(Array, n, 2 * n + 2);
					n = 2 * n + 2;
					continue;
				}
				else if (Array[n] > Array[2 * n + 1])
				{
					Swap(Array, n, 2 * n + 1);
					n = 2 * n + 1;
					continue;
				}
				else
					break;
			}
			else
			{
				if (Array[n] > Array[2 * n + 1])
				{
					Swap(Array, n, 2 * n + 1);
					n = 2 * n + 1;
					continue;
				}
				else if (Array[n] > Array[2 * n + 2])
				{
					Swap(Array, n, 2 * n + 2);
					n = 2 * n + 2;
					continue;
				}
				else
					break;
			}
		}
	}
}

template<class ElemType>
void MinHeap<ElemType>::ShiftUp(int n)
{
	while (n > 0)
	{
		if (Array[n] < Array[(n - 1) / 2])
		{
			Swap(Array, n, (n - 1) / 2);
			n = (n - 1) / 2;
			continue;
		}
		else
			break;
	}
}

template<class ElemType>
ElemType MinHeap<ElemType>::GetMin()
{
	Swap(Array, 0, size - 1);
	size--;
	ShiftDown(0);
	return Array[size];
}

template<class ElemType>
void MinHeap<ElemType>::BuildHeap()
{
	for (int i = size / 2 - 1; i >= 0; i--) ShiftDown(i);
}
/*#include<iostream>
using namespace std;

#define MaxSize 100

class MinHeap
{
private:
	int * Array;
	int MaxDauflt;
	int size;
public:
	MinHeap(){}
	MinHeap(int M) {}
	void GetNumber(int *a, int n) {}
	void ShiftDown(int n) {}
	void ShiftUP(int n) {}
	void BuildHeap(){}
	int Get
};

MinHeap::MinHeap()
{
	MaxDauflt = MaxSize;
	Array = new int[MaxDauflt];
}

MinHeap::MinHeap(int M)
{
	MaxDauflt = M;
	Array = new int[MaxDauflt];
}

void MinHeap::GetNumber(int *a, int n)
{
	size = n;
	for (int i = 0; i < size; i++)
	{
		Array[i] = a[i];
	}
}*/

template<class ElemType>
void Swap(ElemType*a, int i, int j)
{
	if (i == j)
		return;
	ElemType tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}