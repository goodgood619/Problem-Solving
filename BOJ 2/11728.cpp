#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> a;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		a.push_back(num);
	}
	for(int i=1;i<=m;i++){
		int num;
		scanf("%d",&num);
		a.push_back(num);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		printf("%d ",a[i]);
	}
	return 0;
}