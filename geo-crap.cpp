D RedToDeg(D x) {
    return (180*x)/pi;
}
D mintodeg(D x) {
    return x/60;
}
D brittochap(D r, D theta) {
    return r*theta;
}
D DegToRed(D x) {
    return (pi*x)/180;
}

///radius of circumcircle**********************************
D rc(D a, D b, D c) {
    return (a*b*c)/(sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)));
}
///radius of innercircle***********************************
D ri(D a, D b, D c) {
    D s=(a+b+c)/2;
    return sqrt(((s-a)*(s-b)*(s-c))/s);
}
D median_c(D a, D b, D c) {
    return (sqrt(2*a*a + 2*b*b - c*c))/2;
}
pair<double, double> intersect(ll x[], ll y[]) { ///intersect point of two lines
    a = ((y[1]-y[2])*(x[3]-x[4])) - ((y[3]-y[4])*(x[1]-x[2]));
    b = ((x[3]-x[4])*((x[1]*(y[1]-y[2]))-(y[1]*(x[1]-x[2]))))-((x[1]-x[2])*((x[3]*(y[3]-y[4]))-(y[3]*(x[3]-x[4]))));
    X = b/a;
    a = ((x[3]-x[4])*(y[1]-y[2]))- ((x[1]-x[2])*(y[3]-y[4]));
    b = ((y[3]-y[4])*((x[1]*(y[1]-y[2]))-(y[1]*(x[1]-x[2]))))-((y[1]-y[2])*((x[3]*(y[3]-y[4]))-(y[3]*(x[3]-x[4]))));
    Y = b/a;
    return {X,Y};

}
bool parallel(ll x[], ll y[]) { ///returns whether two lines are parallel or not
    ll c1 = (y[1]-y[2])*(x[3]-x[4]);
    ll c2 = (y[3]-y[4])*(x[1]-x[2]);
    if(c1==c2)
        return 1;
    return 0;
}
bool same_line(ll x[], ll y[]) { ///returns whether two lines are same or not
    ll c1 = x[1]*(y[1]-y[2])-y[1]*(x[1]-x[2]);
    ll c2 = x[3]*(y[1]-y[2]) - y[3]*(x[1]-x[2]);
    ll c3 = x[4]*(y[1]-y[2]) - y[4]*(x[1]-x[2]);
    if(c1==c2 && c1==c3)
        return 1;
    return 0;
}
void find_fourth_point() { ///returns the fourth point of a parallelogram given end points of two adjacent sides
    double a,b;
    struct point {
        pair<double, double>s,e;
    } p[3];
    pair<double, double>com;
    scanf("%lf%lf",&a,&b);
    p[1].s = {a,b};
    scanf("%lf%lf",&a,&b);
    p[1].e = {a,b};
    scanf("%lf%lf",&a,&b);
    p[2].s = {a,b};
    scanf("%lf%lf",&a,&b);
    p[2].e = {a,b};
    if(p[1].s==p[2].s || p[1].s==p[2].e) {
        com=p[1].s;
        if(p[1].s==p[2].s)
            printf("%.3f %.3f\n", p[1].e.first+p[2].e.first-com.first, p[1].e.second+p[2].e.second-com.second);
        else
            printf("%.3f %.3f\n", p[1].e.first+p[2].s.first-com.first, p[1].e.second+p[2].s.second-com.second);

    } else {
        com = p[1].e;
        if(p[1].e==p[2].s)
            printf("%.3f %.3f\n", p[1].s.first+p[2].e.first-com.first, p[1].s.second+p[2].e.second-com.second);
        else
            printf("%.3f %.3f\n", p[1].s.first+p[2].s.first-com.first, p[1].s.second+p[2].s.second-com.second);

    }
}
///equation:x1a+y1b+z1c=k1,x2a+y2b+z2c=k2,x3a+y3b+z3c=k3
D nirnayok(D x[],D y[], D z[]) {
    return x[1]*(y[2]*z[3]-z[2]*y[3])-y[1]*(x[2]*z[3]-x[3]*z[2])+z[1]*(x[2]*y[3]-x[3]*y[2]);
}
void eq3(D x[],D y[], D z[], D k[]) {
    D del=nirnayok(x[1],y[1],z[1],x[2],y[2],z[2],x[3],y[3],z[3]);
    D dela=nirnayok(k[1],y[1],z[1],k[2],y[2],z[2],k[3],y[3],z[3]);
    D delb=nirnayok(x[1],k[1],z[1],x[2],k[2],z[2],x[3],k[3],z[3]);
    D delc=nirnayok(x[1],y[1],k[1],x[2],y[2],k[2],x[3],y[3],k[3]);
    a=ceil(dela/del);
    b=delb/del;
    c=delc/del;
}
D nirnayok(D x[],D y[]) {
    return x[1]*(y[2]*z[3]-z[2]*y[3])-y[1]*(x[2]*z[3]-x[3]*z[2])+z[1]*(x[2]*y[3]-x[3]*y[2]);
}
void eq3(D x[],D y[], D k[]) {
    D del=nirnayok(x[1],y[1],x[2],y[2],x[3],y[3]);
    D dela=nirnayok(k[1],y[1],k[2],y[2],k[3],y[3]);
    D delb=nirnayok(x[1],k[1],z[1],x[2],k[2],z[2],x[3],k[3],z[3]);
    D delc=nirnayok(x[1],y[1],k[1],x[2],y[2],k[2],x[3],y[3],k[3]);
    a=ceil(dela/del);
    b=delb/del;
    c=delc/del;
}
D area_of_triangle_given_three_points(D x[], D y[]) {
    D z[5];
    z[1]=1;
    z[2]=1;
    z[3]=1;
    return (nirnayok(x, y, z))/2;
}
