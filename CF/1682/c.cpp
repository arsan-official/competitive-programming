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
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    queue<int> q;
    for(int i=0; i<n; i++) q.push(arr[i]);
    vi aa, bb;
    while(!q.empty()) {
        if ((aa.empty() || aa.back() < q.front()) && aa.size() <= bb.size()) {
            aa.push_back(q.front());
        } else if(bb.empty() || bb.back() < q.front()) {
            bb.push_back(q.front());
        }
        q.pop();
    }
    int ans = min(aa.size(), bb.size());
    for(unsigned i=0; i<aa.size(); i++) {
        auto it = (unsigned)(lower_bound(bb.begin(), bb.end(), aa[i]) - bb.begin());
        if(it >= bb.size() || bb[it] != aa[i]) {
            ans = max(ans, (int)min(aa.size(), bb.size() + 1));
        }
    }
    for(unsigned i=0; i<bb.size(); i++) {
        auto it = (unsigned)(lower_bound(aa.begin(), aa.end(), bb[i]) - aa.begin());
        if(it >= aa.size() || aa[it] != bb[i]) {
            ans = max(ans, (int)min(bb.size(), bb.size() + 1));
        }
    }
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1682/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1682/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}