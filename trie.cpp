ll n, name_of_node,ans, root, node[1000010][26], child[1000010];
char s[100010][100];
bool isword[100010];
void initialize(ll node) {
    for(ll i=0; i<26; i++)
        node[node][i]=-1;
}
void insrt(char s[]) {
    ll sz=strlen(s);
    ll now=root;
    for(ll i=0; i<sz; i++) {
        if(node[now][s[i]-'a']==-1) {
            child[now]++;
            node[now][s[i]-'a']= ++name_of_node;
            initialize(name_of_node);
        }
        now=node[now][s[i]-'a'];
    }
    isword[now]=1;
}
