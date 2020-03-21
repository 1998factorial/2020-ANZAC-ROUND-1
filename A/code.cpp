#include <bits/stdc++.h>
using namespace std;

int n;
string s1;
string s2;
int main() {
  cin >> n >> s1 >> s2;
  int same = 0;
  int diff = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == s2[i]) same++;
    else diff++;
  }

  int answer = min(same, n) + min(((int) s1.length())-n, diff);
  cout << answer << endl;
}
