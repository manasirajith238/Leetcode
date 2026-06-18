class Solution:
    def lengthOfLongestSubstring(self, s):
        char_index = {}
        left = 0
        max_length = 0

        for right, char in enumerate(s):

            # If char is already in current window,
            # move left pointer
            if char in char_index and char_index[char] >= left:
                left = char_index[char] + 1

            # Store latest index of char
            char_index[char] = right

            # Update answer
            max_length = max(max_length, right - left + 1)

        return max_length