class Solution {
public:
    int maxArea(vector<int>& ht) {
        if(ht.size() <= 1)
            return 0;
        int i=0, j=ht.size()-1;
        int maxi = INT_MIN; 
        while(i < j) {
            maxi = max(maxi, (j-i)*(min(ht[i], ht[j])));
            if(ht[j] > ht[i])
                i++;
            else
                j--;
        }

        return maxi;
    }
};
