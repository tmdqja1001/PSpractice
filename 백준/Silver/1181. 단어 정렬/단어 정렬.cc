#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if(a.size()==b.size()) return a<b;
    else return a.size()<b.size();
}

int main(void){
    int n;
    cin >> n;
    vector <string> table;
    for(int i=0; i<n; i++){
        string buf;
        cin >> buf;
        table.push_back(buf);
    }
    sort(table.begin(), table.end(), &cmp);

    string delay = table[0];
    cout << delay << '\n';
    for(int i=1; i<n; i++){
        if(delay == table[i]) continue;
        cout << table[i] << '\n';
        delay = table[i];
    }
}
