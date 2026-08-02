class Solution {
public:

    int findPar(int a, vector<int>& par) {
        cout<<"findPar"<<endl;
        if(a == par[a])
            return a;
        par[a] = findPar(par[a], par);
        return par[a];
    }

    void union_(int a, int b, vector<int>& size, vector<int>& par) {
        cout<<"union_"<<endl;
        int parA = findPar(a, par);
        int parB = findPar(b, par);

        if(parA == parB)
            return;

        if(size[a] > size[b]) {
            size[a] += size[b];
            par[parB] = parA;
        } else {
            size[b] += size[a];
            par[parA] = parB;
        }
    }    

    int countComponents(int n, vector<vector<int>>& edges) {

        //size
        //parent

        //connect each node with Union() and findParent()

        // Numberof nodes with par as -1 --> answer

        vector<int> par, size;

        for(int i=0; i<n; i++) {
            par.push_back(i);
            size.push_back(1);
        }
        
        for(auto it:edges) {
            // cout<<"calling union"<<endl;
            // cout<<it[0]<<it[1]<<endl;
            // return 0;
            union_(it[0], it[1], size, par);
        }
        

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if (par[i] == i)
                cnt++;
        }
        
        return cnt;
    }
};
