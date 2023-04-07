#include <iostream>
#include <algorithm>

#define MAXN 20
#define MAXC 1000001


using namespace std;

int c, n;
int cost[MAXN];
int reward[MAXN];
int dp[MAXC]; // 소모 비용당 최대 인원 // 1명당 100원 * 1000명

void input(void){
    cin >> c >> n;
    for(int i=0; i<n; i++){
        cin >> cost[i] >> reward[i];
    }
}

void dynamicPro(void){
    for(int i=0; i<n; i++){
        for(int j=0; j<MAXC; j++){     // j원을 사용하여 만들 수 있는 최대 reward
            if(j - cost[i] >= 0){
                dp[j] = max(dp[j], dp[j-cost[i]]+reward[i]);
            }
        }
    }
}

void getAns(void){
    for(int i=0; i<MAXC; i++){
        if(dp[i] >= c){
            cout << i << endl;
            return;
        }
    }
}

int main(void){
    input();
    dynamicPro();
    getAns();
}
