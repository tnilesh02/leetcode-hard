class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 == 0 ){
            if(n2%2 == 0){
                return (nums2[(n2-1)/2] + nums2[(n2)/2])/2.0;
            } else {
                return nums2[n2/2];
            }
        }

        if(n2 == 0 ){
            if(n1%2 == 0){
                return (nums1[(n1-1)/2] + nums1[(n1)/2])/2.0;
            } else {
                return nums1[n1/2];
            }
        }

        int x = n1 + n2;
        int tofind = x/2;
        if(x%2){
            tofind++;
        }

        int l = 0;
        int r = n1;
        while(l<r){
            int mid = (l+r)>>1;
            int p = tofind - mid;
            if(p < 0){
                r = mid;continue;
            }
            if(p>n2){
                l=mid+1;continue;
            }
            int a1 = (mid == 0 ? INT_MIN : nums1[mid-1]);
            int a2 = (p==0 ? INT_MIN : nums2[p-1]);
            int b1 = (mid == n1 ? INT_MAX : nums1[mid]);
            int b2 = ( p == n2 ? INT_MAX : nums2[p]);
            if(max(a1,a2) <= min(b1,b2)){
                l =mid;r=mid;break;
            }

            if(a1 > b2){
                r=mid;
            } else {
                l=mid+1;
            }

        }

        int p = tofind - l;
    
        int a1 = (l == 0 ? INT_MIN : nums1[l-1]);
        int a2 = (p==0 ? INT_MIN : nums2[p-1]);
        int b1 = (l == n1 ? INT_MAX : nums1[l]);
        int b2 = ( p == n2 ? INT_MAX : nums2[p]);
        //cout<<max(a1,a2)<<" "<<min(b1,b2)<<endl;
        return (x%2 ? max(a1,a2) : ((max(a1,a2) + min(b1,b2))/2.0));
    }
};