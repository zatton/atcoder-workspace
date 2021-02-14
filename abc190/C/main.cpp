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

ll ans_search(ll idx, vector<ll> cond, ll K, ll M, vector<ll> A, vector<ll> B, vector<ll> C, vector<ll> D) {
  // return ans
  if (idx == K) {
    ll ans = 0;
    REP(i, M) {
      if (cond[A[i]] > 0 && cond[B[i]] > 0) {
        ans ++;
      }
    }
    //coutALL(cond);
    return ans;
  }

  if (cond[C[idx]] > 0 && cond[D[idx]] > 0) {
    return ans_search(idx + 1, cond, K, M, A, B, C, D);
  } else if (cond[C[idx]] > 0) {
    cond[D[idx]] += 1;
    return ans_search(idx + 1, cond, K, M, A, B, C, D);
  } else if (cond[D[idx]] > 0) {
    cond[C[idx]] += 1;
    return ans_search(idx + 1, cond, K, M, A, B, C, D);
  }

  cond[C[idx]] += 1;
  ll ans_a = ans_search(idx + 1, cond, K, M, A, B, C, D);
  cond[C[idx]] -= 1;
  cond[D[idx]] += 1;
  ll ans_b = ans_search(idx + 1, cond, K, M, A, B, C, D);
  return max(ans_a, ans_b);
}

void solve(long long N, long long M, std::vector<long long> A, std::vector<long long> B, long long K, std::vector<long long> C, std::vector<long long> D){
  vector<ll> cond(N + 1);
  REP(i, N + 1) {
    cond[i] = 0;
  }
  ll ans = ans_search(0, cond, K, M, A, B, C, D);
  cout << ans << endl;
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long N;
  scanf("%lld",&N);
  long long M;
  scanf("%lld",&M);
  std::vector<long long> A(M);
  std::vector<long long> B(M);
  for(ll i = 0 ; i < M ; i++){
    scanf("%lld",&A[i]);
    scanf("%lld",&B[i]);
  }
  long long K;
  scanf("%lld",&K);
  std::vector<long long> C(K);
  std::vector<long long> D(K);
  for(ll i = 0 ; i < K ; i++){
    scanf("%lld",&C[i]);
    scanf("%lld",&D[i]);
  }
  solve(N, M, std::move(A), std::move(B), K, std::move(C), std::move(D));
  return 0;
}
