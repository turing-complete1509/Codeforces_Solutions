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
    ll sum = 0;
    bool flag = true;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
        if(arr[i]>1){
            flag = false;
        }
    }
    if(flag==true){
        cout<<-1<<endl;
    }else{
        if(arr[0]==1 && arr[n-1]==1){
            cout<<sum-1<<endl;
        }else{
            flag = true;
            for(int i=1; i<n-1; i++){
                if(arr[i]>1){
                    flag = false;
                }
            }
            if(flag){
                cout<<sum-(n-1)<<endl;
            }else{
                cout<<sum-1<<endl;
            }
        }
        
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