#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//typedef vector<int> vi;
//typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//typedef vector< vii> vvii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
//#define FORE(i, a, b) \
//    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

//#define INF 1e9+7
//#define INFLL 1e18+7
//#define esp 1e-9
//#define PI 3.14159265
//
//ll nMod = 1e9 + 7;

//inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
//inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int a, b, c;
ll temp;

ll max(ll a1, ll b1) {
    return a1 > b1 ? a1 : b1;
}

ll maxSum1D(vl arr1D) {
    ll dp = arr1D[0];
    ll max1D = dp;
    FOR(i, 1, arr1D.size()) {
        dp = max(arr1D[i], dp + arr1D[i]);
        max1D = max(max1D, dp);
    }
    return max1D;
}

vl addArr1D(vl arr1, vl arr2) {
    int size = arr1.size();
    FOR(i, 0, size) {
        arr1[i] += arr2[i];
    }
    return arr1;
}

ll maxSum2D(vvl arr2D) {
    ll dp = maxSum1D(arr2D[0]);
    ll max2D = dp;
    FOR(i, 1, arr2D.size()) {
        vl tempArr = arr2D[i];
        dp = maxSum1D(tempArr);
        FORD(j, i - 1, 0) {
            tempArr = addArr1D(tempArr, arr2D[j]);
            dp = max(dp, maxSum1D(tempArr));
        }
        max2D = max(max2D, dp);
    }
    return max2D;
}

vvl addArr2D(vvl arr1, vvl arr2) {
    int size = arr1.size();
    FOR(i, 0, size) {
        arr1[i] = addArr1D(arr1[i], arr2[i]);
    }
    return arr1;
}

ll maxSum3D(vvvl arr3D) {
    ll dp = maxSum2D(arr3D[0]);
    ll max3D = dp;
    FOR(i, 1, arr3D.size()) {
        vvl tempArr = arr3D[i];
        dp = maxSum2D(tempArr);
        FORD(j, i - 1, 0) {
            tempArr = addArr2D(tempArr, arr3D[j]);
            dp = max(dp, maxSum2D(tempArr));
        }
        max3D = max(max3D, dp);
    }
    return max3D;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FOR(tc, 0, TC) {
        cin >> a >> b >> c;
        vvvl heap;
        FOR(i, 0, a) {
            vvl arr2D;
            FOR(j, 0, b) {
                vl arr1D;
                FOR(k, 0, c) {
                    cin >> temp;
                    arr1D.emplace_back(temp);
                }
                arr2D.emplace_back(arr1D);
            }
            heap.emplace_back(arr2D);
        }
        cout << maxSum3D(heap) <<'\n';
        if (tc + 1 != TC) {
            cout << "\n";
        }
    }

    return 0;
}