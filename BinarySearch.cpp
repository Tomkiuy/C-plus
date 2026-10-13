// BinarySearch.cpp : 定義主控台應用程式的進入點。
//

#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

//-----define temple BiSearch()-----------------------
template <class T>
int BiSearch(T *V, int N, T Key) {
	int Left = 0, Right, Mid;
	Right = N - 1;
	while (Left <= Right) {
		Mid = (int)((Left + Right) / 2);
		if (Key == V[Mid]) return Mid;
		else if (Key > V[Mid])
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}
	return -1;
}
//-----define inline RandI(), creat 1 to N number for random
inline int RandI(int N){ return rand() % N + 1; }

//-----define Exchange()--------------------------------
template <class T>
void Exchange(T& A, T& B){
	T Temp;
	Temp = A; A = B; B = Temp;
}
//-----define Bubble()----------------------------------
template <class T>
void Bubble(T *V, int N){
	for(int i = 0; i < N; i++)
		for(int j = N - 1; j > i; j--) 
			if(V[j] < V[j-1])
				Exchange(V[j], V[j-1]);
	return;
}
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

