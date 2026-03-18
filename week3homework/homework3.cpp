#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

static const unordered_set<string> DEFAULT_STOPWORDS = {
    "the","and","a","an","of","to","in","is","it","that","this","for","on","with","as","by","at","from"
};

string normalize_word(const string& s) {
    string out;
    out.reserve(s.size());
    for (unsigned char ch : s) {
        if (isalnum(ch)) {
            out.push_back(static_cast<char>(tolower(ch)));
        }
        else {
            // treat other chars as separators
        }
    }
    return out;
}

void count_words(istream& in,
    unordered_map<string, int>& counts,
    const unordered_set<string>& stopwords) {
    string line;
    while (getline(in, line)) {
        string token;
        for (unsigned char ch : line) {
            if (isalnum(ch)) {
                token.push_back(static_cast<char>(tolower(ch)));
            }
            else {
                if (!token.empty()) {
                    string word = token;
                    if (stopwords.empty() || stopwords.find(word) == stopwords.end()) {
                        ++counts[word];
                    }
                    token.clear();
                }
            }
        }
        if (!token.empty()) {
            string word = token;
            if (stopwords.empty() || stopwords.find(word) == stopwords.end()) {
                ++counts[word];
            }
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> wordCount;
    unordered_set<string> stopwords = DEFAULT_STOPWORDS;
    int topN = 0; // 0 => print all

    // Usage:
    // 1) ./program                <- read stdin
    // 2) ./program filename       <- read file
    // 3) ./program filename N     <- read file, print top N
    // 4) ./program -nostop        <- read stdin without default stopwords
    // 5) ./program filename -nostop N
    istream* inptr = &cin;
    ifstream infile;
    bool noStop = false;
    string filename;

    // parse arguments (simple)
    for (int i = 1; i < argc; ++i) {
        string a = argv[i];
        if (a == "-nostop") {
            noStop = true;
        }
        else if (filename.empty()) {
            filename = a;
        }
        else {
            try {
                topN = stoi(a);
                if (topN < 0) topN = 0;
            }
            catch (...) {
                // ignore parse errors, keep default
            }
        }
    }

    if (noStop) stopwords.clear();

    if (!filename.empty()) {
        infile.open(filename);
        if (!infile) {
            cerr << "파일을 열 수 없습니다: " << filename << "\n";
            return 1;
        }
        inptr = &infile;
    }
    else {
        cout << "텍스트를 입력하세요 (Ctrl+Z 또는 EOF로 종료):\n";
    }

    count_words(*inptr, wordCount, stopwords);

    // move to vector and sort by frequency desc, then word asc
    vector<pair<string, int>> vec;
    vec.reserve(wordCount.size());
    for (const auto& p : wordCount) vec.emplace_back(p.first, p.second);

    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
        });

    cout << "\n===== 단어 등장 횟수 =====\n";
    int printed = 0;
    for (const auto& p : vec) {
        cout << p.first << " : " << p.second << "회\n";
        ++printed;
        if (topN > 0 && printed >= topN) break;
    }

    return 0;
}