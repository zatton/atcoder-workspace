#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long M, std::vector<long long> A, std::vector<std::vector<long long>> B){

}

// Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<std::vector<long long>> B(N, std::vector<long long>(M));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%lld",&B[i][j]);
        }
    }
    solve(N, M, std::move(A), std::move(B));
    return 0;
}
