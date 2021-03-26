#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//イテレーション
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
//x:コンテナ
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())
//定数
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf
//#define MOD 1000000007 //問題による
//略記
#define F first
#define S second
//出力(空白区切りで昇順に)
#define coutALL(x) {for(auto i=x.begin();i!=--x.end();i++)cout<<*i<<" ";cout<<*--x.end()<<endl;}


void solve(long long H, long long W, std::vector<std::vector<long long>> c, std::vector<std::vector<long long>> A){
  vector<ll> cost(10, INF64); // 1にするコストの最小値
  REP(i, 10) cost[i] = c[i][1];
  queue<int> que;
  REP(i, 10) que.push(i);

  while(SIZE(que) > 0) {
    ll tmp = que.front();
    que.pop();

    REP(i, 10) {
      if (cost[tmp] + c[i][tmp] < cost[i]) {
        cost[i] = cost[tmp] + c[i][tmp];
        que.push(i);
      }
    }
  }

  //coutALL(cost);

  ll ans = 0;
  REP(i, H) REP(j, W) {
    if (A[i][j] == -1) continue;
    ans += cost[A[i][j]];
  }
  cout << ans << endl;
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long H;
  scanf("%lld",&H);
  long long W;
  scanf("%lld",&W);
  std::vector<std::vector<long long>> c(9-0+1, std::vector<long long>(9-0+1));
  for(ll i = 0 ; i < 9-0+1 ; i++){
    for(ll j = 0 ; j < 9-0+1 ; j++){
      scanf("%lld",&c[i][j]);
    }
  }
  std::vector<std::vector<long long>> A(H, std::vector<long long>(W));
  for(ll i = 0 ; i < H ; i++){
    for(ll j = 0 ; j < W ; j++){
      scanf("%lld",&A[i][j]);
    }
  }
  solve(H, W, std::move(c), std::move(A));
  return 0;
}
