#include <iostream>
#include <vector>
#include <cstdlib>  // abs
#include <queue>    // bfs queue
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


using namespace std;

int shark_size = 2;
int n; // size of map
int space[20][20];
int visited[20][20];
int pos_r, pos_c; // position of shark
int time = 0;
int exper = 0;
queue<vector<int>> bfsq;
const int direction[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}; // counter clockwise, start at top

void initialize(void){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }
    //while(!bfsq.empty()) bfsq.pop();
}


int BFS(void){
    initialize();
    bfsq.push({pos_r, pos_c});
    int next_r, next_c;
    int min_r = 20;
    int min_c = 20;
    int ret;
    bool eat_fish = false;
    while(!bfsq.empty()){
        int row = bfsq.front()[0];
        int col = bfsq.front()[1];
        bfsq.pop();

        for(int i=0; i<4; i++){
            next_r = row + direction[i][0];
            next_c = col + direction[i][1];
            if(next_r < 0 || next_r >= n) continue;
            if(next_c < 0 || next_c >= n) continue; // out of map
            if(visited[next_r][next_c] != 0) continue; // visited
            if(space[next_r][next_c] > shark_size) continue; // can't move

            visited[next_r][next_c] = visited[row][col] + 1;
            int fish_size = space[next_r][next_c];
            if(fish_size != 0 && fish_size < shark_size){
                if(eat_fish && ret < visited[next_r][next_c]){
                    while(!bfsq.empty()){
                        bfsq.pop();
                    }
                    break;
                }

                eat_fish = true;
                ret = visited[next_r][next_c];
                if(next_r < min_r){
                    min_r = next_r;
                    min_c = next_c;
                }
                else if(next_r == min_r){
                    if(next_c < min_c){
                        min_c = next_c;
                    }
                }
            }
            else{
                bfsq.push({next_r, next_c});
            }
        }
    }
    if(eat_fish){
        exper++;
        if(exper == shark_size && shark_size < 7){
            exper = 0;
            shark_size++;
        }
        pos_r = min_r;
        pos_c = min_c;
        space[pos_r][pos_c] = 0;
        return ret;
    }
    else return 0;
}

int main(void){
    fastio
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> space[i][j];
            if(space[i][j] == 9){
                pos_r = i;
                pos_c = j;
                space[i][j] = 0;
            }
        }
    }

    int one_time = 1;

    while(one_time){
        one_time = BFS();
        time += one_time;
    }
    //print();
    cout << time;
}
