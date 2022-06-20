#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vll2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n; cin>>n;
    vi2d arr(2, vi(n)), sorted(2, vi(n));
    #define si sorted[i]
    for(int i=0; i<2; i++) {
        for(auto &j: arr[i]) cin>>j;
        si = arr[i];
        sort(si.begin(), si.end());
    }
    vector<pii> ans;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[0][j] != sorted[0][i] || arr[1][j] != sorted[1][i])
                continue;
            swap(arr[0][j], arr[0][i]);
            swap(arr[1][j], arr[1][i]);
            ans.push_back({i + 1, j + 1});
        }
    }
    bool can = is_sorted(arr[0].begin(), arr[0].end()) && is_sorted(arr[1].begin(), arr[1].end());
    if(!can) {
        cout<<"-1\n";
        return;
    }
    cout<<ans.size()<<"\n";
    for(pii &i: ans) cout<<i.first<<" "<<i.second<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1681/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1681/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}