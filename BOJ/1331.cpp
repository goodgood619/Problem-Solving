#include <cstdio>
#include <algorithm>
using namespace std;
bool visited[7][7];
char input[3];
int cnt,pre1,pre2,idx,idy,first,second;
bool check;
int gox[8] = {1,1,-1,-1,2,2,-2,-2};
int goy[8] = {2,-2,2,-2,1,-1,1,-1};
int main() {
	while (1){
		if (cnt == 36){
			bool chk = false;
			for (int i = 0; i < 8; i++) {
				int nx = idx+ gox[i];
				int ny = idy + goy[i];
				if (nx == first && ny == second) { chk = true; }
			}
			if (!chk) { check = true; break; }
			else break;
		}
		scanf("%s", input);
		if (cnt >= 1) {
			pre1 = idx;
			pre2 = idy;
		}
		for (int i = 1; i>=0; i--) {
			if (input[i] >= '1' && input[i] <= '6') {
				int num = input[i] - '0';
				idx = num;
			}
			else if (input[i] >= 'A' && input[i] <= 'F'){
				int num2=input[i] - 64;
				idy = num2;
			}
		}
		if (idx < 1 || idx>6 || idy < 1 || idy>6) { check = true; break;}
		if (visited[idx][idy]) { check = true; break;}
		if (cnt >= 1) {
			bool chk = false;
			for (int i = 0; i < 8; i++) {
				int nx = pre1 + gox[i];
				int ny = pre2 + goy[i];
				if (nx == idx && ny == idy) { chk = true; }
			}
			if (!chk) { check = true; break;}
		}
		if (cnt == 0) { first = idx; second = idy; }
		visited[idx][idy] = true;
			cnt++;
	}
	if (check) printf("Invalid\n");
	else printf("Valid\n");
	return 0;
}