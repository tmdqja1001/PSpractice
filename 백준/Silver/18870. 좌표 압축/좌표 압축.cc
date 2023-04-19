#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

bool cmp1(pair<int ,int> a, pair<int ,int> b){
    return a.first < b.first;
}

bool cmp2(pair<int ,int> a, pair<int ,int> b){
    return a.second < b.second;
}

int main(void){
    fastio;
    vector<pair<int ,int>> vec;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int buf;
        cin >> buf;
        vec.push_back({buf, i});
    }
    sort(vec.begin(), vec.end(), cmp1);
    int cnt = 0;
    int num = vec[0].first;
    vec[0].first = cnt;
    for(int i=1; i<n; i++){
        if(num != vec[i].first){
            cnt++;
            num = vec[i].first;
        }
        vec[i].first = cnt;
    }
    sort(vec.begin(), vec.end(), cmp2);
    for(auto p : vec){
        cout << p.first << ' ';
    }
}
