#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int r,c,maxans = 0;
    cin >> r >> c;
    char arr[r][c];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    int left[r][c] = {{0}};
    int down[r][c] = {{0}};
    for(int i = 0;i<r;i++){
        left[i][c-1] = arr[i][c-1] == '1' ? 1 : 0 ;
        for(int j = c-2;j>=0;j--){
            left[i][j] = arr[i][j+1] == '1' ? left[i][j+1]+1 : 0 ;
        }
    }
    for(int i = r-1;i>=0;i--){
        for(int j = 0;j<c;j++){
            if(i == r-1){
                down[i][j] = arr[i][j] == '1' ? 1: 0 ;
            }else{
                down[i][j] = arr[i][j] == '1' ? down[i+1][j]+1 : 0 ;
            }
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(min(left[i][j],down[i][j]) > maxans){
                maxans = min(left[i][j],down[i][j]);
            }
        }
    }
    cout << maxans;
    return 0;
}