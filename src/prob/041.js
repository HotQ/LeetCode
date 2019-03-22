/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function (nums) {
    const len = nums.length;
    for (var i = 0; i < len; ++i) {
        var crt = nums[i];
        for (; ;) {
            if (crt <= 0 || crt > len || nums[crt - 1] == crt)
                break;
            var temp = nums[crt - 1];
            nums[crt - 1] = crt;
            crt = temp;
        }
    }
    for (var i = 0; i < len; ++i)
        if (nums[i] != i + 1) return i + 1;

    return len + 1;
};

