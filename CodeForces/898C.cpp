#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define FOR(i, a, b) \
    for (ll i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (ll i = (a); i <= (b); i++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

bool isSubfix(string a, string b) {
	// cout << a << " " << b << endl;
	if (b.size() > a.size()) {
		string tmp = a;
		a = b;
		b = tmp;
	}
	int n = a.size(); int m = b.size();
	FORE(i, 1, m) {
		if (a[n-i] != b[m-i]) return false;
	}
	// cout << "true" << endl;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int n;
    cin >> n;
    map<string, vector<string> > contacts;
    FOR(i, 0, n) {
    	string s;
    	cin >> s;
    	int k;
    	cin >> k;
    	FOR(j, 0, k) {
    		string ss; cin >> ss;

    		bool isput = false;
    		FOR(ii, 0, contacts[s].size()) {
    			if (isSubfix(ss, contacts[s][ii])) {
    				if (contacts[s][ii].size() < ss.size()) 
    					contacts[s][ii] = ss;
    				isput = true;
    			}
    		}
    		if (!isput) {
    			contacts[s].push_back(ss);
    		}
    	}
    }

    cout << contacts.size() << endl;
    for (map<string, vector<string> >::iterator it = contacts.begin(); it != contacts.end(); it++) {
    	cout << (*it).first << " " << (*it).second.size() << " ";
    	FOR(i, 0, (*it).second.size()) {
    		cout << (*it).second[i] << " ";
    	}
    	cout << endl;
    }
    return 0;
}