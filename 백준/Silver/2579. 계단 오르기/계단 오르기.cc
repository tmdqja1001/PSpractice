#include <iostream>
#include <algorithm> // max, min

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


using namespace std;

int dp[2][300];         // double streak -> 1

int main(void){
    fastio
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int buf;
        cin >> buf;
        if(i==0){
            dp[0][i] = buf;
            dp[1][i+1] = buf;
        }
        else if(i==1){
            dp[1][i] += buf;
            dp[0][i] = buf;
        }
        else{
            dp[0][i] = max(dp[0][i-2], dp[1][i-2]) + buf;
            dp[1][i] = dp[0][i-1] + buf;
        }
    }
    cout << max(dp[0][n-1], dp[1][n-1]);
}
