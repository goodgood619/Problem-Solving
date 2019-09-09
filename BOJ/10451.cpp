#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector <vector<int>> a;
bool visited[1001];
int cnt=0;
void dfs(int now){
	visited[now]=true;
	for(int i=0;i<a[now].size();i++){
	int next=a[now][i];
	if(!visited[next]) dfs(next);
	}
}
int main(){
	int n,m;
	scanf("%d",&n);
	while(n--){
	a.clear();
	cnt=0;
	scanf("%d",&m);
	a.resize(m+1);
	for(int i=1;i<=m;i++){
	int u;
	scanf("%d",&u);
	a[i].push_back(u);
	visited[i]=false;
	}
	for(int i=1;i<=m;i++)
	{
		if(!visited[i])
		{
			dfs(i);
			cnt++;
		}
		else continue;
	}
	printf("%d\n",cnt);
	memset(visited,false,sizeof(visited));
	}
	return 0;
}	