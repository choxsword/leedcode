//先把所有元素排序，然后把奇数项相加
#include "leetcode.h"


class Solution
{
  public:
    int arrayPairSum(vector<int> &nums)
    {
        int result=0;
        sort(nums.begin(),nums.end());
        int size=nums.size()/2;
        for(int i=0;i<=size-1;++i)
        {
           result+=nums[2*i]; 
        }
        return result;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().arrayPairSum(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}