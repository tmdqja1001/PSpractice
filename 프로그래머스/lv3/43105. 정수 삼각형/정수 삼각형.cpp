#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int level = triangle.size() - 1; // 전체 층 수
    for(int i = level-1; i>=0; i--){
        for(int j = 0; j<triangle[i].size(); j++){
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    int answer = triangle[0][0];
    return answer;
}