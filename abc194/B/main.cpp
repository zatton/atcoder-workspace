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

void solve(ll N, vector<ll> A, vector<ll> B) {
  vector<pair<ll, ll>> Ap;
  vector<pair<ll, ll>> Bp;

  REP(i, N) {
    Ap.push_back(make_pair(A[i], i));
    Bp.push_back(make_pair(B[i], i));
  }

  sort(ALL(Ap));
  sort(ALL(Bp));

  ll ans;
  if ((*(Ap.begin())).second != (*(Bp.begin())).second) {
      ans = max((*(Ap.begin())).first, (*(Bp.begin())).first);
  } else {
    ans = min(min(
      max((*(Ap.begin())).first, (*(Bp.begin() + 1)).first),
      max((*(Ap.begin() + 1)).first, (*(Bp.begin())).first)
    ), Ap[0].first + Bp[0].first);
  }
  cout << ans << endl;
}


signed main(){
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  //ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  ll N;
  cin >> N;

  vector<ll> A(N);
  vector<ll> B(N);

  REP(i, N) cin >> A[i] >> B[i];

  solve(N, A, B);

  return 0;
}