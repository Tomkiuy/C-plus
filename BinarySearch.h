// BinarySearch.h : BiSearch()、Bubble()、Exchange()、RandI() 的定義

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <cstdlib>

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

#endif
