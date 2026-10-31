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
    map<int,vector<int>> mpp;
    vector<int> uniquenums;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mpp[arr[i]].push_back(i);
        if(mpp[arr[i]].size()==1 && arr[i]!=0){
            uniquenums.push_back(arr[i]);
        }
    }
    if(mpp[0].size()==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    vector<char> res(n, 'A');
    if(mpp[0].size()>=2){
        
        res[mpp[0][1]] = 'B';
        
        for(int num : uniquenums){
            if(mpp[num].size()==1){
                res[mpp[num][0]] = 'C';
            }else{
                res[mpp[num][1]] = 'B';
            }
        }
    }
    for(char ch : res){
        cout<<ch;
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