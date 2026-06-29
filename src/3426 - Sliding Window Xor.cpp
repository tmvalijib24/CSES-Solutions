/*
Problem Name: Sliding Window Xor
Problem Link: https://cses.fi/problemset/task/3426
Author: Taha Valiji (tmvalijib24)
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<pll> vpll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define pyes cout << "YES\n"
#define pno cout << "NO\n"
#define forn(i, n) for (ll i = 0LL; i < n; i++)
#define srt(a) sort(a.begin(), a.end())
#define len(x) ll((x).size())
const ll MOD = 1e9 + 7;

template <class T>
using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using MultiTree = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void solve() {
    ll n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    vll p(n);
    p[0] = x;
    for (int i = 1; i < n; i++) p[i] = (a * p[i - 1] + b) % c;
    ll l = 0, cnt = 0, res = 0;
    forn (r, n) {
        cnt ^= p[r];
        while (r - l + 1 == k) {
            res ^= cnt;
            cnt ^= p[l++];
        }
    }
    cout << res << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    ll tt = 1; 
    // cin >> tt;
    while (tt--) solve();
    return 0;
}