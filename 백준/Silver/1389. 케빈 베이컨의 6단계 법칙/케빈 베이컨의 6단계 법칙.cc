#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 101

using namespace std;

bool arr[MAX][MAX];         //
queue<pair<int,int>> bfsq;
bool visited[MAX];
int n;                  // number of computers

void initialize(void){
    for(int i=1; i<=n; i++){
        visited[i] = false;
    }
}

int bfs(int a){
    int ret = 0;
    initialize();
    visited[a] = true;
    for(int i=1; i<=n; i++){
        if(arr[a][i] & ~visited[i]){
            bfsq.push({i, 1});
            visited[i] = true;
            ret += 1;
            //cout << i << 1 << '\n';
        }
    }
    while(!bfsq.empty()){
        int com = bfsq.front().first;
        int tem = bfsq.front().second;
        tem++;
        bfsq.pop();
        for(int i=1; i<=n; i++){
            if(arr[com][i] & ~visited[i]){
                //cout << i << tem << '\n';
                bfsq.push({i, tem});
                visited[i] = true;
                ret += tem;
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
    int minim = 10000;
    int ret = 0;
    for(int i=1; i<=n; i++){
        int temp = bfs(i);
        if(temp < minim){
            minim = temp;
            ret = i;
        }
        //cout << temp << endl;
    }
    cout << ret;

}
