#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long long MOD = 1000000007;

map<ll, ll> count_ele(vector<ll> vec) {
  map<ll, ll> res;
  for (auto iter = vec.begin(); iter != vec.end() ; iter++) {
    if (res.find(*iter) == res.end()) {
      res[*iter] = 1;
    } else {
      res[*iter] += 1;
    }
  }
  return res;
}

ll modpow(ll a, ll b, ll mod) {
  ll res = 1;
  ll tmp = a;
  while (b > 0) {
    if (b & 1) {
      res = res * tmp % mod;
    }
    tmp = tmp * tmp % mod;
    b >>= 1;
  }
  return res;
}

void solve(long long N, std::vector<long long> A){
  int odd = (N % 2);
  auto count = count_ele(A);
  if (odd) {
    for (int i = 0; i <= (N - 1); i += 2) {
      if (count.find(i) != count.end() && (count[i] == 2 || (i == 0 && count[i] == 1))) {
        continue;
      } else {
        cout << 0 << endl;
        return;
      }
    }
    cout << modpow(2, (N - 1) / 2, MOD) << endl;
  } else {
    for (int i = 1; i <= (N - 1); i += 2) {
      if (count.find(i) != count.end() && count[i] == 2) {
        continue;
      } else {
        cout << 0 << endl;
        return;
      }
    }
    cout << modpow(2, N / 2, MOD) << endl;
  }
}

// Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}