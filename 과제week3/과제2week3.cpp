#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> wordCount;
    std::string word;

    std::cout << "텍스트를 입력하세요 (입력 종료: Ctrl+D (Linux/Mac) 또는 Ctrl+Z (Windows)):\n";

    // 표준 입력에서 공백 기준으로 단어를 하나씩 읽음
    while (std::cin >> word) {
        wordCount[word]++;
    }

    // 결과 출력
    std::cout << "\n===== 단어 등장 횟수 =====\n";
    for (const auto& [w, count] : wordCount) {
        std::cout << "\"" << w << "\" : " << count << "회\n";
    }

    return 0;
}