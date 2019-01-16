#include<bits/stdc++.h> 
using namespace std; 
  
class Vector { 
private: 
    long long x, y, z; 
    // 3D Coordinates of the Vector 
  
public: 
    Vector(long long x, long long y, long long z) 
    { 
        // Constructor 
        this->x = x; 
        this->y = y; 
        this->z = z; 
    } 
    Vector operator+(Vector v); // ADD 2 Vectors 
    Vector operator-(Vector v); // Subtraction 
    long long operator^(Vector v); // Dot Product 
    Vector operator*(Vector v); // Cross Product 
    double magnitude() 
    { 
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); 
    } 
    friend ostream& operator<<(ostream& out, const Vector& v); 
    // To output the Vector 
}; 
  
// ADD 2 Vectors 
Vector Vector::operator+(Vector v) 
{ 
    long long x1, y1, z1; 
    x1 = x + v.x; 
    y1 = y + v.y; 
    z1 = z + v.z; 
    return Vector(x1, y1, z1); 
} 
  
// Subtract 2 vectors 
Vector Vector::operator-(Vector v) 
{ 
    long long x1, y1, z1; 
    x1 = x - v.x; 
    y1 = y - v.y; 
    z1 = z - v.z; 
    return Vector(x1, y1, z1); 
} 
  
// Dot product of 2 vectors 
long long Vector::operator^(Vector v) 
{ 
    long long x1, y1, z1; 
    x1 = x * v.x; 
    y1 = y * v.y; 
    z1 = z * v.z; 
    return (x1 + y1 + z1); 
} 
  
// Cross product of 2 vectors 
Vector Vector::operator*(Vector v) 
{ 
    long long x1, y1, z1; 
    x1 = y * v.z - z * v.y; 
    y1 = z * v.x - x * v.z; 
    z1 = x * v.y - y * v.x; 
    return Vector(x1, y1, z1); 
} 
  
// Display Vector 
ostream& operator<<(ostream& out, 
                    const Vector& v) 
{ 
    out << v.x << "i "; 
    if (v.y >= 0) 
        out << "+ "; 
    out << v.y << "j "; 
    if (v.z >= 0) 
        out << "+ "; 
    out << v.z << "k" << endl; 
    return out; 
} 
  
// calculate shortest dist. from point to line 
double shortDistance(Vector line_point1, Vector line_point2, 
                    Vector point) 
{ 
    Vector AB = line_point2 - line_point1; 
    Vector AC = point - line_point1; 
    double area = Vector(AB * AC).magnitude(); 
    double CD = area / AB.magnitude(); 
    return CD; 
} 
  
// Driver program 
int main() 
{ 
    ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("BIGBALL.inp", "r", stdin);
    freopen("BIGBALL.out", "w", stdout);
    long long n, xa, ya, za, xb, yb, zb;
    scanf("%lld", &n);
    scanf("%lld %lld %lld", &xa, &ya, &za);
    scanf("%lld %lld %lld", &xb, &yb, &zb);
    Vector line_point1(xa, ya, za), line_point2(xb, yb, zb); 
    for (int i = 0; i < n; i++) {
        long long x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        Vector point(x, y, z); 
        double dist = shortDistance(line_point1, line_point2, point);
        printf("%.0lf\n", ceil(dist));
    }
    return 0; 
} 