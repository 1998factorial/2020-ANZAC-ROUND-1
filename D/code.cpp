#include <bits/stdc++.h>
#define STATES 1679616
#define INF STATES*2
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

void rot(string& str, int pos) {
  str[pos] = 'A' + ((str[pos] - 'A' + 1) % MAXV);
}

void calculate_edges(int at) {
  if (edge[at].size()) return;

  string original_str = "AAAAAAAA";
  int v = at;
  for (int i = MAXN-1; i >= 0; i--) {
    original_str[i] = (v % MAXV) + 'A';
    v = v / MAXV;
  }

  for (int i = 0; i < MAXN; i++) {
    string str = original_str;
    switch (original_str[i]) {
      case 'A':
        if (i != 0) rot(str, i-1);
        if (i != MAXN-1) rot(str, i+1);
        break;
      case 'B':
        if (i != 0 && i != MAXN-1) str[i+1] = str[i-1];
        break;
      case 'C':
        rot(str, 7-i);
        break;
      case 'D':
        if (i <= 3) {
          for (int j = 0; j < i; j++) rot(str, j);
        } else {
          for (int j = i+1; j < MAXN; j++) rot(str, j);
        }
        break;
      case 'E':
        if (i != 0 && i != MAXN-1) {
          if (i <= 3) {
            int dist = i;
            rot(str, 0);
            rot(str, i+dist);
          } else {
            int dist = MAXN-1-i;
            rot(str, MAXN-1);
            rot(str, i-dist);
          }
        }
        break;
      case 'F':
        if ((i+1) % 2 == 0) rot(str, ((i+1)/2)-1);
        else rot(str, (((i+1)+9)/2)-1);
        break;
    }
    edge[at].push_back(str2int(str));
  }
  // cout << edge[at].size() << endl;
}

string s;
string t;
int main() {
  cin >> s >> t;
  int sn = str2int(s);
  int tn = str2int(t);
  fill(dist, dist+STATES, INF);

  deque<int> q;
  q.push_back(sn);
  dist[sn] = 0;

  for (int i = 0; i < STATES; i++) {
    calculate_edges(i);
  }

  while (q.size()) {
    int at = q.front();
    q.pop_front();

    if (at == tn) {
      cout << dist[at] << endl;
      return 0;
    }

    for (int next : edge[at]) {
      if (dist[next] == INF) {
        dist[next] = dist[at] + 1;
        q.push_back(next);
      }
    }
  }

  cout << -1 << endl;
}
