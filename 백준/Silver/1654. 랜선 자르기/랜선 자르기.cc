#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define fastio ios::sync_with_stdio(0),cin.tie(0)

using namespace std;

int k, n;

int main(void){
    cin >> k >> n;
    vector<int> table;
    for(int i=0; i<k; i++){
        int buf;
        cin >> buf;
        table.push_back(buf);
    }
    sort(table.begin(), table.end());
    int cnt = 0;
    long long start = 1;
    long long end = table[k-1];
    long long dividend;
    long long ans = 1;
    while(start <= end){
        cnt = 0;
        dividend = (start+end)/2;
        for(int i=0; i<k; i++){
            cnt += table[i]/dividend;
        }
        if(cnt < n) end = dividend-1;
        else{
            start = dividend+1;
            ans = max(dividend, ans);
        } 
    }
    cout << ans << '\n';
    return 0;
}
