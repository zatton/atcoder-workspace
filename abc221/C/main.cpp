#include <bits/stdc++.h>
#include <string>
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

int ctoi(char c) {
  return int(c - '0');
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  string N;
  cin >> N;

  ll ans = 0;

  REP(i, pow(2, N.size())) { // O(2^N)
    //cout << endl << i << endl;
    vector<int> a;
    vector<int> b;
    REP(j, N.size()) { // O(1)
      //cout << j << endl;
      //cout << (i >> j) << endl;
      //cout << N[j] << endl << endl;;
      //cout << endl;

      if ((i >> j) & 1) {
        a.push_back(ctoi(N[j]));
      } else {
        b.push_back(ctoi(N[j]));
      }
    }

    if (a.size() == 0 || b.size() == 0) {
      continue;
    }

    sort(ALL(a));
    sort(ALL(b));

    if (a[a.size() - 1] == 0 || b[b.size() - 1] == 0) {
      continue;
    }

    ll A = 0, B = 0;

    ll tmp = 1;
    REP(j, a.size()) {
      A += tmp * a[j];
      tmp *= 10;
    }

    tmp = 1;
    REP(j, b.size()) {
      B += tmp * b[j];
      tmp *= 10;
    }

    chmax(ans, A * B);
  }

  cout << ans << endl;

  return 0;
}

