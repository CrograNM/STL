//--------------------------------------------------------------------
// 2025. 3-1. STL, 3월 6일 목요일 (1주 1일)
//--------------------------------------------------------------------
// 한 학기 강의를 저장할 save 기능
//--------------------------------------------------------------------
// 컴파일 환경
// Visual Studio version 17.13. 이후 버전 사용
// Release / x64, 
// 프로젝트 설정, C++언어 - /std:c++ latest, SDL 검사 - 아니요
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>


void save( std::string_view fileName);

int main()
{
	std::cout << "2025년 3학년 1학기 STL" << std::endl;

	save("메인.cpp");
}

// string view 는 (최신) 경량 객체로, 읽기만 가능하고 수정할 수 없다.
void save( std::string_view fileName)
{
	// 1. 인자로 전달된 fileName을 읽기 모드로 연다
	std::ifstream in{ fileName.data()}; // RAII*** cpp 핵심 기능
	
	if ( not in )
	{
		std::cout << fileName << "을 열 수 없습니다." << std::endl;
		exit(20250310);
	}

	// 2. 쓰기 모드로 저장할 파일을 연다.(덧붙이기 모드로)
	std::ofstream out{ "2025 1학기 STL 월910 목910 강의저장.txt", std::ios::app};
	
	// 3. 파일을 읽어서 저장할 파일에 덧붙인다.
};