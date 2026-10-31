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
    int m, n;
    cin>>m>>n;
    vector<ll> a(m, 0);
    ll maxi = LLONG_MIN;
    for(int i=0; i<m; i++){
        cin>>a[i];
        maxi = max(maxi, a[i]);
    }
    if(n==1){
        cout<<maxi<<endl;
        return;
    }
    priority_queue<ll> pq;
    pq.push(a[0]);
    ll sum = a[0];
    ll res = LLONG_MIN;
    for(int i=1; i<m; i++){
        if(pq.size()<n-1){
            pq.push(a[i]);
            sum+=a[i];
        }else{
            ll val = ((ll)n * a[i]) - sum;
            res = max(res, val);
            if(pq.top() > a[i]){
                sum -= pq.top();
                pq.pop();
                pq.push(a[i]);
                sum += a[i];
            }
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