Factorial mod P const int N = 100001;
long long fac[N];
int fact_mod(int n, int p)
{
    fac[0] = 1;
    for (int i = 1; i < p; i++)
    {
        fac[i] = (fac[i - 1] * i) % p;
    }
    int res = 1;
    while (n > 1)
    {
        if ((n / p) % 2)
        {
            res = p - res;
        }
        res = (res * fac[n % p]) % p;
        n /= p;
    }
    return res;
}

nCr Precalculated const int N = 105, R = 85;
int64_t NCR[N][R];
void genNCR()
{
    for (int i = 0; i < N; ++i)
    {
        NCR[i][0] = 1;
        if (i < R)
            NCR[i][i] = 1;
    }
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            NCR[i][j] = NCR[i - 1][j - 1] + NCR[i - 1][j];
        }
    }
}

nCr long long nCr(int n, int r)
{
    long long N = 1, D = 1;
    r = min(r, n - r);
    if (r > 0)
    {
        while (r > 0)
        {
            N *= n, D *= r;
            long long g = __gcd(N, D);
            N /= g, D /= g;
            --n, --r;
        }
    }
    return N;
}

Disjoint Set Union const int lim =
    int parent[lim],
                             len[lim];

void make_set(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        len[i] = 1;
    }
}

int find_set(int v)
{
    if (parent[v] == v)
        return v;

    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (len[a] < len[b])
            swap(a, b);

        parent[b] = a;
        len[a] += len[b];
    }
}

Segment Tree const int lim =
    ll num[lim],
                       seg[4 * lim], lazy[4 * lim];

void build(int i, int lo, int hi)
{
    if (lo == hi)
    {
        seg[i] = num[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    build(2 * i + 1, lo, mid);
    build(2 * i + 2, mid + 1, hi);

    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}

void update(int i, int lo, int hi, int l, int r, int x)
{
    if (hi < l || lo > r)
        return;

    if (lo >= l && hi <= r)
    {
        lazy[i] += x;
        return;
    }

    if (lazy[i] != 0)
    {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
        lazy[i] = 0;
    }

    int mid = (lo + hi) / 2;
    update(2 * i + 1, lo, mid, l, r, x);
    update(2 * i + 2, mid + 1, hi, l, r, x);

    seg[i] = seg[2 * i + 1] + lazy[2 * i + 1] * (mid - lo + 1) + seg[2 * i + 2] + lazy[2 * i + 2] * (hi - mid);
}

ll sum(int i, int lo, int hi, int l, int r)
{
    if (hi < l || lo > r)
        return 0;

    if (hi <= r && lo >= l)
    {
        return seg[i] + lazy[i] * (hi - lo + 1);
    }

    int mid = (lo + hi) / 2;
    ll ans = sum(2 * i + 1, lo, mid, l, r) + sum(2 * i + 2, mid + 1, hi, l, r);
    seg[i] = seg[2 * i + 1] + lazy[2 * i + 1] * (mid - lo + 1) + seg[2 * i + 2] + lazy[2 * i + 2] * (hi - mid);

    return ans;
}

4.1 Edit Distance[SA] const int N = 2005, INF = 1E6;
int dp[N][N];
int ed(string &s, string &t, int n, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    int &ans = dp[n][m];
    if (ans != -1)
        return ans;
    ans = INF;
    if (s[n - 1] == t[m - 1])
    {
        ans = ed(s, t, n - 1, m - 1);
    }
    ans = min(ans, 1 + min({ed(s, t, n - 1, m),
                            ed(s, t, n, m - 1),
                            ed(s, t, n - 1, m - 1)}));
    return ans;
}

Longest Common Increasing Subsequence const int N = 1005;
int arr1[N + 1], arr2[N + 1];
int dp[N + 1];
int LCIS(int n, int m)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                dp[j] = max(dp[j], mx + 1);
            }
            else if (arr1[i] > arr2[j])
            {
                mx = max(mx, dp[j]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        res = max(res, dp[i]);
    }
    return res;
}

Longest Increasing Subsequence[SA] const int MX_N = 1005;
int dp[MX_N];
int LIS(const vector<int> &a, int n, int i)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 0;
    for (int j = i + 1; j < n; ++j)
    {
        if (a[j] > a[i])
        {
            ans = max(ans, LIS(a, n, j));
        }
    }
    return dp[i] = 1 + ans;
}

int LIS(const vector<int> &a, int n)
{
    int ans = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, LIS(a, n, i));
    }
    return ans;
}

Number of LIS[FR] const int N = 1005;
int arr[N + 1], dp[N + 1], dp_l[N + 1], dp_c[N + 1];
int numberOfLIS(int n)
{
    if (n == 0)
    {
        return 0;
    }
    For(i, 0, n)
    {
        dp_c[i] = 1;
        dp_l[i] = 1;
    }
    For(i, 0, n)
    {
        For(j, 0, i)
        {
            if (arr[i] <= arr[j])
            {
                continue;
            }
            if (dp_l[j] + 1 > dp_l[i])
            {
                dp_l[i] = dp_l[j] + 1;
                dp_c[i] = dp_c[j];
            }
            else if (dp_l[j] + 1 == dp_l[i])
            {
                dp_c[i] += dp_c[j];
            }
        }
    }
    int mx = 0;
    For(i, 0, n)
    {
        mx = max(mx, dp_l[i]);
    }
    int cnt = 0;
    For(i, 0, n)
    {
        if (dp_l[i] == mx)
        {
            cnt += dp_c[i];
        }
    }
    return cnt;
}

Dijkstra’s Algorithm const int N = 100001;
struct Node
{
    int vertex, weight;
};
int dist[N], parent[N];
bool vis[N];
vector<Node> adj[N];
void init()
{
    for (int i = 0; i < N; ++i)
    {
        dist[i] = INT_MAX, parent[i] = -1, vis[i] = false;
    }
}
struct cmp
{
    bool operator()(Node &a, Node &b) const
    {
        return a.weight > b.weight;
    }
};
void dijkstra(int s)
{
    dist[s] = 0, vis[s] = true;
    priority_queue<Node, vector<Node>, cmp> PQ;
    PQ.push({s, 0});
    while (!PQ.empty())
    {
        Node cur = PQ.top();
        PQ.pop();
        int u = cur.vertex;
        for (auto &&[v, w] : adj[u])
        {
            if (!vis[v] && (dist[u] + w) < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                PQ.push({v, dist[v]});
            }
        }
        vis[u] = true;
    }
}

Floyd Warshall Algorithm const int INF = 999999;
void floyd_warshall(vector<vector<int>> &d, int n)
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

Minimum Spanning Tree struct Edge
{
    int u, v, w;
};
int kruskal_mst(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.w < b.w; });
    DisjointSet dsu(n + 1);
    dsu.make_set();
    int res = 0;
    for (auto [u, v, w] : edges)
    {
        if (dsu.find(u) == dsu.find(v))
            continue;
        dsu.unite(u, v);
        res += w;
    }
    return res;
}

Topological Sort[SA] const int N = 10001;
bool visited[N];
vector<int> seq;
void dfs(vector<vector<int>> &adj, int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(adj, v);
    }
    seq.push_back(u);
}
void topological_sort(vector<vector<int>> &adj, int nodes)
{
    for (int i = 1; i <= nodes; ++i)
    {
        if (!visited[i])
            dfs(adj, i);
    }
    reverse(seq.begin(), seq.end());
}

BigMod
    ll
    bigMod(ll a, ll b, ll c)
{
    ll rem = a % c, ans = 1 % c;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * rem) % c;

        rem = (rem * rem) % c;

        b /= 2;
    }
    return ans;
}

Euler’s Totient Function int phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

Prime Factor(O(sqrt(N)))
    const int lim =

        bool prime[lim + 10];
vector<int> pNum, pf, times;

void sieve()
{
    mem(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; (ll)i * i <= lim; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= lim; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= lim; i++)
    {
        if (prime[i])
            pNum.push_back(i);
    }
}

void fact(ll n)
{
    for (int i = 0; i < pNum.size(); i++)
    {
        ll p = pNum[i];

        if (p * p > n)
            break;

        int cnt = 0;
        if (n % p == 0)
        {
            while (n % p == 0)
            {
                n /= p;
                cnt++;
            }
            pf.push_back(p);
            times.push_back(cnt);
        }
    }
    if (n > 1)
    {
        pf.push_back(n);
        times.push_back(1);
    }
}

Prime Factor(O(logN))
    const int lim = 1e7;

bool prime[lim + 10];
vector<int> pNum;

int spf[lim + 10];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i <= lim; i++)
    {
        spf[i] = i;
    }

    for (int i = 4; i <= lim; i += 2)
    {
        spf[i] = 2;
    }

    for (int i = 3; (ll)i * i <= lim; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= lim; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> fact(int n)
{
    vector<int> ans;
    while (n != 1)
    {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}

Factorial Prime Power
    int64_t
    factorial_prime_power(int64_t n, int64_t p)
{
    // number of times p occurs in n, O(nlgn)
    int64_t freq = 0;
    while (n > 0)
    {
        freq += n / p;
        n /= p;
    }
    return freq;
}

Factorial Trailing Zeros
    int64_t
    fact_trailing_zeros(int64_t n)
{
    int64_t count = 0;
    for (int64_t i = 5; i <= n; i *= 5)
        count += (n / i);
    return count;
}

Long Division - Quotient
                    string
                    long_division(string number, int div)
{
    string ans = "";
    int ind = 0;
    int temp = number[ind] - '0';

    while (temp < div)
    {
        temp = temp * 10 + number[++ind] - '0';
    }

    while (number.size() > ind)
    {
        ans += temp / div + '0';
        temp = (temp % div) * 10 + number[++ind] - '0';
    }

    if (ans.size() == 0)
        return "0";
    else
        return ans;
}

Long Division - Remainder int long_division(string number, int div)
{
    int ans = 0;

    for (ll i = 0; i < number.size(); i++)
    {
        ans = (ans * 10 + number[i] - '0') % div;
    }
    return ans;
}

SOD const int lim =

    int num[lim + 5];

void SOD()
{
    for (int i = 1; i <= lim; i++)
    {
        for (int j = i; j <= lim; j += i)
        {
            num[j] += i;
        }
    }
}

NOD const int lim =

    int num[lim + 5] = {};

void NOD()
{
    for (int i = 1; i <= lim; i++)
    {
        for (int j = i; j <= lim; j += i)
        {
            num[j]++;
        }
    }
}

Segmented Sieve[SA] vector<bool> segmented_sieve(int64_t L, int64_t R)
{
    int64_t LIMIT = 1 + sqrt(R);
    vector<bool> mark(LIMIT);
    vector<int64_t> primes;
    for (int64_t i = 2; i < LIMIT; ++i)
    {
        if (!mark[i])
        {
            primes.push_back(i);
            for (int64_t j = i * i; j < LIMIT; j += i)
                mark[j] = true;
        }
    }
    vector<bool> is_prime(R - L + 1, true);
    for (auto &i : primes)
        for (int64_t j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            is_prime[j - L] = false;
    is_prime[0] = L != 1;
    return is_prime;
}

PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;

typedef tree<
    int,         // the data type
    null_type,   // null_type for the set
    less<int>,   // the comparator. less_equal : ascending multimap, greater : descending
    rb_tree_tag, // the tree structure would be red black tree
    tree_order_statistics_node_update

    // find_by_order(index) : finds the element using the index
    // order_of_key(value) : finds the number of elements less than the value
    >
    ordered_set;

Trie - String const int lim = 26;

struct Trie
{
    struct node
    {
        int cnt, val;
        bool ending;

        node *next[lim];
        node *child[2];

        node()
        {
            cnt = 0, val = 0;
            ending = false;
            child[0] = NULL, child[1] = NULL;

            for (int i = 0; i < lim; i++)
                next[i] = NULL;
        }
    } *root;

    void init()
    {
        root = new node();
    }

    void insert_string(string s)
    {
        node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {
            int id = s[i] - 'a';
            if (curr->next[id] == NULL)
                curr->next[id] = new node();

            curr = curr->next[id];
        }

        curr->cnt++;
        curr->ending = true;
    }

    bool search_string(string s)
    {
        node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {
            int id = s[i] - 'a';

            if (curr->next[id] == NULL)
                return false;

            curr = curr->next[id];
        }
        return (curr->ending);
    }

    int word_cnt(string s)
    {
        node *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            int id = s[i] - 'a';
            if (curr->next[id] == NULL)
                return 0;

            curr = curr->next[id];
        }
        return curr->cnt;
    }
};

Trie number struct Trie
{
    struct node
    {
        int cnt, val;
        bool ending;

        node *child[2];

        node()
        {
            cnt = 0, val = 0;
            ending = false;
            child[0] = NULL, child[1] = NULL;
        }
    } *root;

    void init()
    {
        root = new node();
    }

    void insert_num(int n)
    {
        node *curr = root;

        for (int i = 31; i >= 0; i--)
        {
            int id = get_bit(n, i);

            if (curr->child[id] == NULL)
                curr->child[id] = new node();

            curr = curr->child[id];
            curr->cnt++;
        }
        curr->val = n;
    }

    void delete_num(int n)
    {
        node *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int id = get_bit(n, i);

            curr = curr->child[id];
            curr->cnt--;
        }
    }

    bool search_num(int n)
    {
        node *curr = root;

        for (int i = 31; i >= 0; i--)
        {
            int id = get_bit(n, i);

            if (curr->child[id] == NULL)
                return false;

            curr = curr->child[id];
        }
        return (curr->cnt);
    }

    int max_array_xor(vector<int> v, int x)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            node *curr = root;

            for (int j = 31; j >= 0; j--)
            {
                int id = get_bit(v[i], j);

                if (curr->child[1 - id] != NULL && curr->child[1 - id]->cnt > 0)
                    curr = curr->child[1 - id];
                else if (curr->child[id] != NULL)
                    curr = curr->child[id];

                curr->cnt--;
            }
            int curr_max = (x ^ (curr->val));
            ans = max(ans, curr_max);
        }
        return ans;
    }

    ll max_value_xor(int n)
    {
        node *curr = root;

        ll ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int id = get_bit(n, i);

            if (curr->child[1 - id] != NULL && curr->child[1 - id]->cnt > 0)
            {
                curr = curr->child[1 - id];
                set_bit(ans, i);
            }
            else if (curr->child[id] != NULL && curr->child[id]->cnt > 0)
            {
                curr = curr->child[id];
            }
        }
        return ans;
    }
};

Euclidean Distance double point_distance(int ax, int ay, int bx, int by)
{
    double a = (ax - bx) * (ax - bx);
    double b = (ay - by) * (ay - by);
    double ans = sqrt(a + b);

    return ans;
}

Mos Algorithm int n, q, block;
struct node
{
    int l, r, idx;
} que[100005]; // query node

bool comp(node &a, node &b)
{ // <[L],R>
    if ((a.l / block) != (b.l / block))
        return (a.l / block) < (b.l / block);
    return a.r < b.r;
}
void add(int idx) {} // add element

void del(int idx) {} // remove element

void mo()
{
    block = sqrt(n) + 1;
    for (int i = 0; i < q; i++)
    {
        cin >> que[i].l >> que[i].r;
        que[i].idx = i;
    }

    sort(que, que + q, comp);

    int start = 0, end = -1;
    int ans[q] = {};
    for (int i = 0; i < q; i++)
    {

        // With updates <[L],[R],Updates_Till_This_Query>
        // current_time -> queries perform
        // if current_time > Updates_Till_This_Query then undo query & current_time--
        // else add query & current_time++

        while (start > que[i].l)
        {
            add(--start);
        }
        while (end < que[i].r)
        {
            add(++end);
        }
        while (start < que[i].l)
        {
            del(start++);
        }
        while (end > que[i].r)
        {
            del(end--);
        }
        ans[que[i].idx] = cnt;
    }
}

Hashing
#include <bits/stdc++.h>
#define endl "\n"
    using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 9;
const int MOD = 1e9 + 7;

/// declare primes and mod value for hash
const int p1 = 137;
const int mod1 = 1e9 + 7;
const int p2 = 277;
const int mod2 = 1e9 + 9;

/// bigmod for substr hash
int power(ll n, ll k, int mod)
{
    int ans = 1 % mod;
    n = n % mod;
    if (n < 0)
        n += mod;
    while (k)
    {
        if (k & 1)
            ans = (ll)ans * n % mod;
        n = (ll)n * n % mod;
        k >>= 1;
    }
    return ans;
}

/// pre calculate power values of primes
pair<int, int> pw[N], ipw[N];
void prec()
{
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int inv_p1 = power(p1, mod1 - 2, mod1);
    int inv_p2 = power(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        ipw[i].first = 1LL * ipw[i - 1].first * inv_p1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * inv_p2 % mod2;
    }
}

/// forward hash of the string
pair<int, int> string_hash(string s)
{
    int n = s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++)
    {
        hs.first += 1LL * s[i] * pw[i].first % mod1;
        hs.first %= mod1;
        hs.second += 1LL * s[i] * pw[i].second % mod2;
        hs.second %= mod2;
    }
    return hs;
}

/// builds the pref hash array
pair<int, int> pref[N];
void build_pref(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if (i)
            pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if (i)
            pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}

/// get hash from idx i to j
pair<int, int> get_hash(int i, int j)
{
    assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if (i)
        hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if (i)
        hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
}

Undirected Cycle Find bool cycle = false;

void cycle_undirected(int s, int parent)
{
    vis[s] = true;
    for (auto x : graph[s])
    {
        if (!vis[x])
        {
            cycle_undirected(x, s);
        }
        else
        {
            if (x != parent)
                cycle = true;
            // cycle detected...
        }
    }
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            cycle_undirected(i, -1);
    }
    return 0;
}

Directed Cycle Find bool cycle = false;
int color[N];

void cycle_directed(int s)
{
    color[s] = 1;
    for (auto x : graph[s])
    {
        if (color[x] == 0)
        {
            cycle_directed(x);
        }
        else
        {
            if (color[x] == 1)
            {
                // cycle detected..
                cycle = true;
            }
        }
    }
    color[s] = 2;
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
            cycle_directed(i);
    }
    return 0;
}