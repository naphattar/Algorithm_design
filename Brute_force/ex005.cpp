#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n,k;
void solve(int n ,vector<int> &sol , int len , int cnt, int maxcnt){ // maxcnt keep the value of most Consecutive Ones
    if(len < n){
       sol[len] = 0;
       solve(n,sol,len+1,0,maxcnt);
       sol[len] = 1;
       if(len > 0 ){
        if(sol[len-1] == 1 ){
            solve(n,sol,len+1,cnt+1,max(cnt+1,maxcnt));
        }else{
            solve(n,sol,len+1,1,max(maxcnt,1));
        }
       }else{
            if(sol[len] == 1){
                solve(n,sol,len+1,1,1);
            }else{
                solve(n,sol,len+1,0,0);
            }
       }

    }else if(maxcnt >= k){
        for(int i = 0;i<n;i++){
            cout << sol[i];
        }
        //cout << " " << cnt;
        cout << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false) , cout.tie(nullptr);
    cin >> n >> k;
    vector<int> sol(n,0);
    solve(n,sol,0,0,0);
    return 0;
}