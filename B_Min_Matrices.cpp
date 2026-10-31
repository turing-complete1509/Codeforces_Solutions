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
    int n, k;
    cin>>n>>k;
    if(k<n || k>(2*n-1)){
        cout<<-1<<endl;
        return;
    }
    vector<vector<int>> res(n, vector<int>(n, 0));
    int extra = 2*n - k;
    int num = 1;
    int i = 0;
    while(extra>0){
        res[i][i] = num++;
        extra--;
        i++;
    }
    for(int j=i; j<n; j++){
        res[j][i-1] = num++;
    }
    while(i<n){
        res[0][i] = num++;
        i++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(res[i][j]==0){
                res[i][j] = num++;
            }
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
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