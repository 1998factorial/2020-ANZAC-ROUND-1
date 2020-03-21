#include <bits/stdc++.h>
#define int int64_t
#define ii pair<int, int>
using namespace std;

void print_vector(vector<ii>& v) {
  int size = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second != 0) size += 1;
  }
  cout << size << " ";
  for (auto [a, b] : v) {
    if (b >= 1) cout << a << " ";
    if (b <= -1) cout << "-" << a << " ";
  }
  cout << endl;
}

int n, k, m, x;
vector<ii> a;
vector<ii> b;

int cap(int x) {
  if (x > 1) x = 1;
  if (x < -1) x = -1;
  return x;
}

void perform_add() {
  vector<ii> result;
  int ia = 0;
  int ib = 0;
  while (ia < a.size() && ib < b.size()) {
    if (a[ia].first == b[ib].first) {
      // add the two together
      result.push_back(make_pair(a[ia].first, cap(a[ia].second+b[ib].second)));
      ia += 1;
      ib += 1;
    } else if (a[ia].first <= b[ib].first) {
      result.push_back(make_pair(a[ia].first, a[ia].second));
      ia += 1;
    } else {
      result.push_back(make_pair(b[ib].first, b[ib].second));
      ib += 1;
    }
  }
  while (ia < a.size()) {
    result.push_back(make_pair(a[ia].first, a[ia].second));
    ia += 1;
  }
  while (ib < b.size()) {
    result.push_back(make_pair(b[ib].first, b[ib].second));
    ib += 1;
  }
  print_vector(result);
}

void perform_mult() {
  vector<ii> result;
  int ia = 0;
  int ib = 0;
  while (ia < a.size() && ib < b.size()) {
    if (a[ia].first == b[ib].first) {
      // multiply the two together
      result.push_back(make_pair(a[ia].first, cap(a[ia].second*b[ib].second)));
      ia += 1;
      ib += 1;
    } else if (a[ia].first <= b[ib].first) {
      result.push_back(make_pair(a[ia].first, a[ia].second*0));
      ia += 1;
    } else {
      result.push_back(make_pair(b[ib].first, b[ib].second*0));
      ib += 1;
    }
  }
  while (ia < a.size()) {
    result.push_back(make_pair(a[ia].first, a[ia].second*0));
    ia += 1;
  }
  while (ib < b.size()) {
    result.push_back(make_pair(b[ib].first, b[ib].second*0));
    ib += 1;
  }
  print_vector(result);
}

void perform_rotate(vector<ii> v) {
  vector<ii> result;
  for (auto [a, b] : v) {
    int pos = a;
    pos -= k;
    if (pos < 1) pos += n;
    result.push_back(make_pair(pos, b));
  }
  sort(result.begin(), result.end());
  print_vector(result);
}

signed main() {
  cin >> n >> k;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    if (x > 0) a.push_back(make_pair(x, 1));
    if (x < 0) a.push_back(make_pair(-x, -1));
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    if (x > 0) b.push_back(make_pair(x, 1));
    if (x < 0) b.push_back(make_pair(-x, -1));
  }

  // perform add
  // vector<ii> add_result;
  // print_vector(a);
  // print_vector(b);
  perform_add();
  perform_mult();
  perform_rotate(a);
  perform_rotate(b);
}
