#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long long MOD = 2;

void solve(long long N, std::vector<long long> a){
  long long count = 0;
  vector<long long> ans_p;
  int ans[N + 1];
  for (ll i = 0; i <= N; i++) {
    ans[i] = 0;
  }
  for (ll i = 1; i <= N; i++) {
    cout << ans[i] << a[i - 1] << endl;
    if (ans[i] == a[i - 1]) {
      continue;
    }
    count++;
    ans_p.push_back(i);
    cout << i << endl;
    long long tmp = i;
    while (tmp <= N) {
      ans[tmp] = (ans[tmp] + 1) % 2;
      tmp += i;
    }
  }
  cout << count << endl;
  //cout << ans_p[0] << endl;;
  //for (int i = 0; i < ans_p.size() - 1; i++) {
  //  cout << ans_p[i] << ' ';
  //}
  //cout << ans_p[ans_p.size() - 1] << endl;;
}

// Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
