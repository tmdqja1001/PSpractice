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
    int temR, temG, temB;
    int ret;

    for(int i=0; i<n; i++){
        cin >> curR >> curG >> curB;
        if(i){
            temR = curR + min(minG, minB);
            temB = curB + min(minR, minG);
            temG = curG + min(minR, minB);
            minR = temR;
            minG = temG;
            minB = temB;
        }
        else{
            minR = curR;
            minG = curG;
            minB = curB;
        }
    }
    ret = min(minR, minG);
    ret = min(ret, minB);
    cout << ret;
}
