#include <stdio.h>
char map[555][555];
int ck[555][555];
int n, m, k;
// U R D L 
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void clear() {
	for (int i = 0; i < 555; i++)
		for (int j = 0; j < 555; j++)
			ck[i][j] = 0;
}
char _change(int i) {
	switch (i) {
	case 0:
		return 'U';
	case 1:
		return 'R';
	case 2:
		return 'D';
	case 3:
		return 'L';
	}
}

void move(int stx, int sty, int dir) {
	if (stx + dx[dir] < 0 || stx + dx[dir] >= n || sty + dy[dir] < 0 || sty + dy[dir] >= m) return;
	if (ck[stx + dx[dir]][sty + dy[dir]]) {
		return;
	}
	ck[stx + dx[dir]][sty + dy[dir]]++;
	k++;
	switch (map[stx + dx[dir]][sty + dy[dir]]) {
	case '.':
		move(stx + dx[dir], sty + dy[dir], dir);
		break;
	case '/':
		dir % 2 ? dir -= 1 : dir += 1;
		move(stx + mx, sty + my, )
	case '\\':
	case 'C':

	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %1c", &map[i][j]);
	int x, y;
	scanf("%d %d", &x, &y);
	int max = -1;
	char maxChar;
	for (int i = 0; i < 4; i++) {
		clear();
		k = 0;
		move(x, y, dx[i], dy[i]);
		if (max < k) {
			maxChar = _change(i);
			max = k;
		}
	}
}