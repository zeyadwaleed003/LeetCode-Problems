class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        long long ans = 0;
        priority_queue<int>pq;

        for(int i : gifts)
            pq.push(i);

        while(k--){
            pq.push(sqrt(pq.top()));
            pq.pop();
        }

        int sz = pq.size();
        while(sz-- > 0){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};