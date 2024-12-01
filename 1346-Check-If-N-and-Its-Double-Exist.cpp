class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>m;

        int n = arr.size();
        for(int i = 0; i < n; ++i){
            m[arr[i]]++;
            arr[i] *= 2;
        }

        for(int i = 0; i < n; ++i){
            if(m[arr[i]]){
                if(arr[i])
                    return 1;
                if(!arr[i] && m[arr[i]] > 1)
                    return 1;
            }
        }

        return 0;
    }
};