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

#define REP(i, a, b) \
    for (int i = (a); i < (b); i++)
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

string s, res;
int inde;
vector<vector<char> > arr;

bool isall(char c, int x, int y, int n, int m) {
	REP(i, x, x+n) {
		REP(j, y, y+m) {
			if (arr[i][j] != c) return false;
		}
	}
	// cout << c << " is all in " << x << " " << y << " size = " << n << " " << m << endl;
	return true;
}

void sovleb(int x, int y, int n, int m) {
	// cout << x << " " << y << " size = " << n << " " << m << endl;
	if (isall('1', x, y, n, m)) {
		// cout << "put 111111111111111111" << endl;
		res.push_back('1');
		// res += '1';
	} else if (isall('0', x, y, n, m)) {
		// cout << "put 000000000000000000000" << endl;
		res.push_back('0');
		// res += '0';
	} else {
		// cout << "put DDDDDDDDDDDDDDDDDDD" << endl;
		res.push_back('D');
		// res += 'D';

		if (n == 1) {
			if (m % 2 != 0) {
				sovleb(x, y, n, m/2+1);
				sovleb(x, y + m/2+1, n, m/2);
			} else {
				sovleb(x, y, n, m/2);
				sovleb(x, y + m/2, n, m/2);
			}
		} else if (m == 1) {
			if (n % 2 != 0) {
				// printf("devide to -> %d %d size %d %d\n",x, y, n/2+1, m);
				// printf("devide to -> %d %d size %d %d\n",x+n/2+1, y, n/2, m);
				sovleb(x, y, n/2+1, m);
				sovleb(x+n/2+1, y, n/2, m);
			} else {
				// printf("devide to -> %d %d size %d %d\n",x, y, n/2, m);
				// printf("devide to -> %d %d size %d %d\n",x+n/2, y, n/2, m);
				sovleb(x, y, n/2, m);
				sovleb(x+n/2, y, n/2, m);
			}
		} else {
			int left = m/2, right = m/2, top = n/2, bottom= n/2;
			if (n % 2 != 0) top++;
			if (m % 2 != 0) left++;
			// printf("devide to -> %d %d size %d %d\n",x, y, top, left);
			// printf("devide to -> %d %d size %d %d\n",x, y + left, top, right);
			// printf("devide to -> %d %d size %d %d\n",x + top, y, bottom, left);
			// printf("devide to -> %d %d size %d %d\n",x + top, y + left, bottom, right);
			sovleb(x, y, top, left);
			sovleb(x, y + left, top, right);
			sovleb(x + top, y, bottom, left);
			sovleb(x + top, y + left, bottom, right);

		}
	}
}

void sovled(int x, int y, int n, int m) {
	// cout << x << " " << y << " size = " << n << " " << m << endl;
	inde++;
	if (s[inde] == 'D') {
		if (n == 1) {
			if (m % 2 != 0) {
				sovled(x, y, n, m/2+1);
				sovled(x, y + m/2+1, n, m/2);
			} else {
				sovled(x, y, n, m/2);
				sovled(x, y + m/2, n, m/2);
			}
		} else if (m == 1) {
			if (n % 2 != 0) {
				sovled(x, y, n/2 + 1, m);
				sovled(x + n/2 + 1, y, n/2, m);
			} else {
				sovled(x, y, n/2, m);
				sovled(x + n/2, y, n/2, m);
			}
		} else {
			int left = m/2, right = m/2, top = n/2, bottom= n/2;
			if (n % 2 != 0) top++;
			if (m % 2 != 0) left++;
			sovled(x, y, top, left);
			sovled(x, y + left, top, right);
			sovled(x + top, y, bottom, left);
			sovled(x + top, y + left, bottom, right);
		}
	} else if (s[inde] == '1') {
		REP(i, x, x+n)
			REP(j, y, y+m)
				arr[i][j] = '1';
	} else {
		REP(i, x, x+n)
			REP(j, y, y+m)
				arr[i][j] = '0';
	}
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    while (true) {
    	char type;
    	cin >> type;
    	if (type == '#') break;
    	int n, m;
    	cin >> n >> m;
    	
    	inde = -1;
    	res = "";
    	if (type == 'B') {
    		s = "";
    		while (s.size() < n*m) {
	    		string ss;
	    		cin >> ss;
	    		s += ss;	
	    	}
    		printf("D%4d%4d\n", n, m);
    		arr = vector<vector<char> >(n);
    		REP(i, 0, n) arr[i] = std::vector<char>(m);
			int index = 0;

			REP(i, 0, n) {
				REP(j, 0, m) {
					arr[i][j] = s[index];
					index++;
					// cout << arr[i][j];
				}
				// cout << endl;
			}
			// cout << endl;

			sovleb(0, 0, n, m);
    		int cnt = 0;
    		while (cnt < res.size()) {
    			for (int i = 0; i < 50 && cnt < res.size(); i++) {
    				cout << res[cnt];
    				cnt++;
    			}
    			cout << endl;
    		}
    	} 
    	else {
    		cin >> s;
    		printf("B%4d%4d\n", n, m);
    		arr = vector<vector<char> >(n);
    		REP(i, 0, n) arr[i] = std::vector<char>(m);
    		sovled(0, 0, n, m);

    		res = "";
			REP(i, 0, n) {
				REP(j, 0, m) {
					res.push_back(arr[i][j]);
					// cout << arr[i][j];
				}
				// cout << endl;
			}
			// cout << endl;

    		int cnt = 0;
    		while (cnt < res.size()) {
    			for (int i = 0; i < 50 && cnt < res.size(); i++) {
    				cout << res[cnt];
    				cnt++;
    			}
    			cout << endl;
    		}
    	}
    }
    return 0;
}