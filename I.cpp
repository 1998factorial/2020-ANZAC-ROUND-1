#include <bits/stdc++.h>

using namespace std;

int a[1011][1011];
int v[1011][1011];
int n, m;

int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			if (i > 1 && i < n && j > 1 && j < m) {
				if (a[i][j] < a[i+1][j] && a[i][j] < a[i-1][j] && a[i][j] < a[i][j+1] && a[i][j] < a[i][j-1]) {
					v[i][j] = 1;
				}
			}
		}
	}
	
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	return 0;
}