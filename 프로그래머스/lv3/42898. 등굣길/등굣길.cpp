#include <string>
#include <vector>

using namespace std;

int map[100][100];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // n : 행, m : 열
    for(auto p : puddles){
        map[p[1]-1][p[0]-1] = -1;
    }
    for(int i=0; i<n; i++){ // i : 행
        for(int j=0; j<m; j++){ // j : 열            
            if(map[i][j] == -1){
                map[i][j] = 0;
            }
            else if(j==0 && i==0){
                map[i][j] = 1;
            }
            else if(i==0){
                map[i][j] = map[i][j-1];
            }
            else if(j==0){
                map[i][j] = map[i-1][j];
            }
            else{
                map[i][j] = map[i-1][j] + map[i][j-1];
                map[i][j] %= 1000000007;
            }
        }
    }
    return answer = map[n-1][m-1];
}