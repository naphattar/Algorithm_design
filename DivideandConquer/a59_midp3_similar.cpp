#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a,b;

bool sim(string x,string y){
    if(x == y) return true;
    if(x.length() == 1) return false;
    long long sizex = x.length(),sizey = y.length();
    string x1 = x.substr(0,sizex/2);
    string x2 = x.substr(sizex/2,sizex/2);
    string y1 = y.substr(0,sizey/2);
    string y2 = y.substr(sizey/2,sizey/2);
    return ((sim(x1,y1) && sim(x2,y2)) || (sim(x1,y2) && sim(x2,y1)));

}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> a >> b;
    string ans =  sim(a,b) ? "YES" : "NO";
    cout << ans;
    return 0;
}