#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int sum=0;
	int p=1;
	while(1){
		sum+=p;
		if(sum>=n){
			break;
		}
		p++;
	}
	if(p%2==0){
		int a=p;
		int b=1;
	while(1){
		if(sum==n){
			printf("%d/%d\n",a,b);
			break;
		}
		sum--;
		a--;
		b++;

	}
	}
	else{
		int a=1;
		int b=p;
	while(1){
		if(sum==n){
			printf("%d/%d\n",a,b);
			break;
		}
		sum--;
		a++;
		b--;

	}
	}
	return 0;
}