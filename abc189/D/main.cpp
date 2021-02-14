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

//aをbで割る時の繰上げ,繰り下げ
ll myceil(ll a,ll b){return (a+(b-1))/b;}
ll myfloor(ll a,ll b){return a/b;}


void solve(long long N, std::vector<std::string> S){
  ll cnt_f = 1;
  ll cnt_t = 1;
  REP(i, N) {
    if (S[i] == "AND") {
      ll _cnt_f = cnt_t + cnt_f * 2;
      ll _cnt_t = cnt_t;
      cnt_t = _cnt_t;
      cnt_f = _cnt_f;
    } else {
      ll _cnt_f = cnt_f;
      ll _cnt_t = cnt_t * 2 + cnt_f;
      cnt_t = _cnt_t;
      cnt_f = _cnt_f;
    }
  }
  cout << cnt_t << endl;
}

signed main(){
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);

  long long N;
  scanf("%lld",&N);
  std::vector<std::string> S(N);
  for(ll i = 0 ; i < N ; i++){
    std::cin >> S[i];
  }
  solve(N, std::move(S));
  return 0;
}