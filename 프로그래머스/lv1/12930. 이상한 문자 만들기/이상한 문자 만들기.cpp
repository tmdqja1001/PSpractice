#include <string>
#include <vector>

using namespace std;

char large(char a){
    if(a<='z' && a>='a') return a-32;
    else return a;
}

char small(char a){
    if(a<='Z' && a>='A') return a+32;
    else return a;
}

string solution(string s) {
    string answer = "";
    int index = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            answer += ' ';
            index = 0;
        }
        else{
            if(index%2){
                answer += small(s[i]);
                index++;
            }
            else{
                answer += large(s[i]);
                index++;
            }
        }
    }
    return answer;
}