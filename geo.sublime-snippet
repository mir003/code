<snippet>
	<content><![CDATA[
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e9
#define MIN -1e9
#define MOD 1000000007
#define mod2 20071027
//#define mod 1000074259
#define base 139
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case %lld:\n", ++c)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const ll N=1000010;
const double pi = 4 * atan(1);
const double eps = 1e-6;
inline int dcmp (double x)
{
    if (fabs(x) < eps) return 0;else return x < 0 ? -1 : 1;
}

struct point
{
    double x, y;
    point (double x = 0, double y = 0): x(x), y(y) {}
    void read (){scanf("%lf%lf", &x, &y);}
    void write (){printf("%lf %lf", x, y);}
    void put (double a, double b){x=a, y=b;}
    bool operator == (const point& u) const{return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0;}
    bool operator != (const point& u) const{return !(*this == u);}
    bool operator < (const point& u) const{return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0);}
    bool operator > (const point& u) const{return u < *this;}
    bool operator <= (const point& u) const{return *this < u || *this == u;}
    bool operator >= (const point& u) const{return *this > u || *this == u;}
    point operator + (const point& u){return point(x + u.x, y + u.y);}
    point operator - (const point& u){return point(x - u.x, y - u.y);}
    point operator * (const double u){return point(x * u, y * u);}
    point operator / (const double u){return point(x / u, y / u);}
    double operator * (const point& u){return x*u.y - y*u.x;}
};

typedef point Vector;
typedef vector<point> Polygon;

namespace Vectorial
{
    double getDot (Vector a, Vector b)
    {
        return a.x * b.x + a.y * b.y;
    }
    double getCross (Vector a, Vector b)
    {
        return a.x * b.y - a.y * b.x;
    }
    double getLength (Vector a)
    {
        return sqrt(getDot(a, a));
    }
    double angle(point a, point b)///degree
    {
    double ret = getDot(a, b);
    ret/=(getLength(a)*getLength(b));
    ret = acos(max(-1.0, min(1.0, ret)));///radian
    return (ret*180)/pi;
    }
};

struct Segment
{
    point a;
    point b;
    Segment() {}
    Segment(point aa,point bb)
    {
        a=aa,b=bb;
    }
};

namespace Linear
{
    using namespace Vectorial;
    bool onSegment (point p, point a, point b)
    {
        return dcmp(getCross(a-p, b-p)) == 0 && dcmp(getDot(a-p, b-p)) <= 0;
    }
    double getDistanceToLine (point p, point a, point b)
    {
        return fabs(getCross(b-a, p-a) / getLength(b-a));
    }
// determine if lines from a to b and c to d are parallel or collinear
    bool LinesParallel(point a, point b, point c, point d)
    {
        return fabs(getCross(b-a, c-d)) < eps;
    }

    bool LinesCollinear(point a, point b, point c, point d)
    {
        return LinesParallel(a, b, c, d)
           && fabs(getCross(a-b, a-c)) < eps
           && fabs(getCross(c-d, c-a)) < eps;
    }
// determine if line segment from a to b intersects with
// line segment from c to d
    bool SegmentsIntersect(point a, point b, point c, point d)
    {
        if (LinesCollinear(a, b, c, d))
        {
            if (getLength(c-a) < eps || getLength(d-a) < eps ||
                getLength(c-b) < eps || getLength(d-b) < eps) return true;
            if (getDot(c-a, c-b) > 0 && getDot(d-a, d-b) > 0 && getDot(c-b, d-b) > 0)
                return false;
            return true;
        }
        if (getCross(d-a, b-a) * getCross(c-a, b-a) > 0) return false;
        if (getCross(a-c, d-c) * getCross(b-c, d-c) > 0) return false;
        return true;
    }
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
    point ComputeLineIntersection(point a, point b, point c, point d)
    {
        b=b-a;
        d=c-d;
        c=c-a;
        assert(getDot(b, b) > eps && getDot(d, d) > eps);
        return a + b*getCross(c, d)/getCross(b, d);
    }
}

namespace Triangular
{
    using namespace Vectorial;
    double getArea (point a, point b, point c)
    {
        return fabs(getCross(b - a, c - a)) / 2;
    }
    bool pointInTriangle(point a, point b, point c, point p)
    {
        double s1 = getArea(a,b,c);
        double s2 = getArea(p,b,c) + getArea(p,a,b) + getArea(p,c,a);
        return dcmp(s1 - s2) == 0;
    }
};
namespace Polygonal
    {
    using namespace Vectorial;
    using namespace Linear;
    using namespace Triangular;
    double getSignedArea (point* p, int n)
    {
        double ret = 0;
        for (int i = 0; i < n-1; i++)
            ret += (p[i]-p[0]) * (p[i+1]-p[0]);
        return ret/2;
    }
    int getConvexHull (point* p, int n, point* ch)
    {
        sort(p, p + n);
    // preparing lower hull
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) <= 0) m--;///if take (< 0) then all points on sides also taken
        ch[m++] = p[i];
    }
    // preparing upper hull
    int k = m;
    for (int i = n-2; i >= 0; i--)
    {
        while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;///if take (< 0) then all points on sides also taken
        ch[m++] = p[i];
    }
    if (n > 1) m--;
        return m;
    }
    int isPointInPolygon (point o, point* p, int n)
    {
        int wn = 0;
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            if (onSegment(o, p[i], p[j]) || o == p[i]) return 0;
            int k = dcmp(getCross(p[j] - p[i], o-p[i]));
            int d1 = dcmp(p[i].y - o.y);
            int d2 = dcmp(p[j].y - o.y);
            if (k > 0 && d1 <= 0 && d2 > 0) wn++;
            if (k < 0 && d2 <= 0 && d1 > 0) wn--;
        }
        return wn ? 1 : -1;
    }
    void rotatingCalipersGetDiameter(point *p, int n, vector<Segment>& sol)
    {
        sol.clear();
        int j = 1;
        p[n] = p[0];
        for (int i = 0; i < n; i++)
        {
            while (getCross(p[j+1]-p[i+1], p[i]-p[i+1]) > getCross(p[j]-p[i+1], p[i]-p[i+1]))
            j = (j+1) % n;
            sol.push_back(Segment(p[i],p[j]));
            sol.push_back(Segment(p[i + 1],p[j + 1]));
        }
    }
    void rotatingCalipersGetRectangle(point *p, int n, double& area, double& perimeter)
    {
        p[n] = p[0];
        int l = 1, r = 1, j = 1;
        area = perimeter = 1e20;
        for (int i = 0; i < n; i++)
        {
            Vector v = (p[i+1]-p[i]) / getLength(p[i+1]-p[i]);
            while (dcmp(getDot(v, p[r%n]-p[i]) - getDot(v, p[(r+1)%n]-p[i])) < 0) r++;
            while (j < r || dcmp(getCross(v, p[j%n]-p[i]) - getCross(v,p[(j+1)%n]-p[i])) < 0) j++;
            while (l < j || dcmp(getDot(v, p[l%n]-p[i]) - getDot(v, p[(l+1)%n]-p[i])) > 0) l++;
            double w = getDot(v, p[r%n]-p[i])-getDot(v, p[l%n]-p[i]);
            double h = getDistanceToLine (p[j%n], p[i], p[i+1]);
            area = min(area, w * h);
            perimeter = min(perimeter, 2 * w + 2 * h);
        }
    }
// Tested : https://www.spoj.com/problems/INOROUT
// point must be in ccw order with no three collinear points
// returns inside = 1, on = 0, outside = -1
    int pointInConvexPolygon(point* pt, int n, point p)
    {
        assert(n >= 3);
        int lo = 1, hi = n - 1 ;
        while(hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if(getCross(pt[mid] - pt[0], p - pt[0]) > 0) lo = mid;
            else hi = mid;
        }
        bool in = pointInTriangle(pt[0], pt[lo], pt[hi], p);
        if(!in) return -1;
        if(getCross(pt[lo] - pt[lo-1], p - pt[lo-1]) == 0) return 0;
        if(getCross(pt[hi] - pt[lo], p - pt[lo]) == 0) return 0;
        if(getCross(pt[hi] - pt[(hi+1)%n], p - pt[(hi+1)%n]) == 0) return 0;
        return 1;
    }
};

///***********************
double angle(point a, point b)///degree
{
    double ret = getDot(a, b);
    ret/=(getLength(a)*getLength(b));
    ret = acos(max(-1.0, min(1.0, ret)));///radian
    return (ret*180)/pi;
}

double slope(point a, point b)
{
    return atan2((a.y-b.y),(a.x-b.x));
}
double dis(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double tym(double s, double v)
{
    return s/v;
}
point nxt(double s, point a, point b)///point in segment [a,b] in distance s
{
    point ret;
    double r = s/dis(a, b);
    ret.x = a.x+(r*(b.x-a.x));
    ret.y = a.y+(r*(b.y-a.y));
    return ret;
}
// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) {
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
