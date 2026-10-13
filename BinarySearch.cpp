// BinarySearch.cpp : 定義主控台應用程式的進入點。
//

#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "BinarySearch.h"

using namespace std;

//-----main----------------------------------------------
int main()
{
	int Index, Key = 500;
	srand(int(time(0)));

	const int size = 1000;
	int data[size];
	
	for (int i = 0; i < size; i++) {
		data[i] = RandI(1000);
	}
	cout << "\ndata原來的值是:\n";
	for(int i = 0; i < size; i++){
		cout << setw(10) << data[i];
		if (i % 5 == 4) cout << endl;
	}
	Bubble(data, size);
	cout << "\n執行 Bubble() 之後, data的值是:\n";
	for(int i = 0; i < size; i++){
		cout << setw(10) << data[i];
		if(i%5 == 4) cout << endl;
	}
	Index = BiSearch(data, size, Key);
	if(Index > -1)
		cout << Key << "在第 " << Index+1 << "個元素的地方\n";
	else
		cout << "找不到 " << Key << endl; 
	
	cin.get();
    return 0;
}

