#include <iostream>

using namespace std;

int coins[10];

int main(void){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    int cnt = 0;
    int index = n-1;
    while(k){
        if(coins[index] <= k){
            cnt++;
            k -= coins[index];
        }
        else{
            if(index >= 0) index--;
        }
    }
    cout << cnt;

}
