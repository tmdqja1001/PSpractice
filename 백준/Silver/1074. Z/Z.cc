#include <iostream>
#include <stack>

using namespace std;

int n, r, c;
int twos_power;
stack<int> area;

void findArea(void){
    if(twos_power == 1) return;
    twos_power /= 2;
    if(r < twos_power && c < twos_power) area.push(0);
    else if(r < twos_power && c >= twos_power) area.push(1);
    else if(r >= twos_power && c < twos_power) area.push(2);
    else if(r >= twos_power && c >= twos_power) area.push(3);

    if(r>= twos_power) r -= twos_power;
    if(c>= twos_power) c -= twos_power;
    findArea();
}

int main(void){
    cin >> n >> r >> c;
    twos_power = 1;
    for(int i=0; i<n; i++){
        twos_power *= 2;
    }
    findArea();

    int ans = 0;
    int fours_power = 1;
    while(!area.empty()){
        int temp = area.top();
        area.pop();
        ans += temp*fours_power;
        fours_power *= 4;
    }
    cout << ans;

}
