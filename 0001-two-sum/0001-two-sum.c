int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ptr = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ptr[0] = i;
                ptr[1] = j;
                *returnSize = 2;
                return ptr;
            }
        }
    }
    
    free(ptr);
    *returnSize = 0;
    return NULL;  
}