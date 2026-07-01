class Solution {
public:
    // Function to calculate the sum of squares of digits
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        while (fast != 1 && slow != fast) {
            slow = getNext(slow);               // Move one step
            fast = getNext(getNext(fast));      // Move two steps
        }

        return fast == 1;
    }
};