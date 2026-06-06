class Solution:
    def findMaxLength(self, nums):
        count = 0
        max_len = 0

        first_occurrence = {0: -1}

        for i in range(len(nums)):
            if nums[i] == 1:
                count += 1
            else:
                count -= 1

            if count in first_occurrence:
                max_len = max(max_len, i - first_occurrence[count])
            else:
                first_occurrence[count] = i

        return max_len
        