#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct p {
	int likeCount, emptyCount, x, y;
};
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
pair<int,int> makeBoard(vector<vector<int>>& board,int num,int n,int x,int y) {

	board[x][y] = num;
	return { x,y };
}
void likeBetween(vector<vector<int>> &board, int x,int y,vector<vector<int>> &likeArray,int num,int n,vector<p> &v) {
	int likeCnt = 0;
	int emptyCnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n  || ny <1 || ny>n) continue;
		for (int j = 0; j < likeArray[num].size(); j++) {
			int likeNum = likeArray[num][j];

			if (board[nx][ny] == likeNum) {
				likeCnt++;
				break;
			}
		}
		if (board[nx][ny] == 0) emptyCnt++;
	}
	v.push_back({ likeCnt,emptyCnt,x,y });
}
bool compare(const p& a, const p& b) {
	if (a.likeCount != b.likeCount) return a.likeCount > b.likeCount;
	if (a.emptyCount != b.emptyCount) return a.emptyCount > b.emptyCount;
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
}
int likeCount(int x, int y, int num, vector<vector<int>>& likeArray,int n,vector<vector<int>> &board) {

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx> n || ny < 1 || ny>n) continue;
		
		for (int j = 0; j < likeArray[num].size(); j++) {
			if ( board[nx][ny]== likeArray[num][j]) {
				cnt++;
				break;
			}
		}
	}

	if (cnt == 0) return 0;
	else if (cnt == 1) return 1;
	else if (cnt == 2) return 10;
	else if (cnt == 3) return 100;
	else return 1000;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> likeArray;
	vector<vector<int>> board;
	likeArray.assign(n * n + 1, vector<int>(4, 0));
	board.assign(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n * n; i++) {
		int num, one, two, three, four;
		scanf("%d%d%d%d%d", &num, &one, &two, &three, &four);
		likeArray[num][0] = one;
		likeArray[num][1] = two;
		likeArray[num][2] = three;
		likeArray[num][3] = four;

		//비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
		vector<p> array;
		// 빈칸에 다 한번씩 넣어본다.
		// 좋아하는 학생이 인접한지 안한지를 체크한다. + 비어있는 칸의 갯수도 체크한다
		for (int i = 1; i <= n; i++) {
			for (int j =1; j <= n; j++) {
				vector<vector<int>> tempboard = board;
				if (tempboard[i][j] == 0) {
					pair<int,int> res =  makeBoard(tempboard, num,n,i,j);
					likeBetween(tempboard,res.first,res.second,likeArray,num,n,array);
				}
			}
		}

		sort(array.begin(), array.end(), compare);
		// 좋아하는 학생수, x좌표, y좌표를 넣어준다.
		//1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
		//2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
		// 정렬을 해줘야함, (좋아하는 학생수 내림차순, 비어있는 칸의 수, x좌표, y좌표 오름차순)

		
		board[array[0].x][array[0].y] = num;
	}


	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += likeCount(i,j,board[i][j], likeArray,n,board);
		}
	}

	printf("%d\n", ans);
	return 0;
}