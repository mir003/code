<snippet>
	<content><![CDATA[
///LCS + print*****************************************************
string x,y;
ll m,n,i,j,c[100][100],d[100][100];///1=diag, 2=up, 3= left
ll lcs_length()
{
    memset(c, 0, sizeof c);
    memset(d, 0, sizeof d);
    f(i,m)
    f(j,n)
    {
        if(x[i-1]==y[j-1])
        {
            c[i][j]=c[i-1][j-1]+1;
            d[i][j]=1;
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j]=c[i-1][j];
            d[i][j]=2;
        }
        else
        {
            c[i][j]=c[i][j-1];
            d[i][j]=3;
        }
    }
    return c[m][n];
}
void lcs_print(ll i,ll j)
{
    if(i==0 || j==0)return;
    if(d[i][j]==1)
    {
        lcs_print(i-1,j-1);
        cout<<x[i-1]<<endl;
    }
    else if(d[i][j]==2) lcs_print(i-1,j);
    else lcs_print(i,j-1);
    return;
}
ll main()
{
    while(cin>>x>>y)
    {
        m=x.length();
        n=y.length();
        cout<<lcs_length()<<endl;
        lcs_print(m,n);
    }
    return 0;
}]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
