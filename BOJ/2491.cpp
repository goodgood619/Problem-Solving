#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int arr[100005];
int n;
int main(){
	scanf("%d",&n);
	// your code goes here
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	// 증가하는 거 찾기
	int ans=1;
	int cnt=1;
	for(int i=1;i<=n-1;i++){
		int here=arr[i];
		int next=arr[i+1];
		if(here<=next){
			cnt++;
			ans=max(cnt,ans);
		}
		else cnt=1;
	}
	cnt=1;
	for(int i=n;i>=2;i--){
		int here=arr[i];
		int next=arr[i-1];
		if(here<=next){
			cnt++;
			ans=max(cnt,ans);
		}
		else cnt=1;
	}
	printf("%d\n",ans);
	return 0;
}