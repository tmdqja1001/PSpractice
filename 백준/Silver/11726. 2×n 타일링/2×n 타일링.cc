#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 10007

using namespace std;

int dp[1000];
int n;

int main(void){
    fastio
    dp[0] = 1;
    dp[1] = 2;
    cin >> n;
    for(int i=2; i<n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }
    cout << dp[n-1];

}
