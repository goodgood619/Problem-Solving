#include <stdio.h>
#include <algorithm>
using namespace std;
int dwarf[11];
bool visited[11];
bool real[11];
bool check;
void go(int index, int cnt){
	if (check) return;
	if (index > 9) return;
	if (cnt == 7){
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			if (visited[i]) sum += dwarf[i];
		}
		if (sum == 100) {
			check = true;
			for (int i = 0; i < 9; i++) {
				if (visited[i]) real[i] = true;
			}
			return;
		}
		return;
	}
	visited[index] = true;
	go(index + 1, cnt + 1);
	visited[index] = false;
	go(index + 1, cnt);
	return;
}
int main(){
	for(int i=0;i<9;i++) scanf("%d", &dwarf[i]);
	go(0, 0);
	for (int i = 0; i < 9; i++) {
		if (real[i]) {
			printf("%d\n", dwarf[i]);
		}
	}
	return 0;
}