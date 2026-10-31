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

int triadValue(int idx, vector<int>& arr){
    if(arr.size()-idx<5){
        return 1e9;
    }
    int sum = 0;
    sum += arr[idx];
    sum += arr[idx+2];
    sum -= arr[idx+4];
    return sum;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    map<int,int> mpp;
    ll res = 0;
    for(int i=n-6; i>=0; i--){
        int triad1 = triadValue(i, arr);
        int triad2 = triadValue(i+1, arr);
        int triad3 = triadValue(i+3, arr);
        if(triad1==triad2){
            res++;
        }
        if(triad1==triad3){
            res++;
        }
        int j = i+5;
        if(n-j>=5){
            mpp[triadValue(j, arr)]++;
        }
        res += mpp[triad1];
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