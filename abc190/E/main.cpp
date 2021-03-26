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


void solve(ll, N, ll M, vector<ll> A, vector<ll> B, ll K, vector<ll> C) {
  vector<map<ll, ll>> tree(N + 1);
  REP(i, M) {
    tree[A[i]][B[i]] = 1;
    tree[B[i]][A[i]] = 1;
  }

  set<ll> c_list;
  REP(i, K) c_list.insert(C[i]);

  vector<int> check(N + 1);
  queue<ll> que;
  que.push(C[0]);
  while(SIZE(que) > 0) {
    ll now = que.front();
    que.pop();
    for(auto next_node : tree[now]) {
      ll next_key = next_node -> first;
      if (check[next_key] == 0) {
        // まだ行ってない
        que.push(next_key);
        auto tmp = c_list.find(next_key);
        if (tmp != c_list.end()) {
          c_list.erace(tmp);
        }
      }
    }
  }
}


signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M, K;
  vector<ll> A(M), B(M), C(K);

  cin >> N >> M;
  REP(i, M) cin >> A[i] >> B[i];
  cin >> K;
  REP(i, K) cin >> C[i];

  solve(N, M, A, B, K, C);

  return 0;
}
