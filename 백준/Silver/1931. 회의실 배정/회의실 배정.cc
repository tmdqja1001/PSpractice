#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

vector<pair<int, int>> table;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main(void){
    fastio;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int s, e;
        cin >> s >> e;
        table.push_back({s, e});
    }
    sort(table.begin(), table.end(), compare);
    int start = table[0].second;
    int ret = 1;
    for(int i=1; i<n; i++){
        if(table[i].first >= start){
            ret++;
            start = table[i].second;
        }
    }
    cout << ret;

}
