// str_size.cpp
#include <iostream>
#include <string>

using namespace std;
int main(void) {
	cout << "Enter all words, then EOF: "; //End of File: ctrl + d, ctrl + z
	
	
	//입력 받기
	string word;
	string max = "";
	string min = "";

	while (cin >> word) {
		if (min. size() == 0) min = word; //초기화
		if (max.size() == 0) max = word; //초기화

		
		/// 크기 확인
		if (word.size() < min.size()) min = word;
		else if (word.size() < max.size()) max = word;

		//결과 출력
		cout <<
			"Min word: " << min << "size: " << min.size() << endl <<
		    "Max word: " << max << "size: " << max.size() << endl;	
		
	}
	return 0;
}