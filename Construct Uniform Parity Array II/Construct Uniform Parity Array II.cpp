// Solution for Construct Uniform Parity Array II in CPP

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = *min_element(nums1.begin(), nums1.end());

        // If the minimum element is odd, we can make all elements odd:
        // any even element nums1[i] can subtract minVal (which is odd) to become odd,
        // since even - odd = odd, and nums1[i] - minVal >= 0 (minVal is the smallest).
        // Any already-odd element keeps its value. So all-odd is always achievable
        // when the minimum is odd.
        if (minVal % 2 == 1) return true;

        // The minimum is even. We cannot make all elements odd, because to make
        // an odd element nums1[i] odd via subtraction, we'd need to subtract an even
        // number — but subtracting any even element still leaves nums1[i] odd only if
        // nums1[j] is even, and nums1[i] - nums1[j] would be odd - even = odd. However,
        // we can only subtract nums1[j] if nums1[i] > nums1[j], and the minimum is even,
        // so there is no even number smaller than minVal to subtract from an odd element.
        // Therefore, if any element is odd, we cannot make all elements even either.
        for (int num : nums1) {
            if (num % 2 == 1) return false;
        }

        // All elements are already even — trivially all-even is satisfied.
        return true;
    }
};
