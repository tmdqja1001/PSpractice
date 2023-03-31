#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int q = s / n;
    if(q){
        for(int i=0; i<n; i++){
            answer.push_back(q);
        }
        int rem = s % n;
        for(int i=0; i<rem; i++){
            answer[n-i-1]++;
        }
    }
    else{
        answer.push_back(-1);
    }
    return answer;
}