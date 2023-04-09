#include <iostream>

using namespace std;

int main(void){
    int dp[11];
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for(int i=3; i<12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        cout << dp[t-1] << '\n';
    }
}
