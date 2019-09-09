#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
int n;
vector<int> v;
int main(){
	scanf("%d",&n);
	if(n==0){
		printf("0\n");
		return 0;
	}
	int p=n;
	while(p!=0){
		int mod=p%(-2);
		int ahr=p/(-2);
		if(mod<0){
			mod=1;
			ahr++;
		}
		v.push_back(mod);
		p=ahr;
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		printf("%d",v[i]);
	}
	return 0;
}