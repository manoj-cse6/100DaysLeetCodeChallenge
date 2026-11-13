class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int temp = INT_MAX;
        int temp2 = INT_MIN;
        while (x != 0) {
            int d = x % 10;
            x /= 10;
            if (rev > temp / 10 || (rev == temp / 10 && d > 7))
                return 0;
            if (rev < temp2 / 10 || (rev == temp2 / 10 && d < -8))
                return 0;
            rev = rev * 10 + d;
        }
        return rev;
    }
};