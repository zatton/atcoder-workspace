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
ll modpow(ll a, ll b, ll mod) {
  // a ^ b % mod
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll combi(ll a, ll b, ll mod) {
  //ll ans = 1;
  __int128 ans = 1;
  FOR(i, 1, b) ans = ans * (a - i + 1) / i;
  return ll(ans % mod);
  //return ll(res);
}



const long long MOD = 1000000007;

void solve(long long n, long long a, long long b){
  ll ans = modpow(2LL, n, MOD);
  ans--; // 0本の場合
  ans -= (combi(n, a, MOD) + combi(n, b, MOD));
  while (ans < 0) ans += MOD;
  cout << ans << endl;
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long n;
  scanf("%lld",&n);
  long long a;
  scanf("%lld",&a);
  long long b;
  scanf("%lld",&b);
  solve(n, a, b);
  return 0;
}
