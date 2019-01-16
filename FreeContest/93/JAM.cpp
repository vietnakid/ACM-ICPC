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

int m, n;
string arr[2005];
vector<set<int> > col(2005), row(2005), East(2005), West(2005), South(2005), North(2005);

queue<ii> q;
vvi isFree(2005, vi(2005, true));


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> arr[i];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != '.') {
                row[i].insert(j);
                col[j].insert(i);
                switch (arr[i][j]) {
                    case 'E': East[i].insert(j); break;
                    case 'W': West[i].insert(j); break;
                    case 'N': North[j].insert(i); break;
                    case 'S': South[j].insert(i); break;
                }
            }
        }
    }
    
    
    for (int i = 0; i < m; i++) {
        if (East[i].size() > 0 && *(East[i].rbegin()) == *row[i].rbegin()) {
            if (isFree[i][*row[i].rbegin()]) {
                q.push({i, *row[i].rbegin()});
                isFree[i][*row[i].rbegin()] = false;
            }
        }
        
        if (West[i].size() > 0 && *(West[i].begin()) == *row[i].begin()) {
            if (isFree[i][*row[i].begin()]) {
                isFree[i][*row[i].begin()] = false;
                q.push({i, *row[i].begin()});
            }   
        }
    }

    for (int j = 0; j < n; j++) {
        if (North[j].size() > 0 && *(North[j].rbegin()) == *col[j].rbegin()) {
            if (isFree[*col[j].rbegin()][j]) {
                q.push({*col[j].rbegin(), j});
                isFree[*col[j].rbegin()][j] = false;
            }            
        }
        
        if (South[j].size() > 0 && *(South[j].begin()) == *col[j].begin()) {
            if (isFree[*col[j].begin()][j]) {
                q.push({*col[j].begin(), j});
                isFree[*col[j].begin()][j] = false;
            }       
        }
    }
    int res = 0;
    while (!q.empty()) {
        ii node = q.front(); q.pop();
        res++;
        int i = node.first, j = node.second;
        // cerr << i << " " << j << endl;
        switch (arr[i][j]) {
            case 'E': 
                East[i].erase(j);
                break;
            case 'W': 
                West[i].erase(j);
                break;
            case 'N': 
                North[j].erase(i);
                break;
            case 'S': 
                South[j].erase(i);
                break;
        }

        row[i].erase(j);
        col[j].erase(i);

        if (East[i].size() > 0 && *(East[i].rbegin()) == *row[i].rbegin()) {
            if (isFree[i][*row[i].rbegin()]) {
                q.push({i, *row[i].rbegin()});
                isFree[i][*row[i].rbegin()] = false;
            }
        }
        
        if (West[i].size() > 0 && *(West[i].begin()) == *row[i].begin()) {
            if (isFree[i][*row[i].begin()]) {
                q.push({i, *row[i].begin()});
                isFree[i][*row[i].begin()] = false;
            }   
        }

        // cerr << *(North[j].rbegin()) << " " << *col[j].rbegin() << endl;
        if (North[j].size() > 0 && *(North[j].rbegin()) == *col[j].rbegin()) {
            if (isFree[*col[j].rbegin()][j]) {
                q.push({*col[j].rbegin(), j});
                isFree[*col[j].rbegin()][j] = false;
            }            
        }
        
        if (South[j].size() > 0 && *(South[j].begin()) == *col[j].begin()) {
            if (isFree[*col[j].begin()][j]) {
                q.push({*col[j].begin(), j});
                isFree[*col[j].begin()][j] = false;
            }       
        }
    }
    cout << res << endl;
    return 0;
}