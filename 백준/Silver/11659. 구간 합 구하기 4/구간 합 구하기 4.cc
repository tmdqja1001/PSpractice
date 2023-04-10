#include <iostream>
#define MAX 100000

using namespace std;

int arr[MAX];
int suffixum[MAX+1];
int n, m;

int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> n >> m;
    int sum = 0;
    for(int i=0; i<n; i++){
        suffixum[i] = sum;
        cin >> arr[i];
        sum += arr[i];
    }
    suffixum[n] = sum;
    for(int i=0; i<m; i++){
        int s, e;
        cin >> s >> e;
        cout << suffixum[e] - suffixum[s-1] << '\n';
    }
}

