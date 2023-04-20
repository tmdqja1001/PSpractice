#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000

int n, m, cnt;
vector<int> graph[MAX];
bool visited[MAX];
queue<int> bfsq;

void BFS(int a){        //start at 0
    while(!bfsq.empty()){
        int temp = bfsq.front();
        bfsq.pop();
        for(int i=0; i<graph[temp].size(); i++){
            if(!visited[graph[temp][i]]){
                visited[graph[temp][i]] = 1;
                bfsq.push(graph[temp][i]);
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
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfsq.push(i);
            visited[i] = true;
            BFS(i);
        }
    }
    cout << cnt;

}
