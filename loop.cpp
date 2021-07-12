///loop
/// -->*************************************
///^  |
///|  v
///<---
void right() {
//    cout<<"right i "<<i<<" j "<<j<<endl;
    if(j>=m || vis[i][j]==tc) {
        j--;
        i++;
        return;
    }
    j++;
    cnt++;
    right();
}
void down() {
//    cout<<"down i "<<i<<" j "<<j<<endl;
    if(i>=n || vis[i][j]==tc) {
        j--;
        i--;
        return;
    }
    cnt++;
    i++;
    down();
}
void left() {
//    cout<<"left i "<<i<<" j "<<j<<endl;
    if(j<0 || vis[i][j]==tc) {
        j++;
        i--;
        return;
    }
    cnt++;
    j--;
    left();
}
void up() {
//    cout<<"up i "<<i<<" j "<<j<<endl;
    if(i<0 || vis[i][j]==tc) {
        j++;
        i++;
        return;
    }
    cnt++;
    i--;
    up();
}
