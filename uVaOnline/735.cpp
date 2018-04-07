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

int main()
{
// 	freopen("input", "r", stdin);
// 	freopen("output", "w", stdout);
	set<int> dkm;
	dkm.insert(0); dkm.insert(50);
    REP(i, 0, 21) {
    	dkm.insert(i);
    	dkm.insert(i*2);
    	dkm.insert(i*3);
    }
    vi arr;
    for (set<int>::iterator it = dkm.begin(); it != dkm.end(); it++) {
    	arr.push_back(*it);
    }
    int ss = arr.size();
    while (true) {
    	int n;
    	cin >> n;
    	int resper = 0;
    	set<vi> rescom;
    	if (n <= 0) break;
    	REP(i1, 0, ss) 
    		REP(i2, 0, ss) 
    			REP(i3, 0, ss) {
    				if (arr[i1] + arr[i2] + arr[i3] == n) {
    					resper++;
    					vi com(3);
    					com[0] = i1; com[1] = i2; com[2] = i3;
    					sort(com.begin(), com.end());
    					rescom.insert(com);	
    				} 
    			}
    	int resc = rescom.size();
    	if (resc > 0) {
    		printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, resc);
    		printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, resper);
    	} else {
    		printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    	}
    	
    	REP(i, 0, 70)
    	cout << "*";
    	cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
