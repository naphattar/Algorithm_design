#include<iostream>
#include<vector>
using namespace std;
vector<long long> v;
int n,cnt=1;
using namespace std;

void genv(){
    v.push_back(3);
    while(v[cnt-1] < n){
        v.push_back(2*v[cnt-1]+cnt+3);
        cnt++;
    }
}
void solve(int n,int idx){
    if(n == 0){
        char ans = (idx == 0) ? 'g' : 'a';
        cout << ans;
        return;
    }
    if(idx < v[n-1]){
        solve(n-1,idx);
    }else if(idx < v[n-1]+n+3){
        char ans = (idx == v[n-1]) ? 'g' : 'a';
        cout << ans;
        return;
    }else{
        solve(n-1,idx-v[n-1]-n-3);
    }
}
int main(){
    cin >> n;
    genv();
    solve(cnt-1,n-1);
    return 0;
}