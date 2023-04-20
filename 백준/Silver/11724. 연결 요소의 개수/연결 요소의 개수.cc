#include <iostream>
#include <queue>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000

int n, m, cnt;
bool graph[MAX][MAX];
bool visited[MAX];
queue<int> bfsq;

void BFS(int a){        //start at 0
    bfsq.push(a);
    while(!bfsq.empty()){
        int temp = bfsq.front();
        visited[temp] = 1;
        bfsq.pop();
        for(int i=0; i<n; i++){
            if(graph[temp][i] && !visited[i]){
                visited[i] = 1;
                bfsq.push(i);
            }
        }
    }
    cnt++;
    return;
}

int main(void){
    fastio;
    cin >> n >> m;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a-1][b-1] = 1;        // -1 for start at 1
        graph[b-1][a-1] = 1;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]) BFS(i);
    }
    cout << cnt;

}
