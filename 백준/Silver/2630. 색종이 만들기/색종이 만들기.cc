#include <iostream>

#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define MAX 128
using namespace std;


int n;
int arr[MAX][MAX];
int cnt_1;  // blue
int cnt_0;  // white

void countArr(int c_s, int c_e, int r_s, int r_e){
    int start = arr[r_s][c_s];
    bool end_flag = true;
    for(int i=r_s; i<=r_e; i++){
        for(int j=c_s; j<=c_e; j++){
            if(start != arr[i][j]){
                end_flag = false;
                break;
            }
        }
        if(!end_flag) break;
    }
    if(end_flag){
        if(start) cnt_1++;
        else cnt_0++;
        return;
    }
    int c_m = (c_s + c_e) / 2;
    int r_m = (r_s + r_e) / 2;
    countArr(c_s, c_m, r_s, r_m); // 1
    countArr(c_m + 1, c_e, r_s, r_m);
    countArr(c_s, c_m, r_m + 1, r_e);
    countArr(c_m + 1, c_e, r_m + 1, r_e);
}


int main(void){
    fastio;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    countArr(0, n - 1, 0, n - 1);
    cout << cnt_0 << '\n' << cnt_1;

}
