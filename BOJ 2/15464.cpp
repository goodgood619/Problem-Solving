#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
typedef pair<int, int> P;
int pos[105];
int id[105];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		pos[i] = num;
	}
	for (int i = 1; i <= n; i++) {
		int idnum;
		scanf("%d", &idnum);
		id[pos[i]] = idnum;
	}
	vector<int> temp;
	temp.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		temp[i] = pos[i];
	}
	for (int i = 0; i < 3; i++){
		for (int j = 1; j <= n; j++){
			int here = temp[j];
			temp[j] = pos[here];
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", id[temp[i]]);
	}
	return 0;
}