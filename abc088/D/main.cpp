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

void solve(ll H, ll W, vector<string> layout) {
  queue<pair<ll, ll>> que;
  que.push(make_pair(0, 0));

  vector<vector<ll>> dist(H, vector<ll>(W));
  dist[0][0] = 1;

  vector<ll> vert{0, -1, 1, 0}; //垂直
  vector<ll> hori{-1, 0, 0, 1}; //水平

  while(SIZE(que) > 0) {
    auto tmp = que.front();
    //cout << tmp.F << tmp.S << endl;
    que.pop();
    if (tmp.F == H - 1 && tmp.S == W - 1) {
      break;
    }
    REP(k, 4) {
      auto i = vert[k];
      auto j = hori[k];
      if (tmp.F + i < 0 || tmp.S + j < 0 || tmp.F + i >= H || tmp.S + j >= W) continue;
      if (layout[tmp.F + i][tmp.S + j] == '.' && dist[tmp.F + i][tmp.S + j] == 0) {
        que.push(make_pair(tmp.F + i, tmp.S + j));
        dist[tmp.F + i][tmp.S + j] = dist[tmp.F][tmp.S] + 1;
      }
    }
    //REP(j, H) coutALL(dist[j]);
  }

  if(dist[H - 1][W - 1] == 0) {cout << -1 << endl; return;}

  ll ans = 0;
  REP(i, H) REP(j, W) if(layout[i][j] == '#') ans++;

  //cout << dist[H - 1][W - 1] << endl;

  ans = H * W - dist[H - 1][W - 1] - ans;

  cout << ans << endl;
}


signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  ll H, W;
  cin >> H >> W;

  vector<string> layout(H);

  REP(i, H) cin >> layout[i];

  solve(H, W, layout);

  return 0;
}
