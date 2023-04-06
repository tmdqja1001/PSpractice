#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

bool table[MAX][MAX];
bool visited[MAX];
bool visited2[MAX];
queue<int> bfsQueue;

void DFS(int n){
    visited[n] = true;
    cout << n << ' ';
    for(int i=1; i<MAX; i++){
        if(table[n][i]) if(!visited[i]) DFS(i);
    }
    return;
}

void BFS(int n){
    visited2[n] = true;
    cout << n << ' ';
    for(int i=1; i<MAX; i++){
        if(table[n][i]){
            cout << i << ' ';
            bfsQueue.push(i);
            visited2[i] = true;
        }
    }
        while(!bfsQueue.empty()){
            int top = bfsQueue.front();
            bfsQueue.pop();
            for(int j = 1; j<MAX; j++){
                if(table[top][j] && !visited2[j]){
                    cout << j << ' ';
                    bfsQueue.push(j);
                    visited2[j] = true;
                }
            }
        }
    return;
}

int main(void){
    int n, m, v;
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        table[a][b] = true;
        table[b][a] = true;
    }
    // DFS
    DFS(v);
    cout << '\n';
    BFS(v);
}
