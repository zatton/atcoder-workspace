#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string YES = "POSSIBLE";
const string NO = "IMPOSSIBLE";

ll gcd(ll A, ll B) {
  if (B == 0) {
    return A;
  }
  return gcd(B, A % B);
}

void solve(long long N, long long K, std::vector<long long> A){
  ll gcda = A[0];
  ll maxa = *max_element(A.begin(), A.end());
  if (maxa < K) {
    cout << NO << endl;
    return;
  }
  for (int i = 1; i < N; i++) {
    gcda = gcd(gcda, A[i]);
  }
  if (K % gcda == 0) {
    cout << YES << endl;
  } else {
    cout << NO << endl;
  }
  return;
}

// Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}
