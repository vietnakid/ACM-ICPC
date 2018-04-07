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

	#define RL double
	#define EPS 1e-6
	struct PT {
	    RL x, y;
	    PT() : x(0), y(0) {}
	    PT(RL x, RL y) : x(x), y(y) {}
	    PT(const PT& p) : x(p.x), y(p.y) {}
	    int operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	    int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	    PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
	    PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
	    PT operator * (RL c) const {return PT(x * c, y * c);}
	    PT operator / (RL c) const {return PT(x / c, y / c);}
	};
	RL cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
	RL area(PT a, PT b, PT c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
	RL area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
	RL dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
	RL dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
	RL dist2(PT p, PT q) {return dot(p - q, p - q);}
	PT RotateCCW90(PT p) {return PT(-p.y, p.x);}
	PT RotateCW90(PT p) {return PT(p.y, -p.x);}
	PT RotateCCW(PT p, RL t) {return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
	int sign(RL x) {return x < -EPS ? -1 : x > EPS;}
	int sign(RL x, RL y) {return sign(x - y);}
	ostream& operator << (ostream& os, const PT& p) {
	    os << "(" << p.x << "," << p.y << ")";
	    return os;
	}

	//Project c on Line(a, b)
	PT ProjectPointLine(PT a, PT b, PT c) {
	    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
	}
	PT ProjectPointSegment(PT a, PT b, PT c) {
	    RL r = dot(b - a, b - a);
	    if (fabs(r) < EPS) return a;
	    r = dot(c - a, b - a) / r;
	    if (r < 0) return a;
	    if (r > 1) return b;
	    return a + (b - a) * r;
	}
	RL DistancePointSegment(PT a, PT b, PT c) {
	    return dist(c, ProjectPointSegment(a, b, c));
	}
	//Compute distance between PT (x, y, z) and plane ax + by + cz = d
	RL DistancePointPlane(RL x, RL y, RL z, RL a, RL b, RL c, RL d) {
	    return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
	}
	//Determine if lines from a to b and c to d are parallel or collinear
	int LinesParallel(PT a, PT b, PT c, PT d) {
	    return fabs(cross(b - a, c - d)) < EPS;
	}
	int LinesCollinear(PT a, PT b, PT c, PT d) {
	    return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
	}
	//Determine if line segment from a to b intersects with line segment from c to d
	int SegmentsIntersect(PT a, PT b, PT c, PT d) {
	    if (LinesCollinear(a, b, c, d)) {
	        if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return 1;
	        if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0) return 0;
	        return 1;
	    }
	    if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
	    if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
	    return 1;
	}
	//Compute intersection of line passing through a and b
	//with line passing through c and d, assuming that unique
	//intersection exists; for segment intersection, check if
	//segments intersect first
	PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
	    b = b - a; d = c - d; c = c - a;
	    return a + b * cross(c, d) / cross(b, d);
	}
	//Compute center of circle given three points
	PT ComputeCircleCenter(PT a, PT b, PT c) {
	    b = (a + b) / 2;
	    c = (a + c) / 2;
	    return ComputeLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(a - c));
	}
	//Determine if point is in a possibly non-convex polygon
	//returns 1 for strictly interior points, 0 for
	//strictly exterior points, and 0 or 1 for the remaining points.
	int PointInPolygonSlow(const vector<PT>& p, PT q) {
	    int c = 0;
	    for (int i = 0; i < p.size(); i++) {
	        int j = (i + 1) % p.size();
	        if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
	    }
	    return c;
	}
	//Strictly inside convex Polygon
	#define Det(a, b, c) ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x))
	int PointInPolygon(vector<PT>& p, PT q) {
	    int a = 1, b = p.size() - 1, c;
	    if (Det(p[0], p[a], p[b]) > 0) swap(a, b);
	    //Allow on edge --> if (Det... > 0 || Det ... < 0)
	    if (Det(p[0], p[a], q) >= 0 || Det(p[0], p[b], q) <= 0) return 0;
	    while(abs(a - b) > 1) {
	        c = (a + b) / 2;
	        if (Det(p[0], p[c], q) > 0) b = c; else a = c;
	    }
	    //Alow on edge --> return Det... <= 0
	    return Det(p[a], p[b], q) < 0;
	}
	//Determine if point is on the boundary of a polygon
	int PointOnPolygon(const vector<PT>& p, PT q) {
	    for (int i = 0; i < p.size(); i++) if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS) return 1;
	    return 0;
	}
	//Compute intersection of line through points a and b with circle centered at c with radius r > 0
	vector<PT> CircleLineIntersection(PT a, PT b, PT c, RL r) {
	    vector<PT> res;
	    b = b - a; a = a - c;
	    RL A = dot(b, b);
	    RL B = dot(a, b);
	    RL C = dot(a, a) - r * r;
	    RL D = B * B - A * C;
	    if (D < -EPS) return res;
	    res.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
	    if (D > EPS) res.push_back(c + a + b * (-B - sqrt(D)) / A);
	    return res;
	}
	//Compute intersection of circle centered at a with radius r with circle centered at b with radius R
	vector<PT> CircleCircleIntersection(PT a, PT b, RL r, RL R) {
	    vector<PT> res;
	    RL d = sqrt(dist2(a, b));
	    if (d > r + R || d + min(r, R) < max(r, R)) return res;
	    RL x = (d * d - R * R + r * r) / (2 * d);
	    RL y = sqrt(r * r - x * x);
	    PT v = (b - a) / d;
	    res.push_back(a + v * x + RotateCCW90(v) * y);
	    if (y > 0) res.push_back(a + v * x - RotateCCW90(v) * y);
	    return res;
	}

	#define FOR(i, a, b) \
	    for (int i = (a); i < (b); i++)
	#define FORE(i, a, b) \
	    for (int i = (a); i <= (b); i++)

	#define INF 2000000000 // 2e9
	#define INFLL 2000000000000000000 // 2e18
	#define PI 3.14159265

	inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
	inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

	priority_queue< ll, vector<ll>, greater<ll> > heap;

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie();
		// freopen("input", "r", stdin);
		// freopen("output", "w", stdout);
	    int n;
	    cin >> n;
	    vector<pair<PT, double> > circles;
	    FOR(i, 0, n) {
	    	double x, y, r;
	    	cin >> x >> y >> r;
	    	PT p(x,y);
	    	circles.push_back(make_pair(p, r));
	    }
	    double res = -1.0;
	    PT ZERO(0,0);
	    FOR(i, 0, n) {
	    	FOR(j, i+1, n) {
	    		// giao diem 2 duong tron
	    		vector<PT> points = CircleCircleIntersection(circles[i].first, circles[j].first, circles[i].second, circles[j].second);
	    		
	    		// truong hop chua' nhau
	    		
	    		points.push_back(PT(circles[i].first.x, circles[i].first.y + circles[i].second));
	    		points.push_back(PT(circles[j].first.x, circles[j].first.y + circles[j].second));

	    		vector<PT> points2 = CircleLineIntersection(circles[i].first, circles[j].first, circles[i].first, circles[i].second);
				FOR(ii, 0, points2.size()) {
					points.push_back(points2[ii]);
				}

				points2 = CircleLineIntersection(circles[i].first, circles[j].first, circles[j].first, circles[j].second);
				FOR(ii, 0, points2.size()) {
					points.push_back(points2[ii]);
				}

				// @@  0,0 -> x,y
				points2 = CircleLineIntersection(ZERO, circles[j].first, circles[j].first, circles[j].second);
				FOR(ii, 0, points2.size()) {
					points.push_back(points2[ii]);
				}

	    		FOR(ii, 0, points.size()) {    			
	    			bool ok = true;
	    			// cout << i << " " << j << " " << points[ii].x << " " << points[ii].y << endl;
	    			FOR(jj, 0, n) {
	    				
	    				if (dist(points[ii], circles[jj].first) - circles[jj].second >= EPS)
	    					ok = false; 
	    			}
	    			if (ok) {
	    				res = max(res, dist(points[ii], ZERO));
	    			}
	    		}
	    	
	    	}
	    }
	    printf("%.3lf\n", res);
	    return 0;
	}