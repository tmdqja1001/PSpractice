#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0; // maximum

    vector<string> order{"+-*", "+*-", "*-+", "*+-", "-*+", "-+*"}; // 우선순위
    vector<long long> number; // 토큰
    vector<char> op;
    int len = expression.size();
    int pos = 0;
    int len_tok = 0;
    for(int i=0;i<len-1;i++){
        len_tok++;
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            string tmp = expression.substr(pos,len_tok-1);
            number.push_back(stoi(tmp));
            op.push_back(expression[i]);
            len_tok = 0;
            pos = i+1;
        }
    }
    string tmp = expression.substr(pos);
    number.push_back(stoi(tmp));
    
    for(int i=0; i<6; i++){
        vector<long long> number_tmp = number;
        vector<char> op_tmp = op;
        while(op_tmp.size()){
            for(int k=0; k<3; k++){
                for(int j=0; j<op_tmp.size(); j++){
                    if(op_tmp[j] == order[i][k]){
                        if(op_tmp[j] == '+'){
                            number_tmp[j] += number_tmp[j+1];
                        }
                        else if(op_tmp[j] == '-'){
                            number_tmp[j] -= number_tmp[j+1];
                        }
                        else if(op_tmp[j] == '*'){
                            number_tmp[j] *= number_tmp[j+1];
                        }                        
                        number_tmp.erase(number_tmp.begin() + j + 1);
                        op_tmp.erase(op_tmp.begin() + j);
                        j--;
                    }
                }
            }
        }
        long long current = number_tmp[0];
        if(current < 0) current *= -1;
        answer = max(answer, current);
    }
    return answer;
}