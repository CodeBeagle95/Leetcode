#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

void SetPivot(vector<int> nums, int i, int j) {
    if (i >= j) return;
    int pick_offset = rand() % (j - i);
    if (pick_offset) swap(nums[i], nums[i + pick_offset]);
}

void RecursiveSort(vector<int>& nums, int i, int j) {
    if (i >= j) return;

    SetPivot(nums, i, j);

    int mark = i;
    for (int k = i + 1; k < j; ++k) {
        if (nums[k] < nums[i]) {
            ++mark;
            if (mark != k) swap(nums[mark], nums[k]);
        }
    }
    if (mark != i) swap(nums[mark], nums[i]);
    RecursiveSort(nums, i, mark);
    RecursiveSort(nums, mark + 1, j);
}

vector<int> FastSort(vector<int>& nums) {
    srand((unsigned)time(NULL));
    RecursiveSort(nums, 0, nums.size());
    return nums;
}

