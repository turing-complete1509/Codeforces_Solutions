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
    int n;
    cin>>n;
    int k = 0;
    for(int i=1; i<=n; i++){
        k |= i;
    }
    k *= 2;
    int msb = 31;
    for(int i=31; i>=0; i--){
        if((k&(1<<i))!=0){
            msb = i;
            break;
        }
    }
    // cout<<msb<<endl;
    vector<int> count(32, 0);
    for(int i=1; i<=n; i++){
        for(int j=31; j>=0; j--){
            if((i&(1<<j))!=0){
                count[j]++;
            }
        }
    }
    vector<int> res(n+1, 0);
    int i = msb;
    while(i>=1){
        if(count[i]%2==0){
            res[1<<(i-1)] = 1;
            count[i]++;
            count[i-1]--;
        }
        i--;
    }
    for(int i=1; i<=n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
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