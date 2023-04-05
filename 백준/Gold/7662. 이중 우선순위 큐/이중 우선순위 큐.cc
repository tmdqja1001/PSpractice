#include <set>
#include <iostream>

using namespace std;

int main(void) {
    int len;
    int TC, N;
    cin >> TC;
    for(int i=0; i<TC; i++){
        cin >> N;
        multiset<int> q; // 오름차순
        len = 0;
        for(int j=0; j<N; j++){
            char operation;
            int number;
            cin >> operation >> number;

            if(operation == 'I'){
                q.insert(number);
            }
            else if(q.empty()){
                continue;
            }
            else if(operation == 'D' && number == 1){
                auto it = q.end();
                it--;
                q.erase(it);
            }
            else if(operation == 'D' && number == -1){
                q.erase(q.begin());
            }
        }
        if(!q.empty()){
            auto it = q.end();
            it--;
            cout << *it << ' ' << *q.begin() << endl;
        }
        else{
            cout << "EMPTY" << endl;
        }
    }
    return 0;
}
