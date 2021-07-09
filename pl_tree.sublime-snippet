<snippet>
	<content><![CDATA[
const int N = 5010;
int tree[N][26], avail, sz, tc;
int len[N], link[N], t, occ[N], cur, res, node[N];
string s; // 1-indexed
vector<int>adj[N];
void init() {
	// memz(tree);
	len[1] = -1, link[1] = 1;
	len[2] = 0, link[2] = 1;
	avail = cur = 2;
	s = "$" + s;
}
void extend(int pos) {
	while (s[pos - len[cur] - 1] != s[pos]) cur = link[cur];
	int x = link[cur], c = s[pos] - 'a';
	while (s[pos - len[x] - 1] != s[pos]) x = link[x];
	if (!tree[cur][c]) {
		tree[cur][c] = ++avail;
		len[avail] = len[cur] + 2;
		link[avail] = len[avail] == 1 ? 2 : tree[x][c];
	} cur = tree[cur][c];
	occ[cur]++;
	node[pos] = cur;
}
int pal_ending_at_suf(int x) {///memz(occ) for all i in |s|
	if(x<3) return 0;
	if (occ[x]) return occ[x];
	return occ[x] = 1+pal_ending_at_suf(link[x]);
	/*for (int i = 3; i <= avail; i++)
		if (occ[i] == 0) {
			occ[i]=pal_ending_at_suf(i);
		}*/
}

void pl_tree()
{
	init();
	for (int i = 1; i <= sz; i++) {
		extend(i);
	}
}
int solve() {
	cin >> s;
	sz = s.length();
	init();
	for (int i = 1; i <= sz; i++)
		extend(i);
	for (int i = avail; i > 2; i--) {
		occ[link[i]] += occ[i];
	}
	return 0;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>pl</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
