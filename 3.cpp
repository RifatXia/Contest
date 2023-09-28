#include <bits/stdc++.h>
#define MAX int(2e5 + 10)
#define en "\n"
#define ll long long 
#define bitscount 32
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

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

ll prefix_track[bitscount][MAX];
void prefix_work(ll arr[], int n)
{
	for (int i = 0; i < bitscount; i++) {

		prefix_track[i][0] = ((arr[0] >> i) & 1);
		for (int j = 1; j < n; j++) {
			prefix_track[i][j] = ((arr[j] >> i) & 1);
			prefix_track[i][j] += prefix_track[i][j - 1];
		}
	}
}

int find_and(int l, int r)
{
	int ans = 0;
	for (int i = 0; i < bitscount; i++) {
		int x;
		if (l == 0)
			x = prefix_track[i][r];
		else
			x = prefix_track[i][r] - prefix_track[i][l - 1];

		if (x == r - l + 1)
			ans = (ans | (1 << i));
	}

	return ans;
}

int main(void)
{
    RifatXia();
    fast_io;

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
	    ll arr[n];
        
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
	    prefix_work(arr, n);
    
        int q;
        cin >> q;
        while(q--)
        {
            ll a, b;
            cin >> a >> b;
            ll ans = -1;
            ll l = a - 1, r = n - 1;
            while(l <= r)
            {
                ll mid = (l + r)/2;
                ll get = find_and(a - 1, mid);
                if(get >= b)
                {
                    ans = max(ans, mid + 1);
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            // for(int i = n; i >= a; i--)
            // {
            //     ll get = find_and(a - 1, i - 1);
            //     if(get >= b)
            //     {
            //         ans = max(ans, (ll)i);
            //         break;
            //     }
            // }
            cout << ans << " ";
        }
        cout << en;
    }

	return 0;
}
