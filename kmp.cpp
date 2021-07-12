ll p[N];
string a,b;
vector<ll>v;
void fail() {
    ll sz=b.length(),j=0, i=1;
    while(i<sz && j<sz) {
        while(b[j]!=b[i] && j<sz && i<sz) {
            if(j==0) {
                p[i]=0;
                i++;
                break;
            } else {
                j=p[j-1];
            }
        }
        while(b[j]==b[i] && j<sz && i<sz) {
            p[i]=j+1;
            j++;
            i++;
        }
    }
    for(ll i=0; i<sz; i++)
        cout<<p[i]<<endl;
    return;
}
void kmp() {
    longest_suf_pref();
    ll sz=a.length(),sz2=b.length(),cnt=0,i=0;
    for(ll j=0; j<sz && i<sz2; j++) {
        for(ll ii=0; ii<sz; ii++) {
            if(ii==j)
                cout<<"( "<<a[ii]<<" )";
            else
                cout<<a[ii];
        }
        cout<<"\n";
        for(ll ii=0; ii<sz2; ii++) {
            if(ii==i)
                cout<<"( "<<b[ii]<<" )";
            else
                cout<<b[ii];
        }
        cout<<"   "<<i<<" "<<j<<"\n";
        if(a[j]!=b[i]) {
            if(i>0) {
                i=p[i-1];
                j--;
            }
        } else {
            if(i==sz2-1) {
                v.push_back(j-i);
                if(i>0) {
                    i=p[i-1];
                    j--;
                }
            } else {
                i++;
            }
        }
    }
}
