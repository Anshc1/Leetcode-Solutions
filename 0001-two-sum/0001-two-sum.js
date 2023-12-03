/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let indexMap = new Map();
    
    // Iterate through the 'nums' array and store the indices in the map
    for (let i = 0; i < nums.length; i++) {
      indexMap.set(nums[i], i + 1);
    }

    // Create an empty array to store the result
    let result = [];

    // Iterate through the 'nums' array again to find the pair that adds up to the 'target'
    for (let i = 0; i < nums.length; i++) {
      let complement = target - nums[i];
      let j = indexMap.get(complement) - 1;

      // Check if the complement exists in the map and the indices are not the same
      if (j >= 0 && j !== i) {
        // Assign the minimum and maximum of the indices to the result array
        result = [Math.min(i, j), Math.max(i, j)];
        return result;
      }
    }

    // If no solution is found, return an empty array
    return result;

};