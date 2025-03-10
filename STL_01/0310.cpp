//--------------------------------------------------------------------
// 2025. 3-1. STL, 3월 6일 목요일 (1주 1일)
//--------------------------------------------------------------------
// 한 학기 강의를 저장할 save 기능
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>

void save( std::string_view fileName);

int main()
{
	std::cout << "2025년 3학년 1학기 STL" << std::endl;

	save("0310.cpp");
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

	// 저장했다는 것을 화면에 표시하자.
	std::cout << fileName << "(" << std::filesystem::file_size(fileName)
		<< " bytes) 저장하였습니다." << std::endl;

	// 2. 쓰기 모드로 저장할 파일을 연다.(덧붙이기 모드로)
	std::ofstream out{ "2025 1학기 STL 월910 목910 강의저장.txt", std::ios::app};
	
	// 3. 파일을 읽어서 저장할 파일에 덧붙인다.
	std::vector<char> v(std::filesystem::file_size(fileName));
	// while은 매번 읽으며 '평가'를 하기 때문에 비효율적임
	std::copy(std::istreambuf_iterator{ in }, {}, v.begin());
	std::copy(v.begin(), v.end(), std::ostreambuf_iterator{out});
};
