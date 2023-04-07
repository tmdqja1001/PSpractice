#include <iostream>
#include <algorithm>
#include <string>

#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define MAX 50

using namespace std;

bool table[MAX][MAX];

int main(void){
    fastio;
    int r, c;
    cin >> r >> c;
    for(int i=0; i<r; i++){
        string buf;
        cin >> buf;
        for(int j=0; j<c; j++){
            if(buf[j] == 'B') table[i][j] = true; // black is 1, white is 0
        }
    }
    int ret = 32;

    for(int i=0; i<=(r-8); i++){
        for(int j=0; j<=(c-8); j++){
            bool tmp1 = true;
            bool tmp2 = false;
            int cnt1 = 0;
            int cnt2 = 0;
            for(int k=0; k<8; k++){
                for(int l=0; l<8; l++){
                    if(l==0) swap(tmp1, tmp2);
                    if(table[k+i][l+j]^tmp1) cnt1++;
                    if(table[k+i][l+j]^tmp2) cnt2++;
                    swap(tmp1, tmp2);
                }
            }
            cnt1 = min(cnt1, cnt2);
            ret = min(cnt1, ret);
        }
    }
    cout << ret << '\n';

}
