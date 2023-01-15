#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
void gen(){
    int a,b,c,d;
    for(int a = 1;a<=9;a++){
        for(int b = 0;b<=9;b++){
            for(int c = 0 ; c <= 9 ;c++){
                for(int d = 0;d<=9 ;d++){
                    if( a != b && a != c && a != d && b != c && b != d && c != d){
                        v.push_back(1000*a + 100*b+10*c+d);
                    }
                    //cout << v[v.size()-1] << " ";
                }
            }
        }
    }
}
int main(){
    int year; // 1000 <= year <= 9000
    cin >> year; 
    gen();
    auto it = upper_bound(v.begin(),v.end(),year);
    cout << *it;
    return 0;
}