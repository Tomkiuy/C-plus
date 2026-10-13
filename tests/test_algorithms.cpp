// test_algorithms.cpp : BiSearch()、Bubble()、Exchange() 的單元測試
// 案例編號對應 TEST_PLAN.md 第 4.1～4.3 節

#undef NDEBUG
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include "BinarySearch.h"

using namespace std;

//-----4.1 BiSearch()-----------------------------------
void TestBiSearch(){
	int V[] = {1, 3, 5, 7, 9};
	assert(BiSearch(V, 5, 5) == 2);    // BS-01
	assert(BiSearch(V, 5, 1) == 0);    // BS-02
	assert(BiSearch(V, 5, 9) == 4);    // BS-03
	assert(BiSearch(V, 5, 0) == -1);   // BS-04
	assert(BiSearch(V, 5, 4) == -1);   // BS-05
	assert(BiSearch(V, 5, 10) == -1);  // BS-06

	int One[] = {5};
	assert(BiSearch(One, 1, 5) == 0);  // BS-07
	assert(BiSearch(One, 1, 6) == -1); // BS-08

	assert(BiSearch((int*)nullptr, 0, 5) == -1); // BS-09

	int Dup[] = {2, 2, 2};             // BS-10
	int Index = BiSearch(Dup, 3, 2);
	assert(Index >= 0 && Index <= 2 && Dup[Index] == 2);

	double D[] = {1.5, 2.5, 3.5};
	assert(BiSearch(D, 3, 2.5) == 1);  // BS-11

	char C[] = {'a', 'c', 'e'};
	assert(BiSearch(C, 3, 'e') == 2);  // BS-12
}

//-----4.2 Bubble()-------------------------------------
template <class T, int N>
bool Equal(const T (&A)[N], const T (&B)[N]){
	return equal(A, A + N, B);
}

void TestBubble(){
	int Sorted[] = {1, 2, 3, 4, 5};    // BB-01
	Bubble(Sorted, 5);
	assert(Equal(Sorted, {1, 2, 3, 4, 5}));

	int Reverse[] = {5, 4, 3, 2, 1};   // BB-02
	Bubble(Reverse, 5);
	assert(Equal(Reverse, {1, 2, 3, 4, 5}));

	int Same[] = {7, 7, 7};            // BB-03
	Bubble(Same, 3);
	assert(Equal(Same, {7, 7, 7}));

	int Dup[] = {3, 1, 3, 2, 1};       // BB-04
	Bubble(Dup, 5);
	assert(Equal(Dup, {1, 1, 2, 3, 3}));

	int Neg[] = {0, -2, 5, -9};        // BB-05
	Bubble(Neg, 4);
	assert(Equal(Neg, {-9, -2, 0, 5}));

	Bubble((int*)nullptr, 0);          // BB-06

	int Single[] = {42};               // BB-07
	Bubble(Single, 1);
	assert(Single[0] == 42);

	// BB-08；以 -fsanitize=address 編譯時同時涵蓋 BB-09
	const int size = 1000;
	int Data[size], Expected[size];
	srand(12345);
	for (int i = 0; i < size; i++)
		Data[i] = Expected[i] = RandI(1000);
	Bubble(Data, size);
	sort(Expected, Expected + size);
	assert(equal(Data, Data + size, Expected));
}

//-----4.3 Exchange()-----------------------------------
void TestExchange(){
	int A = 1, B = 2;                  // EX-01
	Exchange(A, B);
	assert(A == 2 && B == 1);

	string S = "foo", T = "bar";       // EX-02
	Exchange(S, T);
	assert(S == "bar" && T == "foo");

	int X = 3;                         // EX-03
	Exchange(X, X);
	assert(X == 3);
}

//-----main----------------------------------------------
int main(){
	TestBiSearch();
	TestBubble();
	TestExchange();
	cout << "All tests passed" << endl;
	return 0;
}
