#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

string table = "0123456789";
int small_size;
int big_size;

bool checkTable(int a){     // if integer "a" can be made of table -> return true // else return false
    if(a<0) return false;
    string buf = to_string(a);
    bool ret;
    for(int i=0; i<buf.size(); i++){
        ret = false;
        for(int j=0; j<table.size(); j++){
            if(table[j] == buf[i]) ret = true;
        }
        if(ret == false) return ret;
    }
    return ret;
}

int main(void){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int buf;
        cin >> buf;
        auto iter = table.find('0'+ buf);
        table.erase(iter, 1);
    }

    if(m == 10){
        cout << abs(n-100);
        return 0;
    }

    int cnt = 0;
    int ret = 0;
    while(1){
        if(checkTable(n-cnt)){
            string buf = to_string(n-cnt);
            ret += cnt;
            ret += buf.size();
            break;
        }

        if(checkTable(n+cnt)){
            string buf = to_string(n+cnt);
            ret += cnt;
            ret += buf.size();
            break;
        }
        cnt++;
    }

    cout << min(abs(n-100), ret);


}
