class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        map<string,int>frq;
        for( string s : arr )
            frq[s]++;

        vector<string>dist;
        for( string s : arr )
        {
            if( frq[s] == 1 )
                dist.push_back(s);
        }

        k--;
        return ((k < dist.size())? dist[k] : "");  
    }
};