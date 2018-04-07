	#include <bits/stdc++.h>

	using namespace std;

	typedef long long ll;
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

	vi row(8);
	vvi resrow;

	bool place(int r, int c) {
	  for (int prev = 0; prev < c; prev++)    // check previously placed queens
	    if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
	      return false;        // share same row or same diagonal -> infeasible
	  return true; }

	void backtrack(int c) {
	  if (c == 8) {         // candidate sol, (a, b) has 1 queen
	    resrow.push_back(row); }
	  for (int r = 0; r < 8; r++)                       // try all possible row
	    if (place(r, c)) {          // if can place a queen at this col and row
	      row[c] = r; backtrack(c + 1);      // put this queen here and recurse
	}   }

	int main()
	{
		// freopen("input", "r", stdin);
		// freopen("output", "w", stdout);
	    backtrack(0);
	    string s;
	    int TC = 0;
	    while (getline(cin, s)) {
	    	vi arr(8);
	    	stringstream ss(s);
	    	REP(i, 0, 8) {
	    		ss >> arr[i];
	    		arr[i]--;
	    	}

	    	int n = resrow.size();
	    	int res = INF;
	    	REP(ii, 0, n) {
	    		int cnt = 0;
	    		REP(i, 0, 8) {
	    			cnt += arr[i] != resrow[ii][i];
	    		}
	    		res = min(res, cnt);
	    	}
	    	TC++;
	    	cout << "Case " << TC << ": " << res << endl;
	    }
	    return 0;
	}
