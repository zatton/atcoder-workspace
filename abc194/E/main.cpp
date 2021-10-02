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
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


void solve(long long N, long long M, std::vector<long long> A){
  ll MAX_NUM = 1500000;
  vector<ll> cond(MAX_NUM + 1);
  REP(i, M) {
    cond[A[i]]++;
  }

  // REP(i, 10) cout << cond[i] << ' ';
  // cout << endl;

  ll tmp = -1;
  REP(i, MAX_NUM + 1) {
    if (cond[i] == 0) {
      tmp = i;
      break;
    }
  }
  ll ans = tmp;
  FOR(i, 1, N - M) {
    cond[A[i - 1]]--;
    cond[A[i + M - 1]]++;

    if (cond[A[i - 1]] == 0 && A[i - 1] < tmp) {
      tmp = A[i - 1];
    } else if (A[i + M] == tmp) {
      FOR(j, tmp, MAX_NUM + 1) {
        if (cond[i] == 0) {
          tmp = i;
          break;
        }
      }
    }
    // REP(i, 10) cout << cond[i] << ' ';
    // cout << endl;
    // cout << tmp << endl;
    chmin(ans, tmp);
  }
  cout << ans << endl;
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long N;
  scanf("%lld",&N);
  long long M;
  scanf("%lld",&M);
  std::vector<long long> A(N);
  for(ll i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
  }
  solve(N, M, std::move(A));
  return 0;
}