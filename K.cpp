#include <bits/stdc++.h>
#define MAX_SIZE 1011
using namespace std;

vector<pair<int, int>> p;
int valid = -1;

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		p.emplace_back(l, r);
	}
	
	for (i = 0; i <= n; ++i) {
		int cnt = 0;
		for (auto pp : p) {
			if (pp.first <= i && i <= pp.second) cnt++;
		}
		if (cnt == i) valid = i;
	}
	printf("%d\n", valid);
	return 0;
}