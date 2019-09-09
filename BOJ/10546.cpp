#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
map<string,int> m;
int n;
int main() {
	// your code goes here
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c[25]={'\0',};
		scanf("%s",c);
		string s=c;
		m[s]++;
	}
	for(int i=1;i<=n-1;i++){
		char c[25]={'\0',};
		scanf("%s",c);
		string s=c;
		m[s]--;
	}
	map<string,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		if(it->second==0) continue;
		else printf("%s",it->first.c_str());
	}
	return 0;
}