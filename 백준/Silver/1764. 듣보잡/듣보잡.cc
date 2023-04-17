#include <iostream>
#include <map>
#include <string>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void){
    int n, m;
    int cnt=0;
    cin >> n >> m;
    map<string,int> mp;
    for(int i=0; i<n; i++){
        string buf;
        cin >> buf;
        mp[buf]++;
    }
    for(int i=0; i<m; i++){
        string buf;
        cin >> buf;
        mp[buf]++;
        if(mp[buf] == 2) cnt++;
    }
    cout << cnt << '\n';
    for(auto p : mp){
        if(p.second == 2) cout << p.first << '\n';
    }


}
