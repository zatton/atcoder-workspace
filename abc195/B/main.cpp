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

// 切り上げ
ll iceil(ll a,ll b){return (a+(b-1))/b;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


void solve(long long A, long long B, long long W){
  double w = W * 1000;
  ll ansmin = 1000000000000000;
  ll ansmax = 0;
  int ok = 0;
  REP(i, 10000000) {
    if (w / i <= B && w / i >= A) {
      chmin(ansmin, i);
      chmax(ansmax, i);
      ok = 1;
    }
  }
  if(ok) cout << ansmin << ' ' << ansmax << endl;
  else cout << "UNSATISFIABLE" << endl;
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long A;
  scanf("%lld",&A);
  long long B;
  scanf("%lld",&B);
  long long W;
  scanf("%lld",&W);
  solve(A, B, W);
  return 0;
}
