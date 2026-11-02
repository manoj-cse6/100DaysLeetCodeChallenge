class Solution {
public:
    bool isPerfectSquare(int n) {
        int root = static_cast<int>(std::sqrt(n));
        return (root * root == n);
    }
public:
    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        int temp = n;
        while (temp % 4 == 0) {
            temp /= 4;
        }
        if (temp % 8 == 7) {
            return 4;
        }
        for (int i = 1; i * i <= n; ++i) {
            if (isPerfectSquare(n - i * i)) {
                return 2;
            }
        }
        return 3;
    }
};