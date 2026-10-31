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

bool isValid(ll k, vector<ll>& arr, int x, int n){
    vector<vector<ll>> dp(n, vector<ll>(2, 1e15));
    
    dp[0][0] = 1; 
    
    for(int i = 1; i < n; i++) {
        ll gap = arr[i] - arr[i-1];
        
        ll gap_cost = max(0LL, (gap + k - 1) / k - 1);
        
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + 1;
        
        ll prev_best = (i >= 2) ? min(dp[i-2][0], dp[i-2][1]) : 0;
        dp[i][1] = min(prev_best, dp[i-1][1]) + gap_cost;
    }
    
    return min(dp[n-1][0], dp[n-1][1]) <= x;
}

void solve() {
    int n, x;
    cin>>n>>x;
    vector<ll> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll low = 1;
    ll high = 1e9;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(isValid(mid, arr, x, n)){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<low<<endl;
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