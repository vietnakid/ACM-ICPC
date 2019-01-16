#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int t, u, v;
    ll cost;
    Edge(int t, int u, int v, int cost) : t(t), u(u), v(v), cost(cost) {}
    int operator < (const Edge& other) const {
        return cost < other.cost;
    }
};

ostream& operator << (ostream& os, const Edge& e) {
    os << "(" << e.t << " " << e.u << " " << e.v << " " << e.cost << ")";
    return os;
}

const int rowType = 2, colType = 1;

ll numRowDrawed = 0, numColDrawed = 0;
ll n, m, p, q, nMod;
vector<Edge> arr;
vector<ll> dsuRow, dsuCol, numDSURow, numDSUCol;
ll MST = 0, SUM = 0;

bool isSameRoot(int type, int u, int v) {
    if (type == rowType) {
        while (u != dsuRow[u]) {
            u = dsuRow[u];
        }
        while (v != dsuRow[v]) {
            v = dsuRow[v];
        }
        
        return u == v;
    } else {
        while (u != dsuCol[u]) {
            u = dsuCol[u];
        }
        while (v != dsuCol[v]) {
            v = dsuCol[v];
        }
        return u == v;
    }
}

void connectDSU(int type, int u, int v) {
    if (type == rowType) {
        while (u != dsuRow[u]) {
            u = dsuRow[u];
        }
        while (v != dsuRow[v]) {
            v = dsuRow[v];
        }
        if (numDSURow[u] < numDSURow[v]) {
            dsuRow[v] = u;
            numDSURow[u] += numDSURow[v];
        } else {
            dsuRow[u] = v;
            numDSURow[v] += numDSURow[u];
        }
    } else {
        while (u != dsuCol[u]) {
            u = dsuCol[u];
        }
        while (v != dsuCol[v]) {
            v = dsuCol[v];
        }
        if (numDSUCol[u] < numDSUCol[v]) {
            dsuCol[v] = u;
            numDSUCol[u] += numDSUCol[v];
        } else {
            dsuCol[u] = v;
            numDSUCol[v] += numDSUCol[u];
        }
    }
}

ll mulMod(ll a, ll b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    ll x = mulMod(a, b/2);
    x = (x + x) % nMod;
    if (b % 2 == 0) {
        return x;
    } else {
        return (x + a) % nMod;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    freopen("CONNECT.INP", "r", stdin);
	freopen("CONNECT.OUT", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &m, &n, &p, &q, &nMod);

    dsuRow.resize(m+1);
    numDSURow.resize(m+1, 1);
    dsuCol.resize(n+1);
    numDSUCol.resize(n+1, 1);
    for (int i = 0; i <= m; i++) {
        dsuRow[i] = i;
    }
    for (int i = 0; i <= n; i++) {
        dsuCol[i] = i;
    }

    for (int i = 0; i < p; i++) {
        ll u, v, cost;
        scanf("%lld %lld %lld", &u, &v, &cost);
        arr.push_back(Edge(1, u, v, cost));
    }
    for (int i = 0; i < q; i++) {
        ll u, v, cost;
        scanf("%lld %lld %lld", &u, &v, &cost);
        arr.push_back(Edge(2, u, v, cost));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < (int)arr.size(); i++) {
        Edge curEdge = arr[i];
        ll curType = curEdge.t;
        if (curType == rowType) {
            SUM = (SUM + mulMod(curEdge.cost, n)) % nMod;
            if (!isSameRoot(rowType, curEdge.u, curEdge.v)) {
                MST = (MST + mulMod(curEdge.cost, n - numColDrawed)) % nMod;
                numRowDrawed++;
                connectDSU(rowType, curEdge.u, curEdge.v);
            }
        } else {
            SUM = (SUM + mulMod(curEdge.cost, m)) % nMod;
            if (!isSameRoot(colType, curEdge.u, curEdge.v)) {
                MST = (MST + mulMod(curEdge.cost, m - numRowDrawed)) % nMod;
                numColDrawed++;
                connectDSU(colType, curEdge.u, curEdge.v);
            }
        }
        // cout << curEdge << " " << MST << endl;
    }
    // cout << SUM << " " << MST << endl;
    ll res = (SUM + mulMod(MST, nMod - 1)) % nMod;
    cout << res << endl;
    return 0;
}