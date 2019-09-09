#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <math.h>
#include <map>
typedef long long ll;
using namespace std;
vector<ll> seg;
int h=1;
int n,m;
void update(int index,ll value){
	index+=h-1;
	seg[index]+=value;
	while(index>1){
		index/=2;
		seg[index]=seg[index*2]+seg[index*2+1];
	}
}
ll query(int nodenum,int left,int right,int nodeleft,int noderight){
	if(noderight<left || nodeleft>right) return 0;
	else if(left<=nodeleft && noderight<=right) return seg[nodenum];
	int mid=(nodeleft+noderight)/2;
	return query(nodenum*2,left,right,nodeleft,mid)+query(nodenum*2+1,left,right,mid+1,noderight);
}
int main(){
	// your code goes here
	scanf("%d%d",&n,&m);
	while(h<n)h*=2;
	seg.resize(h*2);
	for(int i=1;i<=m;i++){
		int what;
		scanf("%d",&what);
		if(what==1){
			int index;
			ll value;
			scanf("%d%lld",&index,&value);
			update(index,value);
		}
		else{
			int left,right;
			scanf("%d%d",&left,&right);
			printf("%lld\n",query(1,left,right,1,h));
		}
	}
 
	return 0;
}