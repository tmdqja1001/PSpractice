#include <string>
#include <vector>

using namespace std;

string del(string s){
    int n = 0;
    for(int i = 0 ; i< s.size()-1 ; i++){
        if(s[i] < s[i+1]){
            n = i;
            break;
        }
        n = i+1;
    }
    s.erase(s.begin() + n);
    return s;
}

string solution(string number, int k) {
    string answer = "";
    for(int i = 0; i<k ; i++) number = del(number);
    answer = number;
    return answer;
}