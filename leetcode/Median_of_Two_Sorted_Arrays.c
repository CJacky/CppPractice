class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int totalNum = nums1.size() + nums2.size();
        int middle = (totalNum-1) / 2;
        bool isOdd = totalNum % 2;
        double A, B, T;
        
        for(int i=0, i1=0, i2=0; i<totalNum; ++i)
        {
            if( i1 < nums1.size() && i2 < nums2.size() )
            {
                if( nums1[i1] < nums2[i2] )
                {
                    T = nums1[i1++];
                }
                else
                {
                    T = nums2[i2++];
                }
            }
            else if( i1 < nums1.size() )
            {
                T = nums1[i1++];
            }
            else
            {
                T = nums2[i2++];
            }
            
            if( i == middle )
            {
                A = T;
            }
            
            if( i == middle+1)
            {
                B = T;
                break;
            }
            
        }
        
        return (isOdd)? A : (A+B)/2;
    }
};
