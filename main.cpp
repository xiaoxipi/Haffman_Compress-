#include"Node.h"
#include"MinHeap.h"
#include"Haffman.h"

int  main()
{
	/*Frequency_Node a(11, 0.11);
	Frequency_Node b(12, 0.09);
	//cout << a.frequency << endl;
	a = b;
	//cout << a.number << " " << a.frequency << endl;
	if (a > b)
		cout << "!!!" << endl;

	MinHeap<int> heap;
	int* a1 = new int[6];
	for (int i = 6; i >= 1; i--)
	{
		a1[6 - i] = i;
	}
	heap.GetElem(a1, 6);
	heap.BuildHeap();
	heap.Show();
	heap.AddElem(0);
	heap.Show();
	heap.GetMin();
	heap.Show();*/
	int ins = 0;
	while (ins != 3)
	{
		cout << "1.Compress" << endl << "2.DeCompress" << endl << "3.Exit"<<endl<<"Choose:";
		cin >> ins;
		if (ins == 1)
		{
			RunCompress();
		}
		else if (ins == 2)
		{
			RunDeCompress();
		}
	}
	/*RunCompress();
	RunDeCompress();*/
	system("pause");
	return 0;
}