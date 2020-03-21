#include <bits/stdc++.h>
#define STATES 512
#define MAXN 6
#define INF 223456789.0
using namespace std;

double dp[STATES];
bool seen[STATES];
bool is_max = true;

void print_state(int state) {
  if (state == 0) cout << -1;
  else {
    for (int shift = 0; shift < 9; shift++) {
      // WARNING: shift is 1 less than the actual digit
      if (state & (1<<shift)) {
        cout << (shift+1);
      }
    }
  }
}

double calc_all(int state);
pair<double, int> calc(int state, int a, int b) {
  // only uses values of dp, doesn't change it
  if (state == 0) return make_pair(0, 0);
  int sum = a + b;
  double best_crossout = -1;
  if (!is_max) {
    best_crossout = INF+1;
  }
  int best_crossout_set = 0;
  for(int crossout = state; crossout; crossout = (crossout - 1) & state){
    // brute force which digits to cross out
    // must all exist in state firsts
    int cosum = 0;
    for (int shift = 0; shift < 9; shift++) {
      if (crossout & (1<<shift)) {
        cosum += (shift+1);
      }
    }

    // is a valid crossout
    // remove the digits
    // add the score of next
    if (cosum == sum) {
      int next = state ^ crossout;
      double score = calc_all(next);
      if (is_max) {
        if (score > best_crossout) {
          best_crossout = score;
          best_crossout_set = crossout;
        }
      } else {
        if (score < best_crossout) {
          best_crossout = score;
          best_crossout_set = crossout;
        }
      }
    }
  }

  if (best_crossout < -0.5 || best_crossout > INF) {
    int answer = 0;
    for (int shift = 0; shift < 9; shift++) {
      // WARNING: shift is 1 less than the actual digit
      if (state & (1<<shift)) {
        answer *= 10;
        answer += (shift+1);
      }
    }
    return make_pair(answer, 0);
  } else {
    return make_pair(best_crossout, best_crossout_set);
  }
}

double calc_all(int state) {
  // calculates all dice rolls and cascades down
  // sets the value of dp
  if (seen[state]) return dp[state];
  dp[state] = 0;
  seen[state] = true;
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      dp[state] += (1.0/36) * calc(state, i, j).first;
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

  memset(dp, 0, STATES);
  memset(seen, 0, STATES);
  is_max = false;
  pair<double, int> best_min = calc(start, a, b);
  print_state(best_min.second);
  printf(" %.5lf\n", best_min.first);

  memset(dp, 0, STATES);
  memset(seen, 0, STATES);
  is_max = true;
  pair<double, int> best_max = calc(start, a, b);
  print_state(best_max.second);
  printf(" %.5lf\n", best_max.first);
}
