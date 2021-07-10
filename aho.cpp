///aho corasik
const int N = 250004, M=504;
int n, name_of_node,res[N], node[N][27], fail[N],TC,path[N],psz,end_node[M];
char txt[1000004],pat[M];

void insrt(char s[], int pos) {
    int now=0, sz=strlen(s);
    for(int i=0; i<sz; i++) {
        if(node[now][s[i]-'a']==-1) {
            node[now][s[i]-'a']= ++name_of_node;
        }
        now=node[now][s[i]-'a'];
    }
    end_node[pos]=now;
    return;
}
void failure() {
    queue<int>q;
    for(int i=0; i<26; i++) {
        if(~node[0][i])
            q.push(node[0][i]);
        else node[0][i]=0;
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=0; i<26; i++) {
            int now = node[u][i];
            if(~now) {
                q.push(now);
                fail[now]=node[fail[u]][i];
                path[++psz]=now;
            } else {
                node[u][i]=node[fail[u]][i];
            }
        }
    }
    return;
}
void aho(char s[]) {
    int now=0, sz=strlen(s);
    for(int i=0; i<sz; i++) {
        now = node[now][s[i]-'a'];
        res[now]++;
    }
    for(int i=psz; i>=1; i--) {
        res[fail[path[i]]]+=res[path[i]];
    }
}

int main() {

    name_of_node=0;
    psz=0;
    memz(path);
    memz(fail);
    memz(res);
    memn(node);
    in1(n);
    scanf("%s", txt);
    for(int i=0; i<n; i++) {
        scanf("%s",pat);
        insrt(pat,i);
    }
    failure();
    aho(txt);
    for(int i=0; i<n; i++) {
        printf("%d\n",res[end_node[i]]);
    }
    return 0;
}

