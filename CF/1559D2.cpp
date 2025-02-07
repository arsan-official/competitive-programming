#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
#define FORINC(i, a, n) for(int i=a; i<n; i++)
#define FORDEC(i, a, n) for(int i=n - 1; i>=a; i--)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

ll modmul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll modpow (ll a, ll b) {
    a %= MOD;
    if(b == 1) return a;
    if(b == 0) return 1;
    if(b & 1) {
        return modmul(modpow(a, b - 1), a);
    } else {
        ll res = modpow(a, b >> 1);
        return modmul(res, res);
    }
}

ll comb(ll n, ll k, vi &factorial) {
    ll nk = n - k;
    k = modpow(factorial[k], MOD - 2);
    nk = modpow(factorial[nk], MOD - 2);
    return modmul(modmul(factorial[n], k), nk);
}

void scanArray(vi &arr, int n) {
    FORINC(i, 0, n)
        cin>>arr[i];
}

int find(int n, vi &par) {
    if(par[n] != n) return par[n] = find(par[n], par);
    return n;
}

void prog() {
    int n, m1, m2;
    cin>>n>>m1>>m2;
    vi par1(n), par2(n);
    vector<pii> ans;
    set<int> groups1, groups2;
    for(int i=0; i<n; i++)
        par1[i] = i, par2[i] = i;
    for(int i=0; i<m1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        int parSrc1 = find(u, par1), parDst1 = find(v, par1);
        par1[parSrc1] = par1[parDst1];
    }
    for(int i=0; i<m2; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        int parSrc2 = find(u, par2), parDst2 = find(v, par2);
        par2[parSrc2] = par2[parDst2];
    }
    for(int i=0; i<n; i++) {
        groups1.insert(find(i, par1));
        groups2.insert(find(i, par2));
    }
    int lasti=-1, lastj=-1;
    while(groups1.size() >= 2U) {
        int i = *groups1.begin();
        groups1.erase(groups1.begin());
        int j = *groups1.begin();
        groups1.erase(groups1.begin());
        groups1.insert(i);
        groups1.insert(j);
        lasti = i, lastj = j;
        int parSrc1 = find(i, par1), parDst1 = find(j, par1);
        if(parSrc1 == parDst1) continue;
        int parSrc2 = find(i, par2), parDst2 = find(j, par2);
        if(parSrc2 == parDst2) continue;
        groups1.erase(i);
        groups1.erase(j);
        par1[parSrc1] = par1[parDst1];
        par2[parSrc2] = par2[parDst2];
        groups1.insert(find(i, par1));
        groups1.insert(find(j, par1));
        ans.push_back(mp(i + 1, j + 1));
    }
    for(int i=0; i<n; i++) {
        groups1.insert(find(i, par2));
        groups2.insert(find(i, par2));
    }
    while(groups2.size() >= 2U) {
        int i = *groups2.begin();
        groups2.erase(groups2.begin());
        int j = *groups2.begin();
        groups2.erase(groups2.begin());
        groups1.insert(i);
        groups1.insert(j);
        int parSrc1 = find(i, par1), parDst1 = find(j, par1);
        if(parSrc1 == parDst1) continue;
        int parSrc2 = find(i, par2), parDst2 = find(j, par2);
        if(parSrc2 == parDst2) continue;
        groups1.erase(i);
        groups1.erase(j);
        par1[parSrc1] = par1[parDst1];
        par2[parSrc2] = par2[parDst2];
        groups2.insert(find(i, par2));
        groups2.insert(find(j, par2));
        ans.push_back(mp(i + 1, j + 1));
    }
    cout<<ans.size()<<'\n';
    for(auto i: ans) cout<<i.first<<' '<<i.second<<'\n';
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}