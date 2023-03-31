#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.size();
    if(len == 4 || len == 6){
        for(int i=0; i<len; i++){
        if(s[i] > '9'){
            answer = false;
            break;
        }
        else if(s[i] < '0'){
            answer = false;
            break;
        }
        }
    }
    else{
        answer = false;
    }
    
    return answer;
}