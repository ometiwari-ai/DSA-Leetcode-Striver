#include <iostream>
#include <set>
#include <vector>

using namespace std;

void check(const vector<int>& nums, int targetsum, int n, set<vector<int>>& ans, vector<int>& temp) {
    if (n == 0) {
        if (targetsum == 0) {
            ans.insert(temp);
        }
        return;
    }
    if (targetsum >= nums[n - 1]) {
        temp.push_back(nums[n - 1]);
        check(nums, targetsum - nums[n - 1], n - 1, ans, temp);
        temp.pop_back();
        check(nums, targetsum, n - 1, ans, temp);
    }
    return check(nums, targetsum, n - 1, ans, temp);
}

int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    int targetsum = 7;
    set<vector<int>> ans;
    vector<int> temp;

    check(nums, targetsum, nums.size(), ans, temp);

    for (const auto& x : ans) {
        for (int i : x) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}