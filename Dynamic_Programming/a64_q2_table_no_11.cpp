#include<iostream>
using namespace std;
const int md = 100000007;
int main(){
    int n;
    cin >> n;
    int p0 = 1,p1 = 1,p2 = 1;
    int d0 = 1,d1 = 1,d2 = 1;
    for(int i = 2;i<=n;i++){
        d0 = (p0%md+p1%md+p2%md)%md;
        d1 = (p0%md+p2%md)%md;
        d2 = (p0%md+p1%md)%md;
        p0 = d0;
        p1 = d1;
        p2 = d2;
    }
    cout << (d0%md+d1%md+d2%md)%md;
    return 0;
}
