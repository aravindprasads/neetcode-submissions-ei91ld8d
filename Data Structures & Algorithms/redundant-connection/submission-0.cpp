class Solution {
public:

    // Parent array and size array
    // par -> init as self value
    // size -> init as 1


    int findPar(int a, vector<int>& par) {
        if(a == par[a])
            return a;
        par[a] = findPar(par[a], par);
        return par[a];
    }


    bool unionFind(int a, int b, vector<int>& par, vector<int>& size) {
        a--;
        b--;
        int parA = findPar(a, par);
        int parB = findPar(b, par);

        if(parA == parB)
            return true;

        if(size[a] > size[b]) {
            par[parB] = parA;
            size[parA] += size[parB];
        } else {
            par[parA] = parB;
            size[parB] += size[parA];
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        if(edges.size() == 0)
            return vector<int>{};

        vector<int> par, size;
        for(int i=0; i<edges.size(); i++) {
            par.push_back(i);
            size.push_back(1);
        }

        for(auto it:edges) {
            int a = it[0];
            int b = it[1];

            if(unionFind(a, b, par, size) == true)
                return it;
        }

        return vector<int>{};
    }
};
