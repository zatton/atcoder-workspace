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

// 切り上げ
ll iceil(ll a,ll b){return (a+(b-1))/b;}

void solve(long long S){
  ll A, b;
  if (S % 1000000000 == 0) {
    A = S / 1000000000;
    b = 0;
  } else {
    A = S / 1000000000 + 1;
    b = 1000000000 - S % 1000000000;
  }
  cout << A << ' ' << b << ' ' << 1 << ' ' << 1000000000 << ' ' << 0 << ' ' << 0 << endl;
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long S;
  scanf("%lld",&S);
  solve(S);
  return 0;
}
