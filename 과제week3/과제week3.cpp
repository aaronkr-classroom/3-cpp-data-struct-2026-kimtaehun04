#include <iostream>
#include <string>
using namespace std;

int main() {
    string words[100];  // 최대 100개 저장
    int count = 0;

    cout << "문자열을 입력하세요 (끝내려면 빈 줄 입력)" << endl;
    cout << "----------------------------------------" << endl;

    // 1. 문자열 입력 받기
    while (count < 100) {
        cout << count + 1 << "번째: ";
        getline(cin, words[count]);

        if (words[count] == "") {  // 빈 줄이면 종료
            break;
        }
        count++;
    }

    // 2. 입력이 없으면 종료
    if (count == 0) {
        cout << "입력된 문자열이 없습니다." << endl;
        return 0;
    }

    // 3. 가장 긴 문자열, 가장 짧은 문자열 찾기
    int maxIndex = 0;  // 가장 긴 문자열의 위치
    int minIndex = 0;  // 가장 짧은 문자열의 위치

    for (int i = 1; i < count; i++) {
        if (words[i].length() > words[maxIndex].length()) {
            maxIndex = i;
        }
        if (words[i].length() < words[minIndex].length()) {
            minIndex = i;
        }
    }

    // 4. 결과 출력
    cout << endl;
    cout << "========== 결과 ==========" << endl;
    cout << "가장 긴  문자열: " << words[maxIndex]
        << " (길이: " << words[maxIndex].length() << ")" << endl;
    cout << "가장 짧은 문자열: " << words[minIndex]
        << " (길이: " << words[minIndex].length() << ")" << endl;
    cout << "==========================" << endl;

    return 0;
}
