#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
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
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
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
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << " ";
            os << v[i];
            first = false;
        }
        return os;
    }
    
/*-------------------------------------------------*/

// read once, read again, think, code

ll n, ones;

ll calc(string &s, ll d) {
	ll ans = INT_MAX, curr = 0;

	for(int i = 0 ; i < d ; i++) {
		ll j = i, match = 0, cnt = 0;
		while(j < n) {
			if(s[j] == '1') match++;
			else cnt++;	
			j += d;
		}

		ll curr = ones - match + cnt;

		ans = min(ans, curr);
	}

	return ans;
}


void solve() {

    ll ans = INT_MAX; cin >> n;
    string s; cin >> s;
    ones = 0;
    rep(i,n) ones += (s[i] == '1');
    // watch(ones);

    for(int i = 1 ; i*i <= n ; i++) {
    	if(n%i) continue;
    	ll ans1 = calc(s,i); ans = min(ans,ans1);
    	ans1 = calc(s,n/i); ans = min(ans,ans1);
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

    w(tc)
    	solve();
	
	return 0;
}