#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Trie {
	Trie* tree[10];
	bool finish;
	bool cur;
	Trie() {
		fill(tree, tree + 10, nullptr);
		finish = false,cur=false;
	}
	~Trie() {
		for (int i = 0; i < 10; i++) if (tree[i]) delete tree[i];
	}

	void insert(char *key) {
		if (*key == NULL) {
			finish = true;
			return;
		}
		else {
			int next = *key - '0';
			if (!tree[next]) tree[next] = new Trie;
			cur = true;
			tree[next]->insert(key + 1);
		}
	}

	bool check() {
		if (finish && cur) return true;
		for (int i = 0; i < 10; i++) {
			if (tree[i]) {
				if (tree[i]->check()) return true;
			}
		}
		return false;
	}
};
char s[10001][11];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		Trie* trie = new Trie;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", s[i]);
			trie->insert(s[i]);
		}
		int no = 0;
		if (trie->check()) printf("NO\n");
		else printf("YES\n");
		delete trie;
	}
	return 0;
}