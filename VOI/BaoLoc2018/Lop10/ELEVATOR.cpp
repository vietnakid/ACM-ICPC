#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

vi people;
ll res = 0;
ll n, c, p, t, curPeople;

bool check() {
    int lastFloor = 0, curFloor = 0;
    while (t > 0) {
        if (curFloor == 0 && 2*lastFloor > t) break;
        if (people[lastFloor] == 0) {
            lastFloor++;
        }
        if (curPeople == c) {
            t -= curFloor;
            res += c;
            curFloor = 0;
            curPeople = 0;
        }
        if (curFloor < lastFloor && lastFloor+(lastFloor-curFloor) <= t) {
            t -= lastFloor-curFloor;
            curFloor = lastFloor;
        }
        
        if (people[curFloor] + curPeople > c) {
            people[curFloor] -= (c - curPeople);
            curPeople = c;
        } else {
            curPeople += people[curFloor];
            people[curFloor] = 0;
        }
        cerr << "res = " << res << " | cur = " << curPeople << " | time = " << t << " | floor = " << curFloor << endl;
        for (auto x : people) {
            cerr << x << " ";
        }
        cerr << endl;
    }
    cerr << curPeople << " " << t << endl;
    cout << res << endl;
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> c >> p >> t;
    people.resize(n+1);
    t = t/p;
    for (int i = 1; i <= n; i++) {
        cin >> people[i];
    }
    curPeople = 0;
    
    return 0;
}