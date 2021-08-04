#include <stdio.h>
struct A {
	int x, y;
}q[1005*1005];
int map[1005][1005];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	int cnt = 0;
	if ((n + m) % 2) {
		for (int i = 0; i < n; i++) {
			q[++cnt].x = i;
			q[cnt].y = 0;
		}
		for (int i = 1; i < m; i++) {
			q[++cnt].x = n - 1;
			q[cnt].y = i;
		}
	}
	else {
		if (n % 2 == 0) {
			if (n < m) {
				for (int i = 0; i < n / 2 * 2; i++) {
					q[++cnt].x = i;
					q[cnt].y = i;
				}
				for (int i = n; i < m; i++) {
					q[++cnt].x = n - 1;
					q[cnt].y = i;
				}
			}
			else {
				for (int i = 0; i < m / 2 * 2; i++) {
					q[++cnt].x = i;
					q[cnt].y = i;
				}
				for (int i = m; i < n; i++) {
					q[++cnt].x = i;
					q[cnt].y = m - 1;
				}
			}
		}
		else {
			if (n < m) {
				for (int i = 0; i < n / 2 * 2; i++) {
					q[++cnt].x = i;
					q[cnt].y = i;
				}
				for (int i = n / 2 * 2 - 1; i < m; i++) {
					q[++cnt].x = n / 2 * 2;
					q[cnt].y = i;
				}
			}
			else {
				for (int i = 0; i < m / 2 * 2; i++) {
					q[++cnt].x = i;
					q[cnt].y = i;
				}
				for (int i = m / 2 * 2 - 1; i < n; i++) {
					q[++cnt].x = i;
					q[cnt].y = m / 2 * 2;
				}
			}
		}
	}
	printf("%d\n", 2*cnt);
	for (int i = 1; i <= cnt; i += 2) {
		printf("%d %d\n", q[i].x, q[i].y);
		printf("%d %d\n", q[i + 1].x, q[i + 1].y);
		printf("%d %d\n", q[i].x, q[i].y);
		printf("%d %d\n", q[i + 1].x, q[i + 1].y);
	}
}