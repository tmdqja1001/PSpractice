#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<char, int> hasht;
    unordered_map<string, int> hash;
    string temp = "";
    vector<string> tempv;
    for(int i=0; i<orders.size()-1; i++){
        for(int j=i+1; j<orders.size(); j++){
            hasht.clear();
            tempv.clear();
            temp = "";
            for(char& c : orders[i]){
                hasht[c]++;
            }
            for(char& c : orders[j]){
                hasht[c]++;
            }
            for(auto pair : hasht){
                if(pair.second > 1) temp += pair.first;
            }
            sort(temp.begin(), temp.end());
            for(int k=2; k<= temp.size(); k++){
                vector<bool> v(temp.size() - k, false);
                v.insert(v.end(), k, true);
                do {
                    string temps = "";
                    for(int l = 0; l <temp.size(); l++){
                        if(v[l]) temps += temp[l];
                    }
                    tempv.push_back(temps);
                }while (next_permutation(v.begin(), v.end()));
            }
            for(int k : course){
                for(string l : tempv){
                    if(k == l.size()) hash[l]++;
                }
            }
        }
    }
    vector<int> bysize(11, 0);
    for(auto pair : hash){
        if(pair.second > bysize[pair.first.size()]){ // 길이에 따른 횟수
            bysize[pair.first.size()] = pair.second;
        }
    }
    for(auto pair : hash){
        if(pair.second == bysize[pair.first.size()])
            answer.push_back(pair.first);
    }
    sort(answer.begin(), answer.end());
    return answer;
}