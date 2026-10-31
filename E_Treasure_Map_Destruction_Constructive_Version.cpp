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
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> diff(n+1, 0);
    for(int i=0; i<n; i++){
        if(arr[i]!=0 && arr[i]!=-1){
            int si = i - arr[i] + 1;
            int ei = i + arr[i] - 1;
            si = max(0, si);
            ei = min(ei, n-1);
            diff[si]++;
            diff[ei+1]--;
        }
    }
    // cout<<diff[0]<<" ";
    for(int i=1; i<=n; i++){
        diff[i] += diff[i-1];
        // cout<<diff[i]<<" ";
    }
    vector<int> res(n, 0);
    bool flag = true;
    for(int i=0; i<n; i++){
        if(diff[i]>0 && arr[i]==0){
            flag = true;
            break;
        }
        if(diff[i]==0 || arr[i]==0){
            res[i] = 1;
            flag = false;
        }
    }
    if(flag){
        cout<<-1<<endl;
        return;
    }
    vector<int> prev(n, 1e9);
    int p = -1;
    for(int i=0; i<n; i++){
        if(res[i]==1){
            p = i;
        }
        if(p!=-1){
           prev[i] = i-p;
        }
    }
    vector<int> next(n, 1e9);
    int ne = -1;
    for(int i=n-1; i>=0; i--){
        if(res[i]==1){
            ne = i;
        }
        if(ne!=-1){
            next[i] = ne-i;
        }
    }
    for(int i=0; i<n; i++){
        int mini = min(prev[i], next[i]);
        if(arr[i]!=-1 && mini!=arr[i]){
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=0; i<n; i++){
        cout<<res[i];
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