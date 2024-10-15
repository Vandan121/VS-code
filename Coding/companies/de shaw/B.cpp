#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph,int i,vector<int> &code,int c){
    code[i] = c;
    for(auto x:graph[i]){
        if(code[x] == -1){
            dfs(graph,x,code,c);
        }
    }
}
int helper(vector<int> &vec){
    int n = vec.size();
    if(n==1) return vec[0];
    int ans = (vec[0] & vec[1]);
    for(int i=2;i<n;i++){
        ans &= vec[i];
    }
    return ans;
}
void func(int n,int e,vector<int>g_from,vector<int>g_to,vector<int>g_weights,vector<vector<int>> queries ){
    vector<int> code(n+1,-1);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<e;i++){
        graph[g_from[i]].push_back(g_to[i]);
        graph[g_to[i]].push_back(g_from[i]);
    }
    for(int i=1;i<=n;i++){
        if(code[i] == -1){
            dfs(graph,i,code,i);
        }
    }
    map<int,vector<int>> m;
    for(int i=0;i<e;i++){
        m[code[g_from[i]]].push_back(g_weights[i]);
    }
    int n1 = m.size();
    vector<int> pre_ans(n1+1);
    for(int i=1;i<=n1;i++){
        pre_ans[i] = helper(m[i]);
    }
    int q = queries.size();
    vector<int> ans(q,-1);
    for(int i=0;i<q;i++){
        int a = queries[i][0];
        int b = queries[i][1];
        if(code[a] == code[b]){
            ans[i] = pre_ans[code[a]];
        }
    }
    return ans;
}

int main(){
    int n,e; cin>>n>>e;
    vector<int> g_from(e),g_to(e),g_weights(e);
    for(int i=0;i<e;i++){
        cin>>g_from[i]>>g_to[i]>>g_weights[i];
    }
    int q; cin>>q;
    vector<vector<int>> queries(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin>>queries[i][0]>>queries[i][1];
    }
    func(n,e,g_from,g_to,g_weights,queries);
    return 0;
}
