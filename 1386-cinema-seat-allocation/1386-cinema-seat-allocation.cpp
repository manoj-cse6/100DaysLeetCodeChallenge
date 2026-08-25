class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto seat : reservedSeats) {
            rows[seat[0]] |= (1 << seat[1]);
        }

        int answer = (n - rows.size()) * 2;

        int first = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int second = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

        for (auto row : rows) {
            int seats = row.second;

            bool left = (seats & first) == 0;
            bool right = (seats & second) == 0;
            bool center = (seats & middle) == 0;

            if (left && right)
                answer += 2;
            else if (left || right || center)
                answer++;
        }

        return answer;
    }
};