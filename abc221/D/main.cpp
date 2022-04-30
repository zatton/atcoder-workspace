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


signed main(){

  ll N;
  cin >> N;

  vector<ll> A(N);
  vector<ll> B(N);

  //cout << "ok" << endl;

  REP(i, N) cin >> A[i] >> B[i];

  map<ll, ll> tmp;
  ll max_day = 0;

  REP(i, N) {

    if (tmp.count(A[i]) > 0) {
      tmp[A[i]] += 1;
    } else {
      tmp[A[i]] = 1;
    }
    if (tmp.count(A[i] + B[i]) > 0) {
      tmp[A[i] + B[i]] -= 1;
    } else {
      tmp[A[i] + B[i]] = -1;
    }
  //cout << tmp[1] << tmp[2] << tmp[3] << tmp[4] << tmp[5] << endl;
  }

  vector<ll> ans(N, 0);

  ll st = 1;
  ll now = 0;
  FORA(i, tmp) {
    ll day = i.first;
    ll diff = i.second;
    if (now > 0) {
      ans[now - 1] += day - st;
    }
    //cout << diff << endl;
    now += diff;
    st = day;
  }

  coutALL(ans);

  return 0;
}

