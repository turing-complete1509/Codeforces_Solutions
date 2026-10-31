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
int lower_bound(int val, vector<int>& arr){
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=val){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    if(low<arr.size()){
        return low;
    }
    return -1;
}
void solve() {
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    vector<int> ones;
    vector<int> minusones;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]==1){
            ones.push_back(i);
        }else if(arr[i]==-1){
            minusones.push_back(i);
        }
    }
    int f = -1;
    int sec = -1;
    int res = 0;
    vector<int> next;
    int nextminusone = -1;
    for(int i=n-1; i>=0; i--){
        if(arr[i]==-1 && nextminusone==-1){
            nextminusone = i;
        }
        if(arr[i]==1){
            next.push_back(nextminusone);
            nextminusone = -1;
        }
    }
    reverse(begin(next), end(next));
    for(int i=0; i<ones.size(); i++){
       
        int idx = next[i];
        if(i!=ones.size()-1){
            int s = ones[i+1] - ones[i] + 1;
            if(s>res){
                res = s;
                f = ones[i];
                sec = ones[i+1];
            }
        }
        if(idx!=-1 && (i==ones.size()-1 || idx<ones[i+1])){
            int s = idx - ones[i]+ 1;
            if(s>res){
                res = s;
                f = ones[i];
                sec = idx;
            }
        }
    }
    vector<int> next2;
    int nextone = -1;
    for(int i=n-1; i>=0; i--){
        if(arr[i]==1){
            nextone = i;
        }
        if(arr[i]==-1){
            next2.push_back(nextone);
        }
    }
    reverse(begin(next2), end(next2));
    for(int i=0; i<minusones.size(); i++){
        int idx = next2[i];
        if(idx==-1 || idx>minusones[minusones.size()-1]){
            int s = minusones[minusones.size()-1] - minusones[i]+ 1;
            if(s>res){
                res = s;
                f = minusones[i];
                sec = minusones[minusones.size()-1];
            }
        }
        if(idx!=-1){
            int s = idx - minusones[i] + 1;
            if(s>res){
                res = s;
                f = minusones[i];
                sec = idx;
            }
        }
    }
    if(res==0){
        for(int i=0; i<n; i++){
            if(arr[i]==-1){
                arr[i]=0;
            }
        }
    }else{

        for(int i=0; i<n; i++){
            if(i>f && i<sec){
                arr[i] = arr[i]==-1 ? 0 : arr[i];
            }else{
                arr[i] = arr[i]==-1 ? 0 : arr[i];
            }
        }
        arr[f] = 1;
        arr[sec] = 1;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
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