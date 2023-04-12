#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

priority_queue<int> pq;


int main(void){
    fastio
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int buf;
        cin >> buf;
        if(buf == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(buf);
        }
    }

}
