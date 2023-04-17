#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(void){
    fastio;
    int n;
    bool s[20] = { 0 };
    cin >> n;
    string op;
    int x;
    for(int i=0; i<n; i++){
        cin >> op;
        if(op == "add"){
            cin >> x;
            s[x-1] = 1;
        }
        else if(op == "remove"){
            cin >> x;
            s[x-1] = 0;
        }
        else if(op == "check"){
            cin >> x;
            cout << s[x-1] << '\n';
        }
        else if(op == "toggle"){
            cin >> x;
            s[x-1] = !s[x-1];
        }
        else if(op == "all"){
            memset(s, 1, 20 * sizeof(bool));
        }
        else if(op == "empty"){
            memset(s, 0, 20 * sizeof(bool));
        }
    }
}
