#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 100

int tomatoes[MAX][MAX][MAX];
int r, c, h; // row, col, height
int fresh; // number of fresh tomatoes
queue<vector<int>> riped;

void print(void){
    for(int i=0; i<h; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                cout << tomatoes[i][j][k] << ' ';
            }
            cout << '\n';
        }
    }
}

void ripe(void){
    auto p = riped.front();
    int hei = p[0];
    int row = p[1];
    int col = p[2];
    //cout << row << ' ' << col << '\n';
    riped.pop();
    int next[6][3] = {{-1,0,0},{1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
    for(int i=0; i<6; i++){
        int hei_new = next[i][0] + hei;
        int row_new = next[i][1] + row;
        int col_new = next[i][2] + col;
        if(row_new < 0 || row_new >= r) continue;
        else if(col_new < 0 || col_new >= c) continue;
        else if(hei_new < 0 || hei_new >= h) continue;
        else if(tomatoes[hei_new][row_new][col_new] == 0){
            fresh--;
            tomatoes[hei_new][row_new][col_new] = tomatoes[hei][row][col] + 1;
            riped.push({hei_new, row_new, col_new});
        }
    }
    return;
}

int maximum(void){
    int ret = tomatoes[0][0][0];
    for(int i=0; i<h; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                ret = max(tomatoes[i][j][k], ret);
            }
        }
    }
    return ret;
}

int main(void){
    cin >> c >> r >> h;
    for(int i=0; i<h; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                cin >> tomatoes[i][j][k];
                if(tomatoes[i][j][k] == 0) fresh++;
                else if(tomatoes[i][j][k] == 1) riped.push({i, j, k});
            }
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
