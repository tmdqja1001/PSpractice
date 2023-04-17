#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(void){
    int n;
    cin >> n;
    int ret = 0;
    int sum = 0;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int buf;
        cin >> buf;
        vec.push_back(buf);
    }
    sort(vec.begin(), vec.end());
    for(auto i : vec){
        sum += i;
        ret += sum;
    }
    cout << ret;
}
