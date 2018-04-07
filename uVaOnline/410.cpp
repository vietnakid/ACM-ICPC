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

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC = 0;

    int c, s;
    while (scanf("%d %d", &c, &s) != EOF) {
    	vii arr(2*c);
    	double sum = 0;
    	REP(i, 0, s) {
    		cin >> arr[i].first;
    		arr[i].second = i+1;
    		sum += arr[i].first;
    	}
    	sum /= c;
    	REP(i, s, 2*c-1) {
    		arr[i] = {0, 0};
    	}
    	sort(arr.begin(), arr.end());
    	vector<vii > res(c);
    	double imbalance = 0;
    	REP(i, 0, c) {
    		res[i].push_back(arr[i]);
    		res[i].push_back(arr[2*c-1-i]);
    		imbalance += fabs((arr[i].first + arr[2*c-1-i].first) - sum);
    	}
    	TC++;
    	printf("Set #%d\n", TC);

    	REP(i, 0, c) {
    		printf(" %d:", i);
    		if (res[i][0].second != 0)
    			printf(" %d", res[i][0].first);
    		if (res[i][1].second != 0)
    			printf(" %d", res[i][1].first);
    		cout << endl;
    	}
    	printf("IMBALANCE = %.5f\n\n", imbalance);
    }
    return 0;
}