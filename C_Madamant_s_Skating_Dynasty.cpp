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

const int MOD = 998244353;

template <typename T>
void debug(const vector<T>& arr) {
    for(const auto& x: arr) cout << x << " ";
    cout << nl;
}

long long gcd(long long a, long long b) { return b==0?a:gcd(b,a%b); }
long long lcm(long long a, long long b) { return (a/gcd(a,b))*b; }

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n, 0);
    ll product = 1;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=1; i<n; i++){
        product = (product * i)%MOD;
    }
    sort(begin(a), end(a));
    vector<ll> b(n, 0);
    b[n-1] = 0;
    ll sum = a[n-1]%MOD;
    ll res = 0;
    for(int i=n-2; i>=0; i--){
        ll sub = ((ll)(n-i-1) * a[i]%MOD)%MOD;
        ll val = (sum - sub + MOD)%MOD;
        sum = (sum +  a[i])%MOD;
        ll w = (product * modInverse(n-i-1))%MOD;
        res = (res + (w * val)%MOD)%MOD;
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