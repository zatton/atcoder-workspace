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


void solve(long long Q, std::vector<long long> l, std::vector<long long> r){
  vector<ll> prime_list;
  vector<ll> ok_list;
  for(ll i = 2; i <= 100000; i++) {
    int ok = 1;
    for (ll j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        ok = 0;
        break;
      }
    }
    if (!ok) continue;
    prime_list.push_back(i);
    if (find(ALL(prime_list), (i + 1) / 2) == prime_list.end()) continue;
    // cout << i << endl;
    ok_list.push_back(i);
  }

  REP(i, Q) {
    // cout << *lower_bound(ALL(ok_list), r[i] + 1) << ' ' << *lower_bound(ALL(ok_list), l[i]) << endl;
    ll ans = distance(ok_list.begin(), lower_bound(ALL(ok_list), r[i] + 1))
      - distance(ok_list.begin(), lower_bound(ALL(ok_list), l[i]));
    if (ans < 0) ans = 0;
    cout << ans << endl;
  }
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long Q;
  scanf("%lld",&Q);
  std::vector<long long> l(Q);
  std::vector<long long> r(Q);
  for(ll i = 0 ; i < Q ; i++){
    scanf("%lld",&l[i]);
    scanf("%lld",&r[i]);
  }
  solve(Q, std::move(l), std::move(r));
  return 0;
}
