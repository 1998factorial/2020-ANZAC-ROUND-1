#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<int , int> ii;

double MAX[1 << 10][7][7];
double MIN[1 << 10][7][7];
bool vis[1 << 10][7][7];
string s;
int a , b;


double getMin(int mask , int x, int y){
  if(!mask)return 0;
  if(!vis[mask][x][y]){
    return MIN[mask][x][y];
  }
  for(int subset = mask; subset; subset = (subset - 1) & mask){

  }
}



void solve_max(){
  int mask = 0;
  for(int i = 0; i < s.size(); ++i){
    mask |= (1 << (s[i] - '0'));
  }

}

void solve_min(){
  int mask = 0;
  for(int i = 0; i < s.size(); ++i){
    mask |= (1 << (s[i] - '0'));
  }
  double best_score = 0;
  int best_choice = 0;
  for(int subset = mask; subset; subset = (subset - 1) & mask){
    int sum = 0;
    for(int i = 1; i <= 9; ++i){
      if((1 << i) & subset)sum += i; // get all digit sum in this choice
    }
    if(sum == a + b){
      double r = 0;
      for(int x = 1; x <= 6; ++x){
        for(int y = 1; y <= 6; ++y){
          r += getMin(mask ^ subset , x , y);
        }
      }
      r /= 36.0;
      if(r > best_score){
        r = best_score;
        best_choice = subset;
      }
    }
  }
  if(best_choice){
    vector<int> t;
    for(int i = 1; i <= 9; ++i){
      if((1 << i) & best_choice)t.push_back(i);
    }
    for(int i : t)cout << i;
    cout << " ";
    cout << best_score << endl;
  }
  else{
    cout << -1 << " "; // can not choose any digits
    vector<int> t;
    for(int i = 1; i <= 9; ++i){
      if((1 << i) & mask)t.push_back(i);
    }
    for(int i : t)cout << i;
    cout << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(MAX , 0 , sizeof(MAX));
  memset(MIN , 0 , sizeof(MIN));
  while(cin >> s >> a >> b){
    solve_min();
    solve_max();
  }
}
