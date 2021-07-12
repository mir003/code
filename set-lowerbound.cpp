ll set_lower_bound(ll val) { ///less than val
    auto it = st.lower_bound(val);
    if(it==st.begin())
        return -1;
    else {
        it--;
        return *it;
    }
}
