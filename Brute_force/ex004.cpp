#include<iostream>
#include<vector>
#include<string>
using namespace std;
int a,b;
vector<string> solve(int b , int a){
    vector<string> ans;
   if(b == 0){
        return ans;
   }
    if( b == 1){
        if(a == 0){
            ans.push_back("0");
        }else if ( a == 1){
            ans.push_back("1");
        }
        return ans;
    }
    if(a > 0 ){
        vector<string> v1 = solve(b-1,a-1);
        for(auto st : v1){
            st.push_back('1');
            ans.push_back(st);
        }
    }
        vector<string> v2 = solve(b-1,a);
        for(auto st : v2){
            st.push_back('0');
            ans.push_back(st);
        }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false) , cout.tie(nullptr);
    cin >> a >> b;
    vector<string> v = solve(b,a);
    for(auto st : v){
        cout << st << "\n";
    }
    return 0;
}
