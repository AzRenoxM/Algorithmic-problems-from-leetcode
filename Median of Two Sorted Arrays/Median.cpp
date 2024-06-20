#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<double> buffer_vector;
        int size_biggest{0};
        if(nums1.empty() && nums2.empty()) return 0.0;
        if(!nums1.empty() || !nums2.empty()){
            if(nums1.size() >= nums2.size()) size_biggest = nums1.size();
            else size_biggest = nums2.size();
            for(size_t i{0}; i < size_biggest; i++){
                if(i < nums1.size()) buffer_vector.push_back(nums1[i]);
                if(i < nums2.size()) buffer_vector.push_back(nums2[i]);
            }
            std::sort(buffer_vector.begin(), buffer_vector.end());
        }
        if(buffer_vector.size() % 2 == 0){
            return ((buffer_vector[(buffer_vector.size() / 2) - 1] + buffer_vector[buffer_vector.size() / 2]) / 2);
        } else {
            return (buffer_vector[((buffer_vector.size()) - 1) / 2]);
        }
    }
};

int main(){

    Solution something;
    std::vector<int> some1;
    std::vector<int> some2;
    std::vector<int> some3;
    std::vector<int> some4;

    some1.push_back(1);
    some1.push_back(3);
    some2.push_back(2);
    // some3.push_back(1);
    // some3.push_back(2);
    // some4.push_back(3);
    some4.push_back(1);

    // std::cout << something.findMedianSortedArrays(some1, some2) << std::endl; 
    std::cout << something.findMedianSortedArrays(some3, some4) << std::endl; 

    return 0;
}