#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
char s[101];
int cnt;
bool visited[101];
string croa[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
int main(){
	scanf("%s", s);
	int length=strlen(s);
	for (int i = 0;i<length; i++){
		if (visited[i]) continue;
		bool check = false;
		for (int j = 0; j < 8; j++) {
			if (j == 2) {
				string cro = croa[j];
				if (s[i] == cro[0] && s[i + 1] == cro[1] && s[i + 2] == cro[2]){
					visited[i] = true;
					visited[i + 1] = true;
					visited[i + 2] = true;
					cnt++;
					check = true;
					break;
				}
			}
			else {
				string cro = croa[j];
				if (s[i] == cro[0] && s[i + 1] == cro[1]){
					visited[i] = true;
					visited[i + 1] = true;
					cnt++;
					check = true;
					break;
				}
			}
		}
		if (!check){
			visited[i] = true;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}