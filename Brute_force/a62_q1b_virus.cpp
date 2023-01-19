#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
string st = "";

bool check(string s , int k){
    if(k == 1){
        return (s == "01");
    }
    string ft = s.substr(0,s.length()/2);
    string ftr = ft;
    reverse(ftr.begin(),ftr.end());
    string bk = s.substr(s.length()/2,s.length()/2);
    return (check(ft,k-1) || check(ftr,k-1)) && check(bk,k-1); 

}
void solve(int k){
    for(int i = 0;i<pow(2,k);i++){
        char c;
        cin >> c;
        st.push_back(c);
    }
    //cout << st << "\n";
    string ans =  check(st,k) ?  "yes" : "no" ;
    cout << ans <<  "\n";
    st = "";
}
int main(){
    ios_base::sync_with_stdio(false),cout.tie(nullptr);
    cin >> n >> k;
    while(n--){
        solve(k);
    }
    return 0;
}