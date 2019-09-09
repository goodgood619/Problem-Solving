#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char c[258];
int happy, sad;
int main(){
	scanf("%[^\n]s", c);
	int length = strlen(c);
	for (int i = 0; i < length;) {
		if (c[i] == ':' && c[i + 1] == '-' && c[i + 2] == ')') {
			happy++;
			i += 3;
		}
		else if (c[i] == ':' && c[i + 1] == '-' && c[i + 2] == '(') {
			sad++;
			i += 3;
		}
		else i++;
	}
	if (happy == 0 && sad == 0) { printf("none\n");}
	else if (happy == sad) { printf("unsure\n");}
	else if (happy > sad) { printf("happy\n");}
	else if (happy < sad) { printf("sad\n");}
	return 0;
}