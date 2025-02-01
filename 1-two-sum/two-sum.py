class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {

        }
        total_sum = 0
        for i in range(len(nums)):

            total_sum+=nums[i]
            diff = target - nums[i]
            if diff in m:
                return [m[diff],i]
            m[nums[i]] = i
        return