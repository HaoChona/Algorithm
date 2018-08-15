/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (44.21%)
 * Total Accepted:    111.9K
 * Total Submissions: 253.2K
 * Testcase Example:  '[]\n[]'
 *
 *
 * Given two arrays, write a function to compute their intersection.
 *
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 *
 * Note:
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 *
 * Follow up:
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        int i=0,j=0,len1,len2;
        vector<int> ret;
        len1=(int)nums1.size();
        len2=(int)nums2.size();
        if(len1==0 && len2==0){
            return ret;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<len1 && j<len2){
            if(nums1[i] > nums2[j]){
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] == nums2[j]){
                ret.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ret;
    }
};
