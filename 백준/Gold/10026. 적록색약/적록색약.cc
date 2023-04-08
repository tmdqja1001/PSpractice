#include <iostream>
#include <vector>
#include <string>

#define MAX 100

using namespace std;

int n;
vector<string> paint;
int rgb[MAX][MAX];
int rb[MAX][MAX];
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void print(void);
void set1(int r, int c, char color, int num);
void set2(int r, int c, char color, int num);
int setRGB(void);
int setRB(void);

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        string buf;
        cin >> buf;
        paint.push_back(buf);
    }
    int a = setRGB();
    int b = setRB();
    cout << a << ' ' << b << endl;
}

int setRGB(void){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(rgb[i][j] == 0){
                cnt++;
                set1(i, j, paint[i][j], cnt);
            }
            else continue;
        }
    }
    return cnt;
}

int setRB(void){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(rb[i][j] == 0){
                cnt++;
                set2(i, j, paint[i][j], cnt);
            }
            else continue;
        }
    }
    return cnt;
}

void set1(int r, int c, char color, int num){
    if(rgb[r][c]) return;

    rgb[r][c] = num;
    //print();

    int new_r, new_c;
    for(int i=0; i<4; i++){
        new_r = r+direction[i][0];
        new_c = c+direction[i][1];
        if(new_r < 0 || new_r >= n) continue;
        if(new_c < 0 || new_c >= n) continue;
        if(paint[new_r][new_c] == color) set1(new_r, new_c, color, num);
    }
}

void set2(int r, int c, char color, int num){
    if(rb[r][c]) return;

    rb[r][c] = num;
    //print();

    int new_r, new_c;
    for(int i=0; i<4; i++){
        new_r = r+direction[i][0];
        new_c = c+direction[i][1];
        if(new_r < 0 || new_r >= n) continue;
        if(new_c < 0 || new_c >= n) continue;
        if(paint[new_r][new_c] == color) set2(new_r, new_c, color, num); //R -> R + G -> G
        else if(color == 'R' && paint[new_r][new_c] == 'G') set2(new_r, new_c, paint[new_r][new_c], num); // R -> G
        else if(color == 'G' && paint[new_r][new_c] == 'R') set2(new_r, new_c, paint[new_r][new_c], num); // G -> R
    }
}


void print(void){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << rb[i][j];
        }
        cout << '\n';
    }
}
