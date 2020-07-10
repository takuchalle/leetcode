#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int cnt = 0;

    if(numsSize <= 1) {
        return numsSize;
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[cnt] != nums[i]) {
            cnt += 1;
            nums[cnt] = nums[i];
        }
    }

    return cnt + 1;
}

int main(int argc, char* argv[]) {
    int nums[] = {1,3,4,4};

    int size = removeDuplicates(nums, 4);

    printf("%d\n", size);

    return 0;
}