#include <stdio.h>
#include <algorithm>
using namespace std;
int r, c;
long long hab,newhab;
bool check;
int dice[7]={0,1,3,2,6,4,5};
void goright() {
	int temp = dice[5];
	dice[2] = dice[1];
	dice[1] = temp;
	dice[4] = 7 - dice[1];
	dice[5] = 7 - dice[2];
	dice[6] = 7 - dice[3];
	hab += dice[1];
	newhab += dice[1];
}
void goleft(){
	dice[1] = dice[2];
	int temp = dice[4];
	dice[2] = temp;
	dice[4] = 7 - dice[1];
	dice[5] = 7 - dice[2];
	dice[6] = 7 - dice[3];
	hab += dice[1];
	newhab += dice[1];
}
void godown() {
	int temp = dice[6];
	dice[3] = dice[1];
	dice[1] = temp;
	dice[4] = 7 - dice[1];
	dice[5] = 7 - dice[2];
	dice[6] = 7 - dice[3];
	hab += dice[1];
}
int main(){
	scanf("%d%d", &r, &c);
	hab += dice[1];
	for (int i = 1; i <= r; i++){
		int sk = (c-1) % 4;
		int ahr = (c - 1) / 4;
		if (ahr != 0) {
			newhab = 0;
			if (i % 2 == 1) {
				for (int i = 1; i <= 4; i++) {
					goright();
					hab -= dice[1];
				}
				newhab = newhab*ahr;
				hab += newhab;
				if (i!=r &&sk == 0) godown();
			}
			else if (i % 2 == 0) {
				newhab = 0;
				for (int i = 1; i <= 4; i++) {
					goleft();
					hab -= dice[1];
				}
				newhab = newhab*ahr;
				hab += newhab;
				if (i != r &&sk == 0)godown();
			}
		}
		for (int j = 1; j <= sk; j++){
			//오른쪽굴리기
			if (i % 2 == 1 && j!=sk) {
				goright();
			}
			//왼쪽굴리기
			else if(i%2==0 && j!=sk){
				goleft();
			}
			else if (i!=r &&i % 2 == 1 && j == sk) {
				goright();
				godown();
			}
			else if (i!=r&&i % 2 == 0 && j == sk) {
				goleft();
				godown();
			}
			else if (i == r &&i % 2 == 1) {
				goright();
			}
			else if (i == r&& i % 2 == 0) {
				goleft();
			}
		}
	}
	printf("%lld\n", hab);
	return 0;
}