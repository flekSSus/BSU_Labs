#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int cmp(const void* val1, const void* val2)
{
	return *(int*)val1 - *(int*)val2;
}
void FillArray(unsigned long* arr,int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 60;
	}
}
void ArrOutput(unsigned long* arr,int length)
{
	cout << endl;
	for (int i = 0,counter=0; i < length; i++,counter++)
	{
		if (counter == 7)
		{
			cout << "|" << endl;
			counter = 0;
		}
			
		cout << arr[i]<<" ";
	}
	cout << endl<<"/////////////////////////////////////////////////"<<endl;
}
int MinArrNum(unsigned long* arr, int length,int i)
{
	int minValue = arr[i];
	int minNumber=i;
	for (; i < length; i++)
	{
		if (arr[i] < minValue)
		{
			minValue = arr[i];
			minNumber = i;
		}
	}
	return minNumber;
}
void ChoiceSort(unsigned long* arr, int length)
{
	int tmp;
	int minNum = 0;
	for (int i = 0; i < length; i++)
	{
		tmp = arr[i];
		minNum = MinArrNum(arr, length, i);
		arr[i] = arr[minNum];
		arr[minNum] = tmp;
	}
	
}
void BiSort(unsigned long* arr, int length)
{
	int tmp;
	int i, j, leftInd, rightInd;
	int midInd;

	for (i = 0; i < length; i++)
	{
		tmp = arr[i];
		leftInd = 0;
		rightInd = i;
		while (leftInd < rightInd)
		{
			midInd = (rightInd + leftInd) / 2;
			if (tmp <arr[midInd])
			{
				rightInd = midInd;
			}
			else
			{
				leftInd = midInd + 1;
			}
		}
		for (j = i; j >leftInd; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[leftInd] = tmp;
	}

}

int main()
{
	srand((unsigned int)time(NULL));

	int element;
	int length;
	int sortInd=0;
	string answer;

	cout << "Enter length of array: ";
	cin >> length;

	while (length < 0)
	{
		cout << "Exeption! Only positive numbers"<<endl<<endl;
		cout << "Enter length of array: ";
		cin >> length;
	}

	unsigned long* arr = new unsigned long[length];

	FillArray(arr,length);
	ArrOutput(arr,length);
	while (sortInd != 1&&sortInd!=2 && sortInd!=3&&sortInd!=4)
	{
		cout << "Choose which sorting you will use: ChoiceSort(enter 1), qsort(enter 2), BinarySort(enter 3), sort(enter 4)" << endl;
		cin >> sortInd;
	}
	
	switch (sortInd)
	{
	case 1:
		ChoiceSort(arr, length);
	case 2:
		qsort(arr, length, sizeof(unsigned long), cmp);
	case 3:
		BiSort(arr,length);
	case 4:
		sort(arr, arr+length);
	};

	ArrOutput(arr, length);
	cout << "Do you want to continue? (yes/no)\n";
	cin >> answer;

	if (answer == "yes")
	{
		cout << "What element do you want to find?\n";
		cin >> element;
		if (bsearch(&element, arr, length, sizeof(unsigned long), cmp)!=NULL)
		{
			cout << "The element is in the array";
		}
		else
		{
			cout << "The element is not in the array";
		}
	}

	delete[]arr;
}