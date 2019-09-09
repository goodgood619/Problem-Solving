#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Trie {
	Trie* tree[26];
	bool finish;
	Trie() {
		fill(tree, tree + 26, nullptr);
		finish = false;
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
			int next = *key - 'a';
			if (!tree[next]) tree[next] = new Trie;
			tree[next]->insert(key + 1);
		}
	}

	bool check(char *key) {
		if (*key == NULL && finish) return true;
		else if (*key == NULL && !finish) return false;
		if (tree[*key - 'a'] && tree[*key - 'a']->check(key + 1)) return true;
		else return false;
	}
};
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Trie* trie = new Trie;
	for (int i = 0; i < n; i++) {
		char s[502] = { '\0', };
		scanf("%s", s);
		trie->insert(s);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		char s[502] = { '\0', };
		scanf("%s", s);
		if (trie->check(s)) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}