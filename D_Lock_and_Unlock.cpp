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
    vector<ll> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(begin(arr), end(arr));
    int l = 0;
    while(l<n-1 && arr[l]==arr[l+1]){
        l++;
    }
    int r = n-1;
    while(r>0 && arr[r]==arr[r-1]){
        r--;
    }

    ll cost = 0;
    ll ops = 0;
    while(l<r){
        ll ops1 = (arr[l+1] - arr[l]);
        ll ops2 = (arr[r] - arr[r-1]);
        ll cost1 = (arr[l+1] - arr[l]) * (ll)(l+1);
        ll cost2 = (arr[r] - arr[r-1]) * (ll)(n - r);
        if((l+1)<=(n-r)){
            cost += cost1;
            ops += (arr[l+1] - arr[l]);
            l++;
            while(l<r && arr[l+1]==arr[l]){
                l++;
            }
        }else{
            cost += cost2;
            ops += (arr[r] - arr[r-1]);
            r--;
            while(l<r && arr[r]==arr[r-1]){
                r--;
            }
        }
    }
    cout<<cost<<" "<<ops<<endl;
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