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
    string s;
    cin>>s;

    stack<int> indexes;
    unordered_set<int> printed;

    for(int i=1; i<=n; i++){
        int val = s[i-1]-'0';
        if(val==1){
            indexes.push(i);
        }else if(val==2){
            if(indexes.empty()){
                printed.insert(i);
            }else{
                int idx = indexes.top();
                indexes.pop();
                printed.insert(idx);
            }
        }else{
            printed.insert(i);
        }
    }
    vector<int> not_printed;
    for(int i=1; i<=n; i++){
        if(printed.find(i)==printed.end()){
            not_printed.push_back(i);
        }
    }
    cout<<not_printed.size()<<endl;
    for(int num : not_printed){
        cout<<num<<" ";
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