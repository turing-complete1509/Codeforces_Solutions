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
    int num1 = 0;
    for(int init=0; init<=1; init++){
        bool flag = true;
        for(int i=0; i<n; i+=2){
            char req = (i/2)%2==init ? '0' : '1';
            if(s[i]!='?' && s[i]!=req){
                flag = false;
                break;
            }
        }
        if(flag){
            num1++;
        }
    }
    int num2 = 0;
    for(int init=0; init<=1; init++){
        bool flag = true;
        for(int i=1; i<n; i+=2){
            char req = ((i-1)/2)%2==init ? '0' : '1';
            if(s[i]!='?' && s[i]!=req){
                flag = false;
                break;
            }
        }
        if(flag){
            num2++;
        }
    }

    cout<<num1*num2<<endl;
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