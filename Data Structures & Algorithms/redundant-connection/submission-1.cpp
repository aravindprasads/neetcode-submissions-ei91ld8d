class Solution {
public:

    int findPar(int a, vector<int>& par) {
        cout<<"findPar"<<endl;
        if(a == par[a])
            return a;
        par[a] = findPar(par[a], par);
        return par[a];
    }

    bool union_(int a, int b, vector<int>& size, vector<int>& par) {
        cout<<"union_"<<endl;
        int parA = findPar(a, par);
        int parB = findPar(b, par);

        if(parA == parB)
            return true;

        if(size[a] > size[b]) {
            size[a] += size[b];
            par[parB] = parA;
        } else {
            size[b] += size[a];
            par[parA] = parB;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> par, size;

        for(int i=0; i<edges.size(); i++) {
            par.push_back(i);
            size.push_back(1);
        }

        vector<int> res;
        for(auto it:edges) {
            if(union_(it[0]-1, it[1]-1, size, par)) {                
                res = {it[0], it[1]};
            }
        }
        
        return res;
    }
};
