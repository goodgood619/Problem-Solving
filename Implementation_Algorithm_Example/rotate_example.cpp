#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <deque>
using namespace std;
int gox[4] = { 0,0,-1,1};
int goy[4] = { 1,-1,0,0};
vector<string> splitSpace(string &s) {
	vector<string> v;
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			v.push_back(temp);
			temp.clear();
		}
		else {
			temp.push_back(s[i]);
		}
	}
	return v;
}
vector<vector<int>> rotate_matrix_90_degree(vector<vector<int>>& board) {

	int n = board.size();
	int m = board[0].size();
	vector<vector<int>> ret;
	ret.assign(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret[j][n-i-1] = board[i][j]; //시계방향
			// ret[n - j - 1][i] = board[i][j]; //반시계방향
		}
	}
	return ret;
}

vector<int> rotate_90_degree_border(vector<vector<int>> &board) {

	int n = board.size();
	vector<int> ret;
	for (int j = 0; j < n; j++) {
		ret.push_back(board[0][j]);
	}
	ret.pop_back();

	for (int i = 0; i < n; i++) {
		ret.push_back(board[i][n - 1]);
	}
	ret.pop_back();

	for (int j = n - 1; j >= 0; j--) {
		ret.push_back(board[n - 1][j]);
	}
	ret.pop_back();

	for (int i = n - 1; i >= 0; i--) {
		ret.push_back(board[i][0]);
	}
	ret.pop_back();

	rotate(ret.begin(), ret.end() - 1, ret.end());
	return ret;
}
vector<vector<int>> make_board_rotate_border(vector<int> &v,vector<vector<int>> &board) {
	int n = board.size();
	vector<int> ret;
	int idx = 0;
	for (int j = 0; j < n; j++) {
		board[0][j] = v[idx++];
	}

	for (int i = 1; i < n; i++) {
		board[i][n - 1] = v[idx++];
	}
	for (int j = n - 2; j >= 0; j--) {
		board[n - 1][j] = v[idx++];
	}

	for (int i = n - 2; i > 0; i--) {
		board[i][0] = v[idx++];
	}
	return board;
}
void print(vector<vector<int>> &board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}
int main() {
	string s;
	s = "i am a good boy";
	auto res = splitSpace(s);
	for (auto& value : res) {
		printf("%s\n", value.c_str());
	}

	vector<pair<int, int>> v = { {10,10},{40,40},{50,50},{30,30},{20,20} };

	rotate(v.begin(), v.begin() + 1, v.end()); //왼쪽으로 한번
	for (auto& value : v) {
		printf("%d %d\n", value.first,value.second);
	}

	rotate(v.begin(), v.end() - 1, v.end()); // 오른쪽으로 한번
	for (auto& value : v) {
		printf("%d %d\n", value.first,value.second);
	}

	vector<vector<int>> board;
	board.assign(5, vector<int>(5, 0));
	int cnt = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[i][j] = cnt++;
		}
	}

	print(board);
	vector<int> temp = rotate_90_degree_border(board);
	board = make_board_rotate_border(temp, board);

	print(board);
	vector<vector<int>> newboard = rotate_matrix_90_degree(board);
	print(newboard);
	return 0;
}
