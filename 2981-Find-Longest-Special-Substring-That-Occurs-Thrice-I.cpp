class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        unordered_map<string, int>m;
        priority_queue<int>pq;
        pq.push(-1);

        for(int i = 0; i < n; ++i){
            int p = i;
            string str;

            while(p < n){
                str += s[p];
                m[str]++;

                if(m[str] >= 3)
                    pq.push(str.size());
                    
                p++;
                if(p == n || str[str.size() - 1] != s[p])
                    break;
            }
        }

        return pq.top();
    }
};