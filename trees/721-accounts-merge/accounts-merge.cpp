class Solution {
public:

    int findPar(int u , vector<int> & parent){
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u], parent);
    }

    void join(int u, int v, vector<int> & parent, vector<int> & rank){
        int uPar = findPar(u, parent);
        int vPar = findPar(v, parent);

        if(rank[uPar] > rank[vPar]){
            parent[vPar] = uPar;
        } else if(rank[vPar] > rank[uPar]){
            parent[uPar] = vPar;
        } else{
            parent[uPar] = vPar;
            rank[vPar]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> rank(n, 0);
        vector<int> parent(n);
        for(int i =0 ; i < n ; i++){
            parent[i] = i;
        }

        // USE DSU TO ONLY JOIN USERNAMES

        unordered_map<string, int> emailOwner;

        for(int i =0 ; i < n; i ++){
            for(int j = 0 ; j < accounts[i].size(); j++ ){
                if(j == 0) continue;
                string mail = accounts[i][j];
                if(emailOwner.count(mail)){
                    int owner = emailOwner[mail];
                    join(owner, i, parent, rank);
                }else {
                emailOwner[mail] = i;
                }
            }
        }

        unordered_map<int, set<string>> pen;

        for(int i = 0 ; i < n ; i++){
            int root = findPar(i, parent);

            for(int j =  1; j < accounts[i].size(); j++){
                
                pen[root].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for(auto p : pen){
            vector<string> temp;
            string username = accounts[p.first][0];
            set<string> emails = p.second;

            temp.push_back(username);
            vector<string> m;
            for(string s : emails){
                m.push_back(s);
            }
            sort(m.begin(), m.end());
            for(string s : m){
                temp.push_back(s);
            }

            ans.push_back(temp);
        }

        return ans;

    }
};