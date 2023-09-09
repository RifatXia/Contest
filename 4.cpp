#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double pi = acos(-1);

int fx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pop_cnt(int n) { return __builtin_popcount(n); }
int clz(int n) { return __builtin_clz(n); }
int ctz(int n) { return __builtin_ctz(n); }
bool parity(int n) { return __builtin_parity(n); }

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

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
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
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
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stderr);
    freopen("out.txt", "a", stdout);
#else
#define debug(x...)
#endif
}

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
#define ull unsigned long long
#define en "\n"
#define ff first
#define ss second
#define sp(x) fixed << setprecision(x)
#define runtime cout << "Runtime: " << clock() * 1.0 / CLOCKS_PER_SEC << en;
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.begin(), v.end(), greater<int>())
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define get_bit(num, pos) \
    {                     \
        num & (1 << pos)  \
    }
#define set_bit(num, pos) (num |= (1 << pos))
#define reset_bit(num, pos) \
    {                       \
        num &= ~(1 << pos)  \
    }
#define toggle_bit(num, pos) \
    {                        \
        num ^= (1 << pos)    \
    }
#define valid(nx, ny, row, col) nx >= 0 && nx < row &&ny >= 0 && ny < col
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define inf int(2e9)
#define mod int(1e9 + 7)

int main(void)
{
    RifatXia();
    fast_io

        int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size();

        vi zero, one;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '0' && a[i] == b[i])
                zero.push_back(i);
            else if (a[i] == '1' && a[i] == b[i])
                one.push_back(i);
        }

        bool ans = false;
        if (a == b)
            ans = true;
        else
        {
            if(zero.size() > 1 && one.size() > 1)
            {
                int one_f = one[0];
                int zero_f = zero[0];
                int one_l = one[one.size() - 1];
                int zero_l = zero[zero.size() - 1];
                string a_x = a;
                string b_x = b;
                // cout << one_f << " " << zero_l << en;
                if(one_f > zero_l)
                {
                    int cnt = zero_l - zero_f + 1;
                    cnt += (one_l - one_f + 1);
                    // for(int i = zero_f; i <= zero_l; i++)
                    // {
                    //     if (a[i] == b[i])
                    //         cnt++;
                    //     else
                    //         break;
                    // }
                    // for(int i = one_f; i <= one_l; i++)
                    // {
                    //     if (a[i] == b[i])
                    //         cnt++;
                    //     else
                    //         break;
                    // }
                    // cout << cnt << en;
                    if(cnt == n)
                        ans = true;
                }+
            }
            if(zero.size() > 1)
            {
                int x = zero[0];
                int y = zero[zero.size() - 1];
                int cnt = y - x + 1;
                for(int i = y + 1; i < n; i++)
                {
                    if(a[i] == b[i])
                        cnt++;
                    else
                        break;
                }
                if(cnt == n)
                    ans = true;
            }
            if(one.size() > 1)
            {
                int x = one[0];
                int y = one[one.size() - 1];
                int cnt = y - x + 1;
                for (int i = 0; i < x; i++)
                {
                    if (a[i] == b[i])
                        cnt++;
                    else
                        break;
                }
                if (cnt == n)
                    ans = true;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}