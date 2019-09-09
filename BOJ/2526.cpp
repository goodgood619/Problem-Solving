#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, p;
bool visited[1000005];
vector<int> a;
int main(){
	scanf("%d%d", &n, &p);
	visited[n] = true;
	int temp = n;
	int cnt = 0;
	a.push_back(n);
	while (1){
		temp = (temp*n) % p;
		if (visited[temp]){
			a.push_back(temp);
			break;
		}
		else {
			visited[temp] = true;
			a.push_back(temp);
		}
	}
	int la = a[a.size() - 1];
	for (int i = a.size() - 2; i >= 0; i--) {
		if (la == a[i]) break;
		else cnt++;
	}
	printf("%d\n", cnt+1);
	return 0;
}