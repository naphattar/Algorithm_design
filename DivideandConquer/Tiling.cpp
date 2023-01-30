#include<iostream>
using namespace std;
int l,x,y;

void solve(int x,int y,int l,int hx,int hy){
    int check = 0;
    // check which square the hidden block is 
    if(hx < x+l/2 && hy < y+l/2){
        check = 0;
    }else if(hx < x+l/2 && hy >= y+l/2){
        check = 2;
    }else if(hx >= x+l/2 && hy < y+l/2){
        check = 1;
    }else{
        check = 3;
    }
    if(l == 2){
        cout << check << " " <<  x << " " << y << "\n";
        return;
    }
        // place the connected one 
        cout << check <<" " <<  x+l/2-1 << " " << y+l/2-1 << "\n";
        switch(check){
            case 0:
                solve(x,y,l/2,hx,hy);
                solve(x+l/2,y,l/2,x+l/2-1,y+l/2-1);
                solve(x,y+l/2,l/2, x+l/2-1, y+l/2);
                solve( x+l/2, y+l/2,l/2,x+l/2,y+l/2);
                break;
            case 1:
                solve(x,y,l/2,x+l/2-1,y+l/2-1);
                solve(x+l/2,y,l/2,hx,hy);
                solve(x,y+l/2,l/2, x+l/2-1, y+l/2);
                solve( x+l/2, y+l/2,l/2,x+l/2,y+l/2);
                break;
            case 2:
                solve(x,y,l/2,x+l/2-1,y+l/2-1);
                solve(x+l/2,y,l/2,x+l/2-1,y+l/2-1);
                solve(x,y+l/2,l/2,hx,hy);
                solve( x+l/2, y+l/2,l/2,x+l/2,y+l/2);
                break;
            case 3:
                solve(x,y,l/2,x+l/2-1,y+l/2-1);
                solve(x+l/2,y,l/2,x+l/2-1,y+l/2-1);
                solve(x,y+l/2,l/2, x+l/2-1, y+l/2);
                solve( x+l/2, y+l/2,l/2,hx,hy);
                break;
            default :
                break;
        }  
    return;  
}

int main(){
    ios_base::sync_with_stdio(false),cout.tie(nullptr);
    cin >> l >> x >> y;
    cout << l*l/3 << "\n";
    solve(0,0,l,x,y);
    return 0;
}