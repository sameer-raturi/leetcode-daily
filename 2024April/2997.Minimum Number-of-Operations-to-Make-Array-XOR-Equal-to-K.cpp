class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sumXor = 0;
        for(int i=0;i<nums.size();i ++){
            sumXor^=nums[i];
        }
        int xorWithK = sumXor^k, count=0;
        for(int i=0;i<32;i++){
            if(1<<i & xorWithK){
                count++;
            }
        }
        return count;
    }
};