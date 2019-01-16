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

int n, m, start, low, high;
int arr[500005], brr[500005];
unordered_set<int> sumSet;

void sovle() {
    srand(time(NULL));
    int checkTime = 50;
    for (int value = low; value <= high; value++) {
        // cerr << value << " " << checkTime << endl;
        bool check = true;
        for (int t = 0; t < checkTime; t++) {
            int r = rand() % n;
            if (sumSet.count(value + arr[r]) == 0) {
                check = false;
            }
        }
        if (check) {
            printf("%d ", value);
        }
    }
}

void sovleSmall() {
    for (int i = 0; i <= m-n; i++) {
        bool check = true;
        int x = brr[i] - start;
        for (int j = 0; j < n; j++) {
            if (sumSet.count(x + arr[j]) == 0) {
                // cerr << x << " " << arr[j] << " " << x + arr[j] << endl;
                check = false;
                break;
            } 
        }
        if (check) {
            cout << x << " ";
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    start = arr[0]; 
    sort(arr, arr+n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &brr[i]);
        sumSet.insert(brr[i]);
    }
    
    sort(brr, brr+m);
    if (m <= 10000)
        sovleSmall();
    else {
        low = brr[0] - arr[0];
        high = brr[m-1] - arr[n-1];
        sovle();
    }
        
    return 0;
}