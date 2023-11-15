double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, j, k;
    int* c = (int*)malloc((nums1Size + nums2Size) * sizeof(int)); // Allocate memory for merged array
    i = j = k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            c[k++] = nums1[i++];
        } else {
            c[k++] = nums2[j++];
        }
    }

    while (i < nums1Size) {
        c[k++] = nums1[i++];
    }

    while (j < nums2Size) {
        c[k++] = nums2[j++];
    }

    int len = k; // Length of the merged array

    if (len % 2 != 0) {
        return (double)c[len / 2];
    } else {
        return (c[len / 2 - 1] + c[len / 2]) / 2.0;
    }

    free(c); // Free the allocated memory
}
