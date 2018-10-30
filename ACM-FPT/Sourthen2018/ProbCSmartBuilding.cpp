#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-9
typedef long long ll;

double max(double x, double y) {
	return (x > y) ? x : y;
}

double min(double x, double y) {
	return (x < y) ? x : y;
}

int gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

typedef  struct Point
{
	double x;
	double y;

	Point() : x(0), y(0) {}

	Point(double x1, double y1) : x(x1), y(y1) {}

	Point operator + (const Point& p) const {return Point(x + p.x, y + p.y);}
    Point operator - (const Point& p) const {return Point(x - p.x, y - p.y);}
    Point operator * (double c) const {return Point(x * c, y * c);}
    Point operator / (double c) const {return Point(x / c, y / c);}
} Vector;

double dist(Point A, Point B) {
	return hypot(A.x - B.x, A.y - B.y);
}

//equation ax + by + c = 0
struct Line
{
	double a, b, c;

	Line() : a(0), b(0), c(0) {}

	Line(double a1, double b1, double c1) : a(a1), b(b1), c(c1) {}

	Line(Point A, Point B) : a(A.x - B.x), b(A.y - B.y), c(- a * A.x - b * A.y) {}
};

struct Circle
{
	double r;
	Point I;

	Circle() : r(0), I(Point(0, 0)) {}

	Circle(double radius, Point center) : r(radius), I(center) {}

	Circle(double radius, double x, double y) : r(radius), I(Point(x, y)) {}
};

double dot(Point p, Point q) {
	return p.x * q.x + p.y * q.y;
}


vector<Point> CircleLineIntersection(Point a, Point b, Point c, double r) {
    vector<Point> res;
    b = b - a; a = a - c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r * r;
    double D = B * B - A * C;
    if (D < 0) return res;
    res.push_back(c + a + b * (-B + sqrt(D)) / A);
    if (D > 0) res.push_back(c + a + b * (-B - sqrt(D)) / A);
    return res;
}

//P là điểm nguyên
Point intPointRight(Point P1, Point A, ll step) {
	ll n = fabs(P1.x - A.x) / step;
	if (P1.x < A.x) {
		return Point(A.x + (n + 1) * step, A.y + (n + 1) * step);
	} else if (P1.x > A.x) {
		return Point(A.x - n * step, A.y - n * step);
	} else {
		return P1;
	}
}

Point intPointUp(Point P1, Point A, ll step) {
	ll n = fabs(P1.y - A.y) / step;
	if (P1.y < A.y) {
		return Point(A.x, A.y + (n + 1) * step);
	} else if (P1.y > A.y) {
		return Point(A.x, A.y - n * step);
	} else {
		return P1;
	}
}

Point intPointLeft(Point P1, Point A, ll step) {
	ll n = fabs(P1.x - A.x) / step;
	if (P1.x < A.x) {
		return Point(A.x + n * step, A.y + n * step);
	} else if (P1.x > A.x) {
		return Point(A.x - (n + 1) * step, A.y - (n + 1) * step);
	} else {
		return P1;
	}
}

Point intPointDown(Point P1, Point A, ll step) {
	ll n = fabs(P1.y - A.y) / step;
	if (P1.y < A.y) {
		return Point(A.x, A.y + n * step);
	} else if (P1.y > A.y) {
		return Point(A.x, A.y - (n + 1) * step);
	} else {
		return P1;
	}
}
int main(int argc, char const *argv[])
{
	// freopen("D:\\Sublime\\POJ CPP\\VSPC2018\\input.txt", "r", stdin);
	// freopen("D:\\Sublime\\POJ CPP\\VSPC2018\\output.txt", "w", stdout);
	double x0, y0, r;
	double x1, y1, x2, y2;
	double distance;
	ll min, max;
	Point c;
	Point a, b;
	std::vector<Point> res;
	ll step;
	Line d;
	ll n;
	while (scanf("%lf%lf%lf", &x0, &y0, &r) == 3) {
		res.clear();
		c = Point(x0, y0);
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		a = Point(x1, y1);
		b = Point(x2, y2); 
		res = CircleLineIntersection(a, b, c, r);//0 phải, 1 trái
		if (res.size() == 1) {
			// distance = dist(Point((int)res[0].x, (int)res[0].y), Point(x0, y0));
			// if (distance == r) 
			if ((int)res[0].x == res[0].x && (int)res[0].y == res[0].y)
			{
				/* code */
				printf("1\n");
			} else {
				printf("0\n");
			}
		} else if (res.size() == 0) {
			printf("0\n");
		}  else {
			if (res[0].x == res[1].x) {
				// printf("%lf %lf %lf %lf \n", res[0].x, res[0].y, res[1].x, res[1].y);
				max = floor(res[0].y);
				min = ceil(res[1].y);
				// printf("%d %d\n", min, max);
				n = fabs(max - min) + 1;
				if (n < 0) {
					printf("0\n");
				} else {
					printf("%d\n", n);
				}
				continue;
			}
			if (res[0].y == res[1].y) {
				// printf("%lf %lf %lf %lf \n", res[0].x, res[0].y, res[1].x, res[1].y);
				max = floor(res[0].x);
				min = ceil(res[1].x);
				// printf("%d %d\n", min, max);
				n = fabs(max - min) + 1;
				if (n < 0) {
					printf("0\n");
				} else {
					printf("%d\n", n);
				}
				continue;
			}
			// printf("%lf %lf %lf %lf \n", res[0].x, res[0].y, res[1].x, res[1].y);
			step = gcd(fabs(x1 - x2), fabs(y1- y2));
			// printf("step %d\n", step);
			Point p1 = intPointLeft(a, res[0], step);
			Point p2 = intPointRight(a, res[1], step);
			n = (p1.x - p2.x) / step + 1;
			// printf("%lf %lf %lf %lf \n", p1.x, p1.y, p2.x, p2.y);
			if (n < 0) {
				printf("0\n");
			} else {
				printf("%d\n", n);
			}
		}
	}
	
	return 0;
}
