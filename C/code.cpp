#include <bits/stdc++.h>
#define MAXV 1000005
using namespace std;

bool isprime[MAXV];
int x;
int main() {
  fill(isprime, isprime+MAXV, true);
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 2; i*i < MAXV; i++) {
    if (isprime[i]) {
      for (int j = i; i*j < MAXV; j++) {
        isprime[i*j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 0; i < MAXV; i++) {
    if (isprime[i]) primes.push_back(i);
  }

  cin >> x;
  int answer = 0;
  while (x != 0 && x != 2) {
    answer += 1;
    int rhs = primes.size()-1;
    for (int i = 0; i < primes.size(); i++) {
      while (primes[i] + primes[rhs] > x) rhs -= 1;
      if (primes[i] + primes[rhs] == x) {
        x = primes[rhs] - primes[i];
        break;
      }
    }
  }
  cout << answer << endl;
}
