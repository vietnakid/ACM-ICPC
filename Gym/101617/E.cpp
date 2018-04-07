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
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

struct com {
	com(char c, ll index, char x): c(c), index(index), x(x) {}
	char c, x;
	ll index;
};

void input(vector<com> & p1, vector<com> & p2) {
	do {
    	char c, x = '.';
    	cin >> c;
    	if (c == 'E') break;
    	ll index;
    	cin >> index;
    	if (c == 'I') {
    		cin >> x;
    	}
    	p1.push_back(com(c, index, x));
    } while (true);
    do {
    	char c, x = '.';
    	cin >> c;
    	if (c == 'E') break;
    	ll index;
    	cin >> index;
    	if (c == 'I') {
    		cin >> x;
    	}
    	p2.push_back(com(c, index, x));
    } while (true);
}	

void normalize(vector<com> & p) {
	FOR(i, 1, p.size()) {
		// cout << i << endl;
    	for (int j = i; j > 0; j--) {
    		if (p[j].c == 'D' && p[j-1].c == 'D' && p[j].index >= p[j-1].index) {
    			swap(p[j], p[j-1]);
    			p[j-1].index++;
    		} else if (p[j].c == 'I' && p[j-1].c == 'I' && p[j].index <= p[j-1].index) {
    			swap(p[j], p[j-1]);
    			p[j].index++;
    		} else if (p[j-1].c == 'I' && p[j].c == 'D') {
				if (p[j-1].index > p[j].index) {
	  				swap(p[j-1], p[j]);
	  				p[j].index--;
				} else if (p[j-1].index == p[j].index) {
		  			p.erase(p.begin() + j - 1, p.begin() + j + 1);
		  			i -= 2;	  
		  			break;
				} else {
	  				swap(p[j-1], p[j]);
	  				p[j-1].index--;
				} 
			} else {
				break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	vector<com> p1, p2;
    input(p1, p2);
    normalize(p1);
    normalize(p2);
    bool ok = true;
    FOR(i, 0, p1.size()) {
    	if (p1[i].c != p2[i].c || p1[i].index != p2[i].index || p1[i].x != p2[i].x) ok = false;
    }
    cout << !ok << endl;
    return 0;
}