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


void solve(ll H, ll W, ll K, vector<vector<char>> s) {

  vector<vector<ll>> div_col;
  vector<ll> div_row;

  REP(i, H) {
    vector<ll> tmp_div_col;
    REP(j, W) {
      if (s[i][j] == '#') {
        tmp_div_col.push_back(j);
      }
    }
    if (SIZE(tmp_div_col) > 0) {
      div_col.push_back(tmp_div_col);
      div_row.push_back(i);
    }
  }

  ll now = 1;
  REP(i, SIZE(div_row)) {
    vector<ll> tmp_row_ans;
    // tmp_row_ansを作る
    REP(j, SIZE(div_col[i])) {
      ll col_st = 0;
      ll col_en = W - 1;
      if (j != 0) col_st = div_col[i][j - 1] + 1;
      if (j != SIZE(div_col[i]) - 1) col_en = div_col[i][j];
      FOR(k, col_st, col_en) tmp_row_ans.push_back(now);
      now ++;
    }

    ll row_st = 0;
    ll row_en = H - 1;
    if (i != 0) row_st = div_row[i - 1] + 1;
    if (i != SIZE(div_row) - 1) row_en = div_row[i];

    FOR(j, row_st, row_en) coutALL(tmp_row_ans);
  }

  return;
}


signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll H, W, K;
  cin >> H >> W >> K;

  //char s[H][W];
  vector<vector<char>> s(H, vector<char>(W));
  REP(i, H) REP(j, W) cin >> s[i][j];

  solve(H, W, K, s);

  return 0;
}
