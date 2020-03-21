#include <bits/stdc++.h>
#define STATES 512
#define MAXN 6
using namespace std;

double dp[STATES];
bool seen[STATES];
double calc(int state, int a, int b) {
  // only uses values of dp, doesn't change it
  int sum = a + b;
  for (int shift = 0; shift < 9; shift++) {
    // WARNING: shift is 1 less than the actual digit
    if (state & (1<<shift)) digits.push_back(shift+1);
  }

  for (int crossout = 1; crossout < STATES; crossout++) {
    // brute force which digits to cross out
    // must all exist in state firsts
    if (crossout & state != crossout) continue;
    int cosum = 0;
    for (int shift = 0; shift < 9; shift++) {
      if (crossout & (1<<shift)) {
        cosum += 
      }
    }

    // is a valid crossout
    if (cosum == sum) {
      int next = sum ^ cosum;
    }
  }

  // find which digits sum up to sum

}

double calc_all(int state) {
  // calculates all dice rolls and cascades down
  // sets the value of dp
  if (seen[states]) return dp[state];
  dp[state] = 0;
  seen[state] = true;
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      dp[state] += (1.0/36) * calc(state, i, j);
    }
  }
  return dp[state];
}

int main() {
  string d;
  int a, b;
  cin >> d >> a >> b;

  int start = 0;
  for (int i = 0; i < d.length(); i++) {
    // WARNING: shift is 1 less than the actual digit
    int shift = (d[i] - '0') - 1;
    start |= (1 << shift);
  }
  cout << calc(start, a, b) << endl;
}
