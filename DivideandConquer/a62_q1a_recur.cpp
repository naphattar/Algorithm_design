#include<iostream>
int arr[260][260];
using namespace std;
void solve(int a ,int b ,int x ,int y){
    if(a == 0){
        arr[x][y] = b;
        return;
    }
    int da = 1 << (a-1);
    solve(a-1,b,x,y);
    solve(a-1,b-1,x+da,y);
    solve(a-1,b+1,x,y+da);
    solve(a-1,b,x+da,y+da);
    return;
}

int main(){
    ios_base::sync_with_stdio(false),cout.tie(nullptr);
    int a,b;
    cin >> a >> b;
    solve(a,b,0,0);
    int s = 1 << a;
    for(int j = 0;j<s;j++){
        for(int i = 0;i<s;i++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}