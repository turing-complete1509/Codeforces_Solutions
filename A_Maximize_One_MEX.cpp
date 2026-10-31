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

int f(vector<int>& arr, int k, int n){
    vector<int> p;
    set<int> present;
    int curr = 0;
    for(int i=0; i<n; i++){
        present.insert(arr[i]);
        while(present.find(curr)!=present.end()){
            curr++;
        }
        p.push_back(curr);
    }
    sort(begin(p), end(p));
    return p[n - k];
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int res = f(arr, k, n);
    vector<int> ans = {-1, -1};
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            

            int val = f(arr, k, n);
            if(val>res){
                ans = {i, j};
                res = val;
            }

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    if(ans[0]==-1){
        cout<<-1<<endl;
        return;
    }else{
        cout<<ans[0]+1<<" "<<ans[1]+1<<endl;
        return;
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