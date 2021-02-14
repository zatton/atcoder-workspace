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

//aをbで割る時の繰上げ,繰り下げ
ll myceil(ll a,ll b){return (a+(b-1))/b;}
ll myfloor(ll a,ll b){return a/b;}

const string YES = "Yes";
const string NO = "No";

void solve(ll N, ll M, ll T, vector<ll> A, vector<ll> B) {
  ll last = 0;
  ll tmp = N;
  REP(i, M) {
    tmp -= A[i] - last; // 減った量
    if (tmp <= 0) {
      cout << NO << endl;
      return;
    }
    tmp += B[i] - A[i];
    tmp = min(tmp, N);
    last = B[i];
  }
  tmp -= T - last; // 減った量
  if (tmp <= 0) {
    cout << NO << endl;
    return;
  }
  cout << YES << endl;
}


signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M, T;
  cin >> N >> M >> T;
  vector<ll> A(M);
  vector<ll> B(M);
  REP(i, M){
    cin >> A[i] >> B[i];
  }

  solve(N, M, T, move(A), move(B));

  return 0;
}
