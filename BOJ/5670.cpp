#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int ret;
struct Trie {
	Trie* tree[26];
	bool finish;
	int cnt;
	Trie() {
		fill(tree, tree +26, nullptr);
		finish = false;
		cnt = 0;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (tree[i]) delete tree[i];
	}

	void insert(char *key) {
		if (*key == NULL) {
			finish = true;
			return;
		}
		else {
			int next = *key - 'a';
			if (!tree[next]) {
				tree[next] = new Trie;
				cnt++;
			}
			tree[next]->insert(key + 1);
		}
	}
	int check(char *key) {
		if (*key == NULL) {
			return ret;
		}
		else {
			if (cnt >= 2 || finish) ret++;
			return tree[*key - 'a']->check(key + 1);
		}
	}
};

char s[100001][82];
int main() {
	int n;
	while (scanf(" %d",&n)!=EOF) {
		Trie* trie = new Trie;
		for (int i = 0; i < n; i++) {
			scanf("%s", s[i]);
			trie->insert(s[i]);
		}

		int total = 0;
		if (trie->cnt == 1) total += n;
		for (int i = 0; i < n; i++) {
			ret = 0;
			total += trie->check(s[i]);
		}
		printf("%.2lf\n", (double)(total) / n);
		delete trie;
	}
	return 0;
}