int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int*  returnArray = malloc(2 * sizeof(int));
	for(int i = 0; i < numsSize; i++) {
		for(int j = i + 1; j < numsSize; j++) {
			if(target == (nums[i] + nums[j])) {
				returnArray[0] = i;
				returnArray[1] = j;
				*returnSize = 2;
			}
		}
	}
	return returnArray;
}
