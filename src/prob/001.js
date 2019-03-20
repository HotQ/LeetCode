/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    for (var i = 0; i < nums.length - 1; ++i) {
        var subtarget = target - nums[i];
        for (var j = i + 1; j < nums.length; ++j) 
            if (subtarget == nums[j]) 
                return new Array(i, j);
    }
};
