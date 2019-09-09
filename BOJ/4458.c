#include <stdio.h>
int t;
int main(){
	scanf("%d ", &t);
	while (t--){
		char c[35] = {'\0',};
		gets(c);
		if(c[0]>=97) c[0]-=32;
		printf("%s\n", c);
	}
	return 0;
}