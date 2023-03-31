#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<int> arr[3][2][2][2];

int makeNum(string s)
{
    if(s=="cpp" || s=="backend" || s=="junior" || s=="chicken" )
        return 0;
    else if(s=="java" || s=="frontend" || s=="senior" || s=="pizza")
        return 1;
    else if(s=="python")
        return 2;
    else if(s=="-")
        return -1;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    //1 - 0,1,2 = cpp, java, python
    //2 - 0,1   = backend, frontend
    //3 - 0,1   = junior, senior
    //4 - 0,1   = chicken, pizza

    //info로 배열 생성
    for(int i=0;i<info.size();i++)
    {
        string infoS = info[i];
        string tmp = "";
        vector<int> saveNum;
        for(int j=0;j<infoS.length();j++)
        {
            if(infoS[j] == ' '){
                saveNum.push_back( makeNum(tmp) );
                tmp = "";
            }
            else{
                tmp += infoS[j];
            }
        }

        arr[saveNum[0]][saveNum[1]][saveNum[2]][saveNum[3]].push_back(stoi(tmp));
    }


    //query
    for(int i=0;i<query.size();i++)
    {
        string tmpS = query[i];
        string tmp = "";
        vector<int> saveQuery;
        for(int j=0;j<tmpS.size();j++)
        {
            if(tmpS[j] == ' '){
                if(tmp == "and"){
                    tmp = "";
                }
                else{
                    saveQuery.push_back( makeNum(tmp) );
                    tmp = "";
                }
            }
            else{
                tmp += tmpS[j];
            }
        }

        int minNum = stoi(tmp);
        int cnt = 0;
        for(int a=0;a<=2;a++)
        {
            if(saveQuery[0] != -1){
                if(saveQuery[0] != a){
                    continue;
                }
            }
            for(int b=0;b<=1;b++)
            {
                if(saveQuery[1] != -1){
                    if(saveQuery[1] != b){
                        continue;
                    }
                }
                for(int c=0;c<=1;c++)
                {
                    if(saveQuery[2] != -1){
                        if(saveQuery[2] != c){
                            continue;
                        }
                    }
                    for(int d=0;d<=1;d++)
                    {
                        if(saveQuery[3] != -1){
                            if(saveQuery[3] != d){
                                continue;
                            }
                        }

                        for(int x=0;x<arr[a][b][c][d].size();x++)
                        {
                            if(arr[a][b][c][d][x] >= minNum){
                                cnt += 1;
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}