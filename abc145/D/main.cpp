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

ll combi(ll a, ll b, ll mod) {
  //ll ans = 1;
  __int128 ans = 1;
  FOR(i, 1, b) ans = ans * (a - i + 1) / i;
  return ll(ans % mod);
  //return ll(res);
}

//順列
__int128 fact(__int128 a) { // 10^18を超える時
//ll fact(ll a) {
  if (a == 1 || a == 0) return 1;
  return a * fact(a - 1);
}


const long long MOD = 1000000007;

void solve(long long X, long long Y){
  if (Y > X) {
    ll tmp = X;
    X = Y;
    Y = tmp;
  }
  ll diff = X - Y;
  ll cntboth = Y - diff;

  if(cntboth % 3 != 0) {
    cout << 0 << endl;
    return;
  }

  cout << combi(diff + (cntboth / 3 * 2), diff, MOD) * combi(cntboth / 3 * 2, cntboth / 3, MOD) % MOD << endl;

}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long X;
  scanf("%lld",&X);
  long long Y;
  scanf("%lld",&Y);
  solve(X, Y);
  return 0;
}
