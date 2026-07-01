class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();
        int i = 0;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Check sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        int result = 0;

        // Step 3: Convert digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Step 4: Overflow check
            if (result > INT_MAX / 10 ||
               (result == INT_MAX / 10 && digit > 7))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};