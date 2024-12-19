/*https://www.youtube.com/watch?v=tgVSkMA8joQ*/

#include <iostream>
#include <vector>
using namespace std;

/*
    Answers the question : if target is in nums, what index is it at? if not, where should it be placed
    in either case, we need to ask a question for each mid in nums : is this number < target
    and the first number that returns false to this question is the answer to our question
*/
int binSearch(vector<int>& nums, int target){
    int l = 0, r = nums.size()-1;
    while(l < r){
        int mid = l + (r-l)/2;
        /*
            We need to ask the question for mid: is this number < target
            If it is, it's a true value ie this should be on the left of target
            if it's not, it's either the target itself or should be on the right of target 
        */
        if(nums[mid] < target) //we ask if number at mid < target
            l = mid+1; //if yes, this is a true value so a false value should occur only AFTER mid so l=mid+1
        else 
        //but if num at mid is not less than target and is >= target then the first false value can at max occur at mid or anywhere before it so r = mid
            r = mid;
    }
    return l;
    //once we reach l=r which inevitably happens due to the loop, we exit the loop and l will be at the first false value
    //so in case of a target present in nums, l points to the index of that target
    //in case of a target appearing multiple times in nums, l points to the index where it first occurs in nums
    //in case the target isn't in nums, l points to the index where it should be placed to maintain the sorted property of the array
}

int main()
{
    vector<int> nums = {2,3,5,7,7,8};
    
    cout << binSearch(nums, 4) << endl;

    return 0;
}
