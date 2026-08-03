class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map {};

        for(int i { 0 }; i < nums.size(); ++i)
        {
            int need { target - nums[i]};
            auto it { map.find(need) };
            if(it != map.end())
            {
                return { it->second, i};
            }
            else
            {
                map [nums[i]] = i;
            }
            
        }

        return {};
    }
};
