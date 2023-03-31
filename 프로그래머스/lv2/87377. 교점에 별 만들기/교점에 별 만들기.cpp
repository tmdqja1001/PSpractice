#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<vector<long long>> crossing;
    long long MAX_X = LLONG_MIN;
    long long MAX_Y = LLONG_MIN;
    long long MIN_X = LLONG_MAX;
    long long MIN_Y = LLONG_MAX;
    int N = line.size();
    long long x, y;
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            long long A = line[i][0];
            long long B = line[i][1];
            long long E = line[i][2];
            long long C = line[j][0];
            long long D = line[j][1];
            long long F = line[j][2];
            long long demo = A * D - B * C;
            long long numx = B * F - E * D;
            long long numy = E * C - A * F;
            if(demo){
                if(numx%demo) continue;
                if(numy%demo) continue;
                x = numx/demo;
                y = numy/demo;
                crossing.push_back({x,y});
                MAX_X = max(MAX_X, x);
                MAX_Y = max(MAX_Y, y);
                MIN_X = min(MIN_X, x);
                MIN_Y = min(MIN_Y, y);
            }
        }
    }
    
    for(long long i=MAX_Y; i>=MIN_Y; i--){
        string tmp = "";
        for(long long j=MIN_X; j<=MAX_X; j++){
            int star = 0;
            for(auto p : crossing){
                vector<long long> point = {j, i};
                if(p == point) star = 1;
            }
            if(star) tmp += "*";
            else tmp += ".";
        }
        answer.push_back(tmp);
    }
    return answer;
}