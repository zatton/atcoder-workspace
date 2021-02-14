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
#define coutALL(x) {for(auto i=x.begin();i!=--x.end();i++)cout<<*i<<" ";cout<<*--x.end()<<endl};
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


void solve(long long N, std::string S){
  ll tmp = 0;
  vector<ll> l_li(SIZE(S));
  REP(i, SIZE(S)) {
    if (S[i] == '#') {
      tmp ++;
    }
    l_li[i] = tmp;
  }

  tmp = 0;
  vector<ll> r_li(SIZE(S));
  REP(i, SIZE(S)) {
    if (S[SIZE(S) - i - 1] == '.') {
      tmp ++;
    }
    r_li[SIZE(S) - i - 1] = tmp;
  }

  ll ans = INF64;
  REP(i, SIZE(S) + 1) {
    if (i == 0) {chmin(ans, r_li[0]);}
    else if (i == SIZE(S)) {chmin(ans, l_li[SIZE(S) - 1]);}
    else {chmin(ans, r_li[i] + l_li[i - 1]);}
  }

  cout << ans << endl;
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  //ios::sync_with_stdio(false); // stringを入力する時はオフ
  //cin.tie(nullptr);

  long long N;
  scanf("%lld",&N);
  std::string S;
  std::cin >> S;
  solve(N, S);
  return 0;
}
