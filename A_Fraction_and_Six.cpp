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
    int x, y;
    cin>>x>>y;
    string n;
    cin>>n;
    string d;
    cin>>d;
    vector<int> a(26, 0);
    for(int i=0; i<x; i++){
        a[n[i]-'a']++;
    }
    for(int i=0; i<y; i++){
        a[d[i]-'a']--;
    }
    if(a[18]!=1 || a[8]!=1 || a[23]!=1){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0; i<26; i++){
        if((a[i]>0 && i!=18 && i!=8 && i!=23) || (a[i]<0)){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    
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