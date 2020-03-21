#include <bits/stdc++.h>
#define STATES 1679616
#define MAXN 8
#define MAXV 6
using namespace std;

int str2int(string& str) {
  int result = 0;
  for (int i = 0; i < str.length(); i++) {
    result *= MAXV;
    result += (str[i] - 'A');
  }
  return result;
}

int dist[STATES];
vector<int> edge[STATES];

void calculate_edges(int at) {
  if (edge[at]) return;
  int str[8];
  int v = at;
  for (int i = MAXN-1; i >= 0; i--) {
    str[i] = v % MAXV;
    v = v / MAXV;
  }

  for (int i = 0; i < 8; i++) {
    if (str[i] == 'A') {

    }
  }

  // operation A
  // operation B
  // operation C
  // operation D
  // operation E
  // operation F
}

string s;
string t;
int main() {
  cin >> s >> t;
  int sn = str2int(s);
  int tn = str2int(t);
}