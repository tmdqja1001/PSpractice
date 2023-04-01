#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int N, int number) {
    vector<vector<int>> dp(8, {0});    
    int answer = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<=i; j++){
            int exp = pow(10, j);
            dp[i][0] += N*exp;
        }
        if(dp[i][0] == number){
            return i+1;
        }
    }
    
    for(int i=1; i<8; i++){
        for(int j=0; j<i; j++){
            int k = i - j - 1;
            for(auto p1 : dp[j]){
                for(auto p2 : dp[k]){
                    dp[i].push_back(p1 * p2);
                    dp[i].push_back(p1 + p2);
                    dp[i].push_back(p1 - p2);
                    if(p2 != 0)
                        dp[i].push_back(p1 / p2);
                }
            }
        }
        for(int j=0; j<dp[i].size(); j++){
            if(number == dp[i][j]){
                return i+1;
            }
        }
    }
    
    return answer = -1;
}