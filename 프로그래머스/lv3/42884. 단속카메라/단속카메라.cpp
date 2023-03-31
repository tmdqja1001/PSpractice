#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.rbegin(), routes.rend());
    int answer = 0, flag = 30001;

    for(int i = 0; i < routes.size(); i++){
        if(flag > routes[i][1]){
            flag = routes[i][0];
            answer++;
        }
    }
    return answer;
}