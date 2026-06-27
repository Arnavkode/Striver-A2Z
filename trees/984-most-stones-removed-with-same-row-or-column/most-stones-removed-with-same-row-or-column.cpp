class Solution {
public:
    int findPar(vector<int> & parent, int u){
        if(parent[u] == u) return u;

        return parent[u] = findPar(parent,parent[u]);
    }

    void joinByRank(int u, int v, vector<int> & parent, vector<int>& rank){
        int parU = findPar(parent, u);
        int parV = findPar( parent, v);

        if(rank[parU] > rank[parV]){
            parent[parV] = parU;
        }else if(rank[parV] > rank[parU] ){
            parent[parU] = parV;
        } else{
             parent[parU] = parV;
             rank[parV]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int> parent(stones.size());
        vector<int> rank(stones.size(), 0);
        
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;
        for(int i = 0 ; i < stones.size() ; i++){
            auto stone = stones[i];
            int row = stone[0];
            int col = stone[1];
            rows[row].push_back(i);
            cols[col].push_back(i);
        }

        

        for(int i =0 ;i  < parent.size() ; i++){
            parent[i] = i;
        }

        for(int i = 0 ; i < stones.size() ; i++){
            auto stone = stones[i];
            int row = stone[0];
            int col = stone[1];

            for(int stone2 : rows[row]){
                if(i == stone2) continue;
                joinByRank(i, stone2, parent, rank);
            }
            for(int stone2 : cols[col]){
                if(i == stone2) continue;
                joinByRank(i, stone2, parent, rank);
            }
        }

        int parents = 0;
        for(int i = 0 ; i < stones.size() ; i++){
            if(parent[i] == i) parents++;
        }

        return stones.size() - parents;
    }
};

// every ultimate parent can shed its children