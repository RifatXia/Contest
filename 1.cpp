#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double pi = acos(-1);

int fx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pop_cnt(int n) {return __builtin_popcount(n);}
int clz(int n) {return __builtin_clz(n);}
int ctz(int n) {return __builtin_ctz(n);}
bool parity(int n) {return __builtin_parity(n);}

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

#define work 5

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : "") << i;
    cerr << '}';
}

void _print() { cerr << "]\n"; }

template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

void RifatXia()
{
    #ifndef ONLINE_JUDGE
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
        freopen("in.txt", "r", stdin);
        freopen("err.txt", "w", stderr);
        freopen("out.txt", "w", stdout);
    #else
        #define debug(x...)
    #endif
}

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define en "\n"
#define ff first
#define ss second
#define sp(x) fixed << setprecision(x)
#define runtime cout << "Runtime: " << clock() * 1.0 / CLOCKS_PER_SEC << en;
#define SORT(v)  sort(v.begin(), v.end());
#define RSORT(v) sort(v.begin(), v.end(), greater<int>())
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define get_bit(num, pos) {num & (1 << pos)}
#define set_bit(num, pos) (num |= (1 << pos))
#define reset_bit(num, pos) {num &= ~(1 << pos)}
#define toggle_bit(num, pos) {num ^= (1 << pos)}
#define valid(nx, ny, row, col) nx >= 0 && nx < row && ny >= 0 && ny < col
#define pii pair <int, int>
#define vi vector <int>
#define vll vector <ll>
#define inf int(2e9)
#define mod int(1e9 + 7)

const int lim = 1e5 + 10;
int parent[lim], len[lim], cnt;

void make_set(int n) {
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        len[i] = 1;
    }
}

int find_set(int v) {
    if(parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(len[a] < len[b])
            swap(a, b);
        parent[b] = a;
        len[a] += len[b];
        cnt--;
    }
}

int main(void)
{
    // RifatXia();
    fast_io

    int n;
    cin >> n;
    vll v(n);
    make_set(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cnt = n;
    map <int, vi> mp;
    make_set(n);
    for(int i = 0; i < n; i++)
    {
        for (ll j = 2; j * j <= v[i]; j++)
        {
            if(v[i] % j == 0)
            {
                mp[j].push_back(i);
                while(v[i] % j == 0)
                    v[i] /= j;
            }    
        }
        if(v[i] > 1)
            mp[v[i]].push_back(i);
    }
    for(auto it : mp)
    {
        vi take = it.ss;
        debug(it.ff, take);
        for(int i = 1; i < take.size(); i++)
        {
            union_set(take[i], take[i - 1]);
        }
    }
    cout << cnt << en;

    return 0;
}