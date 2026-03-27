class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<32; i++) {
            int sum = 0;
            for(int num : nums) {
                if((num >> i) & 1) {
                    sum++;
                }
            }
            if(sum % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};









//Bit Counting (Easy to Understand)
💡 Steps
Loop through 32 bits
Count how many numbers have that bit set
Take % 3
Rebuild the answer