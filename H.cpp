#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<int , int> ii;

const int maxn = 1e3 + 10;
int N , S;
char a[maxn][maxn];
int cnt[maxn][maxn];
int ans[10005];

int main(){
  scanf("%d %d" , &N , &S);
  for(int i = 1; i <= N; ++i){
    for(int j = 1; j <= N; ++j){
      cin >> a[i][j];
    }
  }
  for(int i = 1; i <= N; ++i){
    for(int j = 1; j <= N; ++j){
      cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + (a[i][j] == 'D');
    }
  }
  for(int i = 1; i + S - 1 <= N; ++i){
    for(int j = 1; j + S - 1 <= N; ++j){
      int val = cnt[i + S - 1][j + S - 1];
      //printf("(%d %d %d %d) = %d\n" , i , j , i + S - 1 , j + S - 1 , val);
      val -= cnt[i - 1][j + S - 1];
      val -= cnt[i + S - 1][j - 1];
      val += cnt[i - 1][j - 1];
      ans[val]++;
    }
  }
  for(int i = 0; i <= S * S; ++i){
    if(ans[i]){
      cout << i << " " << ans[i] << endl;
    }
  }
}
