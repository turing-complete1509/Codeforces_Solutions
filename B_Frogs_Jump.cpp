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
    vector<string> arr(2);
    for(int i=0; i<2; i++){
        cin>>arr[i];
    }
    vector<vector<bool>> occ(2, vector<bool>(n, false));
    int total = 0;
    int paired = 0;
    vector<int> delr = {-1, +1, 0, -1, +1};
    vector<int> delc = {0, 0, +1, +1, +1};
    for(int j=0; j<n; j++){
        for(int i=0; i<2; i++){
            if(arr[i][j]=='o' || occ[i][j]){
                continue;
            }
            for(int k=0; k<5; k++){
                int nr = i+delr[k];
                int nc = j+delc[k];
                if(nr>=0 && nr<2 && nc>=0 && nc<n && arr[nr][nc]=='f' && occ[nr][nc]==false){
                    occ[nr][nc] = true;
                    occ[i][j] = true;

                    break;
                }
            }

        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]=='f'){
                total++;
                if(occ[i][j]){
                    paired++;
                }
            }
            // cout<<occ[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<total-paired<<endl;
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