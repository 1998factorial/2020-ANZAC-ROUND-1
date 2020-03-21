#include <bits/stdc++.h>

using namespace std;
int a[1011];

int main() {
	int i, n, s;
	int t;
	scanf("%d%d", &n, &s);
	for (i = 0 ; i < n; ++i) scanf("%d", &a[i]);
	t = a[0];
	for (i = 0; i < n; ++i) {
		t = max(t, a[i]);
	}
	
	for (i = t * s; i <= 2000 * 40; i++) {
		if (i % 1000 == 0) {
			printf("%d\n", i/1000);
			break;
		}
	}
	return 0;
}