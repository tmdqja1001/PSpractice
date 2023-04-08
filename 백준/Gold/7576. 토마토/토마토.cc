#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1000

int tomatoes[MAX][MAX];
int r, c; // row, col
int fresh; // number of fresh tomatoes
queue<pair<int, int>> riped;

void print(void){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << tomatoes[i][j] << ' ';
        }
        cout << '\n';
    }
}

void ripe(void){
    int row = riped.front().first;
    int col = riped.front().second;
    //cout << row << ' ' << col << '\n';
    riped.pop();
    int next[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    for(int i=0; i<4; i++){
        int row_new = next[i][0] + row;
        int col_new = next[i][1] + col;
        if(row_new < 0 || row_new >= r) continue;
        else if(col_new < 0 || col_new >= c) continue;
        else if(tomatoes[row_new][col_new] == 0){
            fresh--;
            tomatoes[row_new][col_new] = tomatoes[row][col] + 1;
            riped.push({row_new, col_new});
        }
    }
    return;
}

int maximum(void){
    int ret = tomatoes[0][0];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            ret = max(tomatoes[i][j], ret);
        }
    }
    return ret;
}

int main(void){
    cin >> c >> r;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> tomatoes[i][j];
            if(tomatoes[i][j] == 0) fresh++;
            else if(tomatoes[i][j] == 1) riped.push({i, j});
        }
    }
    int fresh_new = fresh;
    while(!riped.empty()){
        ripe();
        //print();
    }
    //print();
    int time = maximum();
    //cout << time << '\n';
    if(fresh == 0)    cout << time-1 << '\n';
    else    cout << -1 << '\n';
    return 0;
}
