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
#define coutALL(x) for(auto i=x.begin();i!=--x.end();i++)cout<<*i<<" ";cout<<*--x.end()<<endl;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }


void solve(ll H, ll W, vector<string> S) {
  ll ii_sur[4] = {-1, 0, 0, 1};
  ll jj_sur[4] = {0, -1, 1, 0};

  ll ans = 0;

  REP(i, H) REP(j, W) {
    if (S[i][j] == '.') {
      queue<pair<ll, ll>> que;
      que.push(make_pair(i, j));

      vector<vector<ll>> check(H, vector<ll>(W));
      REP(ii, H) REP(jj, W) check[ii][jj] = -1;
      check[i][j] = 0;


      while(SIZE(que) > 0) {
        auto tmp = que.front();
        que.pop();
        ll ii = tmp.F; ll jj = tmp.S;
        REP(k, 4) {
          if (ii + ii_sur[k] >= 0 && ii + ii_sur[k] < H && jj + jj_sur[k] >= 0 && jj + jj_sur[k] < W) {
            if (S[ii + ii_sur[k]][jj + jj_sur[k]] == '.' && check[ii + ii_sur[k]][jj + jj_sur[k]] < 0) { // 未踏
              check[ii + ii_sur[k]][jj + jj_sur[k]] = check[ii][jj] + 1;
              chmax(ans, check[ii][jj] + 1);
              que.push(make_pair(ii + ii_sur[k], jj + jj_sur[k]));
            }
          }
        }
      }

    }
  }
  cout << ans << endl;

}


signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll H, W;
  cin >> H >> W;

  vector<string> S(H);

  REP(i, H) cin >> S[i];

  solve(H, W, move(S));

  return 0;
}
