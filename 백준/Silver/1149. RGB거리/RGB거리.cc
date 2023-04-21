#include <iostream>
#include <algorithm>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n;

int main(void){
    fastio;
    cin >> n;
    int curR, curG, curB;
    int minR, minG, minB;

    for(int i=0; i<n; i++){
        cin >> curR >> curG >> curB;
        if(i){
            curR = curR + min(minG, minB);
            curB = curB + min(minR, minG);
            curG = curG + min(minR, minB);
        }
        minR = curR;
        minG = curG;
        minB = curB;
    }
    cout << min(min(minR, minG), minB);
}
