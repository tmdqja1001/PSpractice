#include <iostream>

using namespace std;
long long getCombi(int n, int r){
    long long ret = 1;
    for(int i=0; i<r; i++){
        ret *= n-i;
        ret /= (i+1);
    }
    return ret;
}


int main(void){
    int TC;
    cin >> TC;
    for(int i=0; i<TC; i++){
        int n, m;
        cin >> n >> m;
        cout << getCombi(m, m-n) << endl;
    }
    return 0;

}
