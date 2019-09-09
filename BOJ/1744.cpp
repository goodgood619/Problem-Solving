#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
typedef long long ll;
vector<int> v;
vector<int> Plus,Minus;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int zero = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 0) Minus.push_back(v[i]);
		else if (v[i] > 0) Plus.push_back(v[i]);
		else {
			zero++;
		}
	}
	int sum = 0;
	for (int i = Plus.size() - 1; i >= 0;){
		int back = i - 1;
		if (back < 0) {
			sum += Plus[i];
		}
		else {
			if (Plus[back] == 1) {
				sum += Plus[i];
				sum += Plus[back];
			}
			else {
				sum += (Plus[i] * Plus[back]);
			}
		}
		i -= 2;
	}
	for (int i = 0; i < Minus.size();){
		int next = i + 1;
		if (next <= Minus.size() - 1) {
			sum += (Minus[i] * Minus[next]);
		}
		else{
			if (zero == 0) {
				sum += Minus[i];
			}
		}
		i += 2;
	}
	printf("%d\n", sum);
	return 0;
}