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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


void solve(long long N, std::string S){
  ll tmp = 0;
  ll ins_l = 0;
  ll ins_r = 0;
  REPD(i, N) {
    if (S[i] == ')') {
      tmp++;
    } else {
      tmp--;
    }
    chmin(ins_r, tmp);
  }

  tmp = 0;
  REP(i, N) {
    if (S[i] == '(') {
      tmp++;
    } else {
      tmp--;
    }
    chmin(ins_l, tmp);
  }

  REP(_, -ins_l) cout << '(';
  cout << S;
  REP(_, -ins_r) cout << ')';
  cout << endl;

}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  //ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long N;
  scanf("%lld",&N);
  std::string S;
  std::cin >> S;
  solve(N, S);
  return 0;
}
