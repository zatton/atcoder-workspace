#include <bits/stdc++.h>
using namespace std;


void solve(long long X, long long Y, long long Z, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C){

}

// Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    long long Z;
    scanf("%lld",&Z);
    std::vector<long long> A(X+Y+Z);
    std::vector<long long> B(X+Y+Z);
    std::vector<long long> C(X+Y+Z);
    for(int i = 0 ; i < X+Y+Z ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        scanf("%lld",&C[i]);
    }
    solve(X, Y, Z, std::move(A), std::move(B), std::move(C));
    return 0;
}