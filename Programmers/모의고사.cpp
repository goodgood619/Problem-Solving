#include <string>
#include <vector>
using namespace std;
int arr[3][12] = { {1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5} };
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int cor[10005] = { 0, };
	int peo[3] = { 0, };
	int Max = 0;
	for (int j = 0; j < 3; j++) {
		int cnt = 0;
		int p = 0;
		for (int i = 0; i < answers.size(); i++) {
			if (j == 0) {
				if (i % 5 == 0) {
					p = 0;
				}
				if (arr[j][p] == answers[i]) cnt++;
				p++;
			}
			else if (j == 1) {
				if (i % 8 == 0) {
					p = 0;
				}
				if (arr[j][p] == answers[i]) cnt++;
				p++;
			}
			else {
				if (i % 10 == 0) {
					p = 0;
				}
				if (arr[j][p] == answers[i]) cnt++;
				p++;
			}
		}
		Max = max(Max, cnt);
		peo[j] = cnt;
		cor[cnt]++;
	}
	for (int i = 0; i < 3; i++) {
		if (peo[i] == Max) answer.push_back(i + 1);
	}
	return answer;
}