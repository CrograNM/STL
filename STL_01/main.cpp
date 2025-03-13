
#include <iostream>
#include "save.h"
using namespace std; // 여러분은 이렇게 하지 마세요

// [문제] main을 변경하지 않고 의도대로 실행되게 코딩하라

// 꼼수1: #define Dog int 
// 꼼수2: using Dog = int; (꼼수1 보다는 훨씬 좋음)

// [조건] Dog를 클래스로 쓰시오

class Dog
{
public:
	int data;
	Dog(int num)
	{
		data = num;
	}
	operator int() { return data; } // 나의 답 : int() Wrapping
};

void change(int&, int&);
void change(Dog&, Dog&);

int main()
{
	{
		Dog a{ 1 }, b{ 2 }; // 초기화는 { }로 하자!
		change(a, b);
		cout << a << ", " << b << endl; // [출력] 2, 1
	}
	{
		int a{ 1 }, b{ 2 }; // 초기화는 { }로 하자!
		change(a, b);
		cout << a << ", " << b << endl; // [출력] 2, 1
	}
	//save("main.cpp");
}

void change(int& num1, int& num2)
{
	int temp{ num1 };	// 저장
	num1 = num2;		
	num2 = temp;		
}
void change(Dog& num1, Dog& num2)
{
	int temp{ num1.data };	// 저장
	num1.data = num2.data;
	num2.data = temp;
}