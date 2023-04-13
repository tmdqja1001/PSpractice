#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 101

using namespace std;

bool arr[MAX][MAX];         //
queue<int> bfsq;
bool visited[MAX];
int n;                  // number of computers

int bfs(int a){
    int ret = 0;
    visited[a] = true;
    for(int i=1; i<=n; i++){
        if(arr[1][i] & ~visited[i]){
            bfsq.push(i);
            visited[i] = true;
            ret++;
        }
    }
    while(!bfsq.empty()){
        int com = bfsq.front();
        bfsq.pop();
        //visited[com] = true;
        for(int i=1; i<=n; i++){
            if(arr[com][i] & ~visited[i]){
                bfsq.push(i);
                visited[i] = true;
                ret++;
            }
        }
    }
    return ret;
}

int main(void){
    fastio
    cin >> n;
    int line;
    cin >> line;
    for(int i=0; i<line; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }
    cout << bfs(1);

}
