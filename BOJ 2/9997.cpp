#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>
using namespace std;
typedef pair<int,pair <int, int>> PP;
typedef pair<int,int> P;
int n,ans,all;
int check[26];
typedef long long ll;
void go(int index,int sum){
	if(index>n) return;
	if(index==n){
		if(sum==all){
			ans++;
		}
		return;
	}
	go(index+1,sum|check[index]);
	go(index+1,sum);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int length=s.size();
		int sum=0;
		for(int j=0;j<length;j++){
			sum|=(1<<(s[j]-'a'));
		}
		check[i]=sum;
	}
	all=(1<<26)-1;
	go(0,0);
	printf("%d\n",ans);
	return 0;
}