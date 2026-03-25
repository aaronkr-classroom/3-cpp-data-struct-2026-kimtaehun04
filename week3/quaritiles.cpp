//quartiles.cpp
/*
	25% => 출력
	50%(중앙값) => 출력
	75% => 출력
*/
#include <iostream>
#include <vector>
#include <algorithm> // sort()

using namespace std;

typedef vector<int> ::size_type vec_sz;

int main(void) {
	cout << "Enter all numbers, then EOF: "; //End of File: ctrl + d, ctrl + z
	vector<int> v;
	int in;
	
	while (cin >> in) {
		v.push_back(in);
	}
	vec_sz size = v.size();
	if (size == 0) {
		cout << "No data! Try again!" << endl;
		return 1; //오류 코드
	}
	// 정렬
	sort(v.begin(), v.end());

	vec_sz q1 = size / 4;
	vec_sz q2 = size / 2;
	vec_sz q3 = size / 4 * 3;
	
	int q1_v, q2_v, q3_v;
	q1_v = size % 4 == 0 ? (v[q1 - 1] + v[q1]) / 2 : v[q1];
	q2_v = size % 2 == 0 ? (v[q2 - 1] + v[q2]) / 2 : v[q2];
	q3_v = size % 4 == 0 ? (v[q3 - 1] + v[q3]) / 2 : v[q3];

	cout <<
		"Q1: " << q1_v << endl <<
		"Q2(중앙값): " << q2_v << endl <<
		"Q3: " << q3_v << endl;

	return 0;
}