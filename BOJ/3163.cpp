#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
typedef pair<int, int> P;
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		int n,l,k;
		vector<P> ant;
		deque<int> listid;
		vector<int> temp;
		map<int, int> m;
		scanf("%d%d%d", &n,&l,&k);
		for (int i = 1; i <= n; i++){
			int meter, id;
			scanf("%d%d", &meter, &id);
			listid.push_back(id);
			if (id > 0) {
				ant.push_back({ l - meter,id });
			}
			else{
				ant.push_back({ meter,id });
			}
		}
		sort(ant.begin(), ant.end());
		for (int i = 0; i < ant.size(); i++){
			int frontid = listid.front();
			int backid = listid.back();
			if (i !=ant.size()-1 &&ant[i].first == ant[i + 1].first){
				if (frontid<backid) {
					temp.push_back(frontid);
					temp.push_back(backid);
				}
				else {
					temp.push_back(backid);
					temp.push_back(frontid);
				}
				listid.pop_front();
				listid.pop_back();
				i++;
			}
			else{
				if (ant[i].second < 0) {
					temp.push_back(frontid);
					listid.pop_front();
				}
				else {
					temp.push_back(backid);
					listid.pop_back();
				}
			}
		}
		printf("%d\n", temp[k - 1]);
	}
	return 0;
}