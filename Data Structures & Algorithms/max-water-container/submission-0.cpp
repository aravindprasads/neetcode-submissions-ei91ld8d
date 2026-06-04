class Solution {
public:
    int maxArea(vector<int>& ht) {
        int i=0, j=ht.size()-1;
        int maxi = INT_MIN;

        while(i < j) {
            maxi = max(min(ht[i], ht[j]) * (j-i), maxi);
            if(ht[i] < ht[j])
                i++;
            else
                j--;
        }

        return maxi;
    }
};
