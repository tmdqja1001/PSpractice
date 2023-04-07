#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dice[6];

int getSmall2(void){
    int ret;
    int line[12][2] = {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{3,4},{2,4},{5,1},{5,2},{5,3},{5,4}};
    ret = dice[line[0][0]] + dice[line[0][1]];
    for(int i=1; i<12; i++){
        ret = min(ret, dice[line[i][0]] + dice[line[i][1]]);
    }
    return ret;
}

int getSmall3(void){
    int ret;
    int vortex[8][3] = {{0,1,2},{0,1,3},{0,3,4},{0,2,4},{1,2,5},{1,3,5},{3,4,5},{2,4,5}};
    ret = dice[vortex[0][0]] + dice[vortex[0][1]] + dice[vortex[0][2]];
    for(int i=1; i<8; i++){
        ret = min(ret, dice[vortex[i][0]] + dice[vortex[i][1]] + dice[vortex[i][2]]);
    }
    return ret;
}

int main(void){
    int small3;   // smallest sum of 3
    int small2;   // smallest sum of 2
    int small1;   // smallest surface
    int big1 = 0; // biggest surface
    int n;
    long long ans = 0;
    cin >> n;
    for(int i=0; i<6; i++){
        cin >> dice[i];
        if(i==0) small1 = dice[0];
        small1 = min(small1, dice[i]);
        big1 = max(big1, dice[i]);
    }

    if(n==1){           // special case ( n = 1 )
        for(int i=0; i<6; i++){
            ans += dice[i];
        }
        cout << ans-big1 << '\n';
        return 0;
    }

    // normal case ( n > 1 )

    small2 = getSmall2();
    small3 = getSmall3();

    int k = n-2;

    ans += (long long)5*k*k*small1;
    ans += (long long)4*k*small1;
    ans += (long long)8*k*small2;
    ans += (long long)4*small2;
    ans += (long long)4*small3;

    cout << ans <<  '\n';
    return 0;
}
