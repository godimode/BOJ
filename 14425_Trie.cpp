#include <stdio.h>
#define MAX 20001
#define MAXSTR 500

struct Node {
	int end;
	int next[26];
};

Node trie[MAXSTR * MAX];
char s[501];
int idx;

void insert(char key[]) {
	int cur = 0;
	for (int i = 0; key[i]; i++) {
		int next = key[i] - 'a';
		if (trie[cur].next[next] == 0) trie[cur].next[next] = ++idx;
		cur = trie[cur].next[next];
	}
	trie[cur].end++;
}
int find(char key[]) {
	int cur = 0;
	for (int i = 0; key[i]; i++) {
		int next = key[i] - 'a';
		if (trie[cur].next[next] == 0) return 0;
		cur = trie[cur].next[next];
	}
	if (trie[cur].end) return 1;
	return 0;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		insert(s);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		scanf("%s", s);
		if (find(s)) ans++;
	}
	printf("%d", ans);
}