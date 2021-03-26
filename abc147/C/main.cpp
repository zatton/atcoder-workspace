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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }


void solve(ll N, vector<ll> A, vector<vector<ll>> x, vector<vector<ll>> y) {
  ll ans = 0;
  REP(n, 1 << N) {
    //cout << endl << endl;
    int ok = 1;
    ll tmp_ans = 0;
    REP(i, N) {
      int honest = (n >> i & 1);
      // cout << honest;
      tmp_ans += honest;

      REP(j, A[i]) {
        if (honest) {
          if (((n >> x[i][j]) & 1) != y[i][j]) {
            ok = 0;
            break;
          }
        }
      }
      if (!ok) break;
    }
    if (!ok) continue;
    // cout << endl;
    // cout << "OK" << ok << endl;
    chmax(ans, tmp_ans);
  }
  cout << ans << endl;
}


signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  //ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<vector<ll>> x;
  vector<vector<ll>> y;
  REP(i, N) {
    cin >> A[i];
    vector<ll> tmp_x(A[i]);
    vector<ll> tmp_y(A[i]);
    REP(j, A[i]) {
      cin >> tmp_x[j] >> tmp_y[j];
      tmp_x[j] -= 1;
    }
    x.push_back(tmp_x);
    y.push_back(tmp_y);
  }

  solve(N, A, x, y);

  return 0;
}
