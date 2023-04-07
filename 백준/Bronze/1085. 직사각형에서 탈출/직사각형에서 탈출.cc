#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int ret = min(x, y);
    ret = min(ret, w-x);
    ret = min(ret, h-y);
    cout << ret << '\n';
}