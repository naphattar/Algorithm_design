#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,x,cnt=2;
vector<int> v = {0,1,3};
void genv(){
    while(v.back() < 2e9+1){
        int addv = upper_bound(v.begin(),v.end(),cnt) - v.begin();
        v.push_back(v.back()+addv);
        cnt++;
    }
}   
int solve(int x){
    int l = 1,r = cnt,mid;
    while( l < r){
        mid = (l+r)/2;
         if(v[mid] >= x){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    genv();
    while(n--){
        cin >> x;
        cout << solve(x) << "\n";
    }
    return 0;
}