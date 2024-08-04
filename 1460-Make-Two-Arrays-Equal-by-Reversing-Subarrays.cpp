class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) 
    {
        map<int,int>frqTar, frqArr;
        for( int i = 0; i < arr.size(); i++ )
            frqTar[target[i]]++, frqArr[arr[i]]++;

        for( int i = 0; i < arr.size(); i++ )
        {
            if( frqTar[arr[i]] != frqArr[arr[i]] )
                return 0;
        }

        return 1;
    }
};