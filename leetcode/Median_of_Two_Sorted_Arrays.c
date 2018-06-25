double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int arr[nums1Size + nums2Size];
    int i, j, k, mid;
    
    i = j = k = 0;
    while(i<nums1Size && j<nums2Size)
    {
        if(nums1[i] <= nums2[j])
        {
            arr[k++] = nums1[i++];
        }
        else
        {
            arr[k++] = nums2[j++];
        }
    }
    
    while(i<nums1Size)
    {
        arr[k++] = nums1[i++];
    }
    
    while(j<nums2Size)
    {
        arr[k++] = nums2[j++];
    }   
    
    mid = (nums1Size+nums2Size)/2;
    if( (nums1Size+nums2Size)%2 == 0 )
    {
        return ((double)arr[mid] + (double)arr[mid-1])/2;
    }
    else
    {
        return arr[mid];
    }
}