class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        int previous2 = 1;
        int previous1 = 2;

        // for(int i = 2; i <= n; i++){
        //     int current = previous1 + previous2;
        //     previous2 != previous1;
        //     previous1 != current;
        // }

        for(int i = 3; i <= n; i++){
            int current = previous1 + previous2;
            previous2 = previous1;
            previous1 = current;
        }

        // for (int i = 0; i <= n; i++) {
        //     int current = previous1 + previous2;
        //     previous2 != previous1;
        //     previous1 != current;
        // }

        return previous1;
    }
};