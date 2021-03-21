#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x) ll x; cin>>x; while(x--)

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
    
/*-------------------------------------------------*/

// read once, read again, think, code

ll findLongestPathFrom(vi *adj, vi &longestPath, ll st) {
	if(longestPath[st] != -1) return longestPath[st];
	if(adj[st].size() == 0) {
		longestPath[st] = 0;
	} else {
		ll best = 0;
		for(auto to : adj[st]) {
			best = max(best, findLongestPathFrom(adj,longestPath,to));
		}
		longestPath[st] = 1 + best;
	}

	return longestPath[st];
}

void solve() {

    ll n, m, u, v, ans = 0; cin >> n >> m;
    vi adj[n+1];
    rep(i,m) {
    	cin >> u >> v;
    	adj[u].pb(v);
    }

    vi longestPath(n+1,-1);
    repeb(i,1,n) {
    	if(longestPath[i] == -1) {
    		ans = max(ans, findLongestPathFrom(adj,longestPath,i));
    	}
    }

    p1(ans);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}