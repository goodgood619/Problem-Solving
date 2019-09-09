#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <climits>
#include <functional>
#include <list>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int isprime[2000000];
void go() {
	for (int i = 2; i <= sqrt(2000000); i++){
		if (isprime[i] == 0) continue;
		for (int j = i*i; j <= 2000000; j += i) {
			isprime[j] = 0;
		}
	}

}
int main(){
	for (int i = 2; i <= 2000000;i++) isprime[i]=i;
    go();
    int n;
    scanf("%d",&n);
    for(int i=n;;i++){
        if(isprime[i]==0) continue;
        else{
            vector<char> ans;
            int temp=i;
            bool no=false;
            while(temp>=1){
                ans.push_back(temp%10+'0');
                temp/=10;
            }
            reverse(ans.begin(),ans.end());
            for(int i=0;i<ans.size()/2;i++){
                if(ans[i]==ans[ans.size()-1-i]) continue;
                else{
                    no=true;
                    break;
                }
            }
        if(!no){
            printf("%d\n",i);
            return 0;
        }
        }
    }

	return 0;
}
