int a[N];
stack < int > st;
int fun() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    ll res = 0, i=0;
    for(i=0; i<n; i++) {
        if(st.empty()) {
            st.push(i);
        } else {
            if(a[st.top()]<a[i]) {
                st.push(i);
            } else {
                while(!st.empty() && a[st.top()]>a[i]) {
                    ll u = st.top(),area;
                    st.pop();
                    if(st.empty()) {
                        area = a[u] * i;
                    } else {
                        area = a[u] * (i-st.top()-1);
                    }
                    res = max(area,res);
                }
                st.push(i);
            }
        }
    }
    while(!st.empty()) {
        ll u = st.top(),area;
        st.pop();
        if(st.empty()) {
            area = a[u] * i;
        } else {
            area = a[u] * (i-st.top()-1);
        }
        res = max(area,res);
    }
    return res;

}
