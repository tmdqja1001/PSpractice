#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;

bool cmp(vector<string> a, vector<string> b) // sort
{
	return a[1]<b[1];
}

int time(string a){ // (string) hh:mm -> (int) minute
    int ret = 0;
    ret += stoi(a.substr(0,2))*60;
    ret += stoi(a.substr(3,2));
    return ret;    
}

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), &cmp); // 시작 시간에 따른 오름차순 정렬
    vector<string> answer;
    int len = plans.size();
    int start = time(plans[0][1]);          // 첫 과제의 시작 시간
    int task = stoi(plans[0][2]);
    int t;
    int red; // 여유시간
    vector<int> remain_time;                // 스택 (잔업의 시간)
    vector<string> remain_task;             // 스택 (잔업의 이름)
    
    for(int i=1; i<len; i++){
        t = time(plans[i][1]);
        red = t - start - task;
        if(red < 0){
            red *= -1;
            remain_time.push_back(red);
            remain_task.push_back(plans[i-1][0]);
        }
        else{
            answer.push_back(plans[i-1][0]);
            if(red > 0){
                while(!remain_task.empty() && red > 0){
                    if(remain_time.back() <= red){
                        red -= remain_time.back();
                        remain_time.pop_back();
                        answer.push_back(remain_task.back());
                        remain_task.pop_back();
                    }
                    else{
                        remain_time.back() -= red;
                        red = 0;
                    }
                }
            }
        }        
        start = time(plans[i][1]);
        task = stoi(plans[i][2]);
    }
    answer.push_back(plans[len-1][0]);
    while(!remain_task.empty()){
        answer.push_back(remain_task.back());
        remain_task.pop_back();
    }
    return answer;
}