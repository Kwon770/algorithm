#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int graph[1001][1001], dv[1001], bv[1001], q[1001];

void dfs(int v, int n) {
	dv[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= n; i++) {
		if (graph[v][i] && !dv[i]) dfs(i, n);
	}
}

void bfs(int v, int n) {
	int f = 0, r = 0, pop;

	printf("%d ", v);
	q[0] = v;
	r++;
	bv[v] = 1;
	while (f < v) {
		pop = q[f];
		f++;

		for (int i = 1; i <= n; i++) {
			if (graph[pop][i] && !bv[i]) {
				printf("%d ", i);
				bv[i] = 1;
				q[r] = i;
				r++;
			}
		}
	}
}

void n1260() {
	int n, m, v, a, b;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(v, n);
	printf("\n");
	bfs(v, n);
}