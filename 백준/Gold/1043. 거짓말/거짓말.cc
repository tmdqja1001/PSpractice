#include <iostream>
#include <vector>
#include <queue>

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 50
using namespace std;

int n, m, l;   // n : number of people, m : number of parties, l : number of people who know the truth
int truth[MAX];
bool party[MAX][MAX]; // index [1][2]  1 : party, 2 : people
int buf, ret;
bool visited[MAX];          // people
bool visited_party[MAX];    // party
queue<int> bfsq;

void print(void){
    for(int i=0; i<m; i++){
        cout << visited_party[i] << ' ';
    }
    cout << '\n';
}


void BFS(int a){
    bfsq.push(a);
    visited[a] = 1;
    //print();
    while(!bfsq.empty()){
        int temp;
        temp = bfsq.front();
        bfsq.pop();
        for(int i=0; i<m; i++){
            if(party[i][temp] && !visited_party[i]){
                visited_party[i] = 1;
                for(int j=0; j<n; j++){
                    if(party[i][j] && !visited[j]){
                        visited[j] = 1;
                        bfsq.push(j);
                    }
                }
            }
        }
    }
    return;
}

int main(void){
    // IO
    fastio;
    cin >> n >> m;
    cin >> l;
    for(int i=0; i<l; i++){
        cin >> truth[i];
    }
    for(int i=0; i<m; i++){
        int tem;
        cin >> tem;
        for(int j=0; j<tem; j++){
            cin >> buf;
            party[i][buf-1] = 1;           // -1 for start at 0
        }
    }

    ret = m;
    if(l == 0){ // Special case
        cout << ret;
    }
    else{
        // Normal case
        for(int i=0; i<l; i++){
            buf = truth[i];
            BFS(buf-1);         // -1 for start at 0
        }
        //print();
        for(int i=0; i<m; i++){
            if(visited_party[i]) ret--;
        }
        cout << ret;
    }

}
