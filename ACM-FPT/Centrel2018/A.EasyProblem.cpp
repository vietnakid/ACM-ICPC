#include <bits/stdc++.h>
using namespace std;

struct PT {
    int x, y;
    PT() : x(0), y(0) {}
    PT(int x, int y) : x(x), y(y) {}
    PT(const PT& rhs) : x(rhs.x), y(rhs.y) {}
    int operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
    int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    PT operator - (const PT& rhs) const {return PT(x - rhs.x, y - rhs.y);}
};

long long cross(PT a, PT b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}

long long area(PT a, PT b, PT c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}

void ConvexHull(vector<PT>& pts, vector<PT>& up, vector<PT>& dn) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

const int maxn = 1e6 + 5;
int n;
PT p[maxn];
vector<pair<int, int> > v;

long long dist(PT a, PT b) {return abs(a.x - b.x) +  abs(a.y - b.y);}
long long area(int i, int j, int k) {return abs(area(p[i], p[j], p[k]));}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    scanf("%d", &n);
    vector<PT> vp, up, dn;
    for (int i = 0; i < n; i++) {
        int x; 
        scanf("%d", &x);
        vp.push_back(PT(i+1, x));
    } 

    ConvexHull(vp, up, dn);

    int u = 0, v = dn.size() - 1, w = up.size() - 1;

    long long mx = dist(up[u], dn[v]);

    while (u < w || v > 0) {
        if (u == w) v--;
        else if (!v) u++;
        else {
            if (cross(up[u + 1] - up[u], dn[v] - dn[v - 1]) < 0) {
                u++;
            }
            else {
                v--;
            }
        }
        mx = max(mx, dist(up[u], dn[v]));
    }

    cout << mx << endl;
    return 0;
}
