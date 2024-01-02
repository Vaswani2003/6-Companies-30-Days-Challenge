class Solution {
public:
    int minimizeSet(long long div1, long long div2, int cnt1, int cnt2)
    {
        long long total = cnt1 + cnt2;
        long long l = 1, r = 1e12, ans = 0;
        long long lcm = lcm(d1,d2), common, mid, onlyA, onlyB;

        while (l <= r) // while left is less than right
        {
            mid = (l + r) / 2;
            common = mid / lcm; // numbers div by both d1 and d2

            onlyA = mid / div2 - common; // numbers div by d2 only and not d1
            onlyB = mid / div1 - common; // numbers div by d1 only and not d2

            total = max(0ll, cnt1 - onlyA) + max(0ll, cnt2 - onlyB); // count of values yet to be filled - vacant

            if (mid - onlyA - onlyB >= total + common) // if vacant blocks + common blocks less are less than count of values that are not div by d1 and d2 and are hence spare values
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
