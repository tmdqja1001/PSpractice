#include <iostream>
#include <cstdlib>

using namespace std;

int n;
int row[15];        // 행별 queen 의 위치 start at 1
int n_queen;
int cnt;

void putQueen(int cur){
    if(cur == n){
        cnt++;
        return;
    }

    for(int i=1; i<=n; i++){    // cur 행 후보 값
        bool flag = 1;
        for(int j=0; j<cur; j++){   // cur 전 행까지 검사
            if(i == row[j]){
                flag = 0;
                break;
            }
            if(abs(cur-j) == abs(i-row[j])){ // 대각선
                flag = 0;
                break;
            }
        }
        if(flag){
            row[cur] = i;
            putQueen(cur+1);
        }
    }
}


int main(void){
    cin >> n;
    putQueen(0);
    cout << cnt;

}
