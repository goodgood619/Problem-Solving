#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int total;
char temp[32];
struct Trie {
	Trie* tree[128];
	bool finish;
	int cnt;
	Trie() {
		fill(tree, tree + 128, nullptr);
		finish = false;
		cnt = 0;
	}
	~Trie() {
		for (int i = 0; i < 128; i++) if (tree[i]) delete tree[i];
	}

	void insert(char *key) {
		if (*key == NULL) {
			finish = true;
			cnt++;
			return;
		}
		else {
			int next = *key - ' ';
			if (!tree[next]) tree[next] = new Trie;
			tree[next]->insert(key + 1);
		}
	}

	void check(int idx) {
		if (finish) {
			temp[idx] = '\0';
			printf("%s %.4lf\n", temp, (double)cnt / total * 100);
		}
		for (int i = 0; i < 128; i++) {
			if (tree[i]) {
				temp[idx] = i + ' ';
				tree[i]->check(idx+1);
				temp[idx] = '\0';
			}
		}
	}
};
int main() {
	Trie* trie = new Trie;
	char s[32] = { '\0', };
	while (scanf(" %[^\n]s",s)!=EOF) {
		trie->insert(s);
		total++;
	}
	trie->check(0);
	return 0;
}