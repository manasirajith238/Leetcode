class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        no=len(nums1)+len(nums2)
        nums=nums1+nums2
        nums.sort()
        if no%2!=0:
            return nums[no/2]
        else:
            return float((nums[no/2]+nums[no/2-1]))/2
        