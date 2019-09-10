#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
typedef pair <int, int> P;
P quest[200];
int n, m,Size;
int k = 1;
char s[15];
int main(){
	scanf("%d%d", &n, &m);
	while (n--) {
		scanf("%s", s);
		if (!strcmp(s, "order")) {
			int table, time;
			scanf("%d%d", &table, &time);
			quest[k].first = time;
			quest[k].second = table;
			k++;
			Size++;
			for (int i = 1; i < k; i++){
				if (quest[i].second == -1) continue;
				else printf("%d ", quest[i].second);
			}
			printf("\n");
		}
		else if (!strcmp(s, "sort")) {
			sort(quest + 1, quest + k);
			if (Size <= 0) { printf("sleep\n");}
			else {
				for (int i = 1; i < k; i++) {
					if (quest[i].second == -1) continue;
					else printf("%d ", quest[i].second);
				}
				printf("\n");
			}
		}
		else if (!strcmp(s, "complete")) {
			int num;
			scanf("%d", &num);
				for (int i = 1; i < k; i++) {
					if (quest[i].second == num) {
						quest[i].second = -1;
						Size--;
						break;
					}
					else continue;
				}
				if (Size<=0) printf("sleep\n");
				else {
					for (int i = 1; i < k; i++) {
						if (quest[i].second == -1) continue;
						else printf("%d ", quest[i].second);
					}
					printf("\n");
				}
		}
	}
	return 0;
}