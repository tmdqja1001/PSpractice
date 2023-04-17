#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)


int main(void){
    fastio;
    int n;
    int s = 0;
    int zero = 0;
    int ffff = ~zero;
    cin >> n;
    string op;
    int x;
    for(int i=0; i<n; i++){
        cin >> op;
        if(op == "add"){
            cin >> x;
            x = (1 << x);
            s |= x;
        }
        else if(op == "remove"){
            cin >> x;
            x = (1 << x);
            x = ~x;
            s &= x;
        }
        else if(op == "check"){
            cin >> x;
            int temp = (s >> x);
            temp &= 1;
            cout << temp << '\n';
        }
        else if(op == "toggle"){
            cin >> x;
            x = (1 << x);
            s ^= x;
        }
        else if(op == "all"){
            s |= ffff;
        }
        else if(op == "empty"){
            s &= zero;
        }
    }
}
