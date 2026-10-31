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
    string s;
    cin>>s;

    int count = 0;
    vector<int> res(n+1, 0);
    vector<int> inversions;
    int inversionCount = 0;
    for(int i=n-1; i>=0; i--){
        if(arr[i]==0){
            inversionCount++;
        }else{
            count+=inversionCount;
            inversions.push_back(inversionCount);
        }
    }
    
    if(count==0){
        debug(res);
        return;
    }
    int m = inversions.size();
    vector<int> diff(m-1, 0);
    for(int i=0; i<m-1; i++){
        diff[i] = inversions[i] - inversions[i+1];
    }
    vector<int> prefixSum(m-1, 0);
    prefixSum[0] = diff[0];
    for(int i=1; i<diff.size(); i++){
        prefixSum[i] = prefixSum[i-1] + diff[i];
    }

    res[0] = count;
    int count0 = 0;
    int count1 = 0;
    int j = m-1;
    for(int i=1; i<n+1; i++){
        if(count==0 || j<0){
            res[i] = 0;
            continue;
        }
        if(s[i-1]==1){
            count1++;
            count -= inversions[j];
            count -= j>=1 ? prefixSum[j-1] : 0;
            j--;
        }else{
            count0++;
            count -= (j+1);
        }
        res[i] = count;
        while(true){
            int rem = inversions[j];
            rem -= count0;
            rem -= (j==m-1) ? 0 : (count1 * diff[j]);
            if(rem>0){
                break;
            }
            j--;
        }
    }
    debug(res);
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