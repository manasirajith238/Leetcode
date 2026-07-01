class Solution {
public:
    vector<string> ans;

    vector<string> mapping = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string current) {

        // Base case
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // Letters corresponding to current digit
        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            backtrack(digits, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        backtrack(digits, 0, "");

        return ans;
    }
};