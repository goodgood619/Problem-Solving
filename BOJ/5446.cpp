#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int cnt;
struct Trie {
	Trie* tree[80];
	bool finish;
	bool del;
	Trie() {
		fill(tree, tree + 80, nullptr);
		finish = false, del = false;
	}
	~Trie() {
		for (int i = 0; i<80; i++) {
			if (tree[i]) delete tree[i];
		}
	}

	void insert(char *key,bool c) {
		if (*key == NULL) {
			finish = c;
			del = c;
			return;
		}
		else {
			int next = *key-'.';
			if (!tree[next]) {
				tree[next] = new Trie;
			}
			del = c;
			tree[next]->insert(key + 1,c);
		}
	}


	void check() {
		if (del) {
			cnt++;
			return;
		}
		else if (finish) {
			cnt++;
		}
		for (int i = 0; i < 80; i++) {
			if (tree[i]) tree[i]->check();
		}
	}
};
int main() {
	int n,m,t;
	scanf(" %d", &t);
	while (t--) {
		scanf(" %d", &n);
			Trie* trie = new Trie();
			cnt = 0;
			for (int i = 0; i < n; i++) { //지워도 됨
				char s[21] = {'\0',};
				scanf(" %s", s);
				trie->insert(s,true);
			}
			scanf(" %d", &m);
			for (int i = 0; i < m; i++) { //지우면 안됨
				char s[21] = { '\0', };
				scanf(" %s", s);
				trie->insert(s, false);
			}
			trie->check();
			printf("%d\n", cnt);
			delete trie;
	}
	return 0;
}