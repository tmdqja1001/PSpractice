#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int r, c;
int map1[100][100];
const int direction[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
queue<pair<int, int>> bfsq;

void BFS(void){
    int row = bfsq.front().first;
    int col = bfsq.front().second;
    bfsq.pop();

    for(int i=0; i<4; i++){
        int next_row = row + direction[i][0];
        int next_col = col + direction[i][1];
        if(next_row < 0 || next_row >= r) continue;     // out of map
        if(next_col < 0 || next_col >= c) continue;     // out of map
        if(map1[next_row][next_col] != 1) continue;     // visited
        map1[next_row][next_col] += map1[row][col];
        bfsq.push({next_row, next_col});
    }
}

void print(void){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << map1[i][j];
        }
        cout << '\n';
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        string buf;
        cin >> buf;
        for(int j=0; j<c; j++){
            if(buf[j] == '0') map1[i][j] = 0;
            else if(buf[j] == '1') map1[i][j] = 1;
        }
    }
    bfsq.push({0,0});
    while(!bfsq.empty()){
        BFS();
    }
    cout << map1[r-1][c-1] << '\n';
    //print();
}
