
#include <iostream>
#include "save.h"
using namespace std;

// [문제] main을 변경하지 않고 의도대로 실행되게 코딩하라

// 꼼수1: #define Dog int 
// 꼼수2: using Dog = int; (꼼수1 보다는 훨씬 좋음)

// [조건] Dog를 클래스로 쓰시오

class Dog
{
public:
	Dog() = default;
	Dog(int n) : num{ n } {}


private:
	int num;	// 4 + 4

	friend ostream& operator<<(ostream& os, const Dog& dog) { 
		// friend 키워드로 ostream에게 Dog를 모두 공개
		return os << dog.num;
	}
};

void change(int&, int&);
void change(Dog&, Dog&);

int main()
{
	{
		Dog a{ 1 }, b{ 2 };
		change(a, b); // 도대체 어떤 함수를 호출하는 것인가?
		// 1. change(Dog, Dog);
		// 2. change(Dog&, Dog&);
		// 3. 1, 2가 없으면, 컴파일러가 직접 만든다?

		cout << a << ", " << b << endl; // [출력] 2, 1
	}
	{
		int a{ 1 }, b{ 2 };
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
	Dog temp{ num1 };	// 저장
	num1 = num2;
	num2 = temp;
}