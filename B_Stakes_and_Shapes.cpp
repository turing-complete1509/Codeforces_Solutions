/*
 * ___________________________________________________________________________________
 * |                                                                                 |
 * |       _____     _____    _____     _____   _______         _____     _____      |
 * |      |  __ \   |_   _|  / ____|   |_   _| |__   __|       |  __ \   |  __ \     |
 * |      | |  | |    | |   | |  __      | |      | |          | |  | |  | |__) |    |
 * |      | |  | |    | |   | | |_ |     | |      | |          | |  | |  |  ___/     |
 * |      | |__| |   _| |_  | |__| |    _| |_     | |          | |__| |  | |         |
 * |      |_____/   |_____|  \_____|   |_____|    |_|          |_____/   |_|         |
 * |                                                                                 |
 * |      "Kill the boy, and let the man be born."                                   |
 * |_________________________________________________________________________________|
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define all(v) v.begin(), v.end()

template <typename T>
void debug(const vector<T>& arr) {
    for(const auto& x: arr) cout << x << " ";
    cout << nl;
}

long long gcd(long long a, long long b) { return b==0?a:gcd(b,a%b); }
long long lcm(long long a, long long b) { return (a/gcd(a,b))*b; }

void solve() {
    int r,s,p;
    cin>>r>>s>>p;
    int sum = r+s+p;
    string res = "";
    if(r>=s && r>=p){
        for(int i=0; i<sum; i++){
            res+="P";
        }
    }else if(s>=r && s>=p){
        for(int i=0; i<sum; i++){
            res+="R";
        }
    }else{
        for(int i=0; i<sum; i++){
            res+="S";
        }
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}