class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        vector<vector<int>> answer;
        int d = 0, step = 1;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        while (answer.size() < rows * cols) {
            for (int x = 0; x < 2; x++) {
                for (int i = 0; i < step; i++) {
                    if (r >= 0 && r < rows && c >= 0 && c < cols)
                        answer.push_back({r, c});
                    r += dr[d];
                    c += dc[d];
                }
                d = (d + 1) % 4;
            }
            step++;
        }

        return answer;
    }
};