#include <bits/stdc++.h>
#define MAXV 1000005
using namespace std;

bool isprime[MAXV];
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

  cout << primes.size() << endl;
}
