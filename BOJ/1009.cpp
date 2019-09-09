#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
bool visited[120];
int ans[150];
int main(){
	scanf("%d", &t);
	while (t--){
		memset(visited, false, sizeof(visited));
		memset(ans, 0, sizeof(ans));
		int k = 0;
	int a, b;
		scanf("%d%d",&a,&b);
		if (a == 1) {
			printf("1\n");
		}
		else{
			visited[(a%10)] = true;
			if (a % 10 == 0) { ans[k++] = 10;}
			else ans[k++] = (a%10);
			int p = (a % 10);
			int cnt = 0;
			while (1){
				long long temp = (a*p) % 10;
				if (!visited[temp]){
					if (temp == 0) { ans[k++] = 10;}
					else ans[k++] = temp;
					a = temp;
					cnt++;
				}
				else {
					break;
				}
				if (cnt >= b) break;
			}
			printf("%d\n",ans[(b - 1) % k]);
		}
	}
	return 0;
}