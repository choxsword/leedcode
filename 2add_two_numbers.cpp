
  //Definition for singly-linked list.
  #define NULL nullptr
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

#include "leetcode.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
      ListNode *result;
        ListNode* end;
        end=result=new ListNode(0);
        int overflow=0;
        ListNode *p1=nullptr,*p2=nullptr;
        for(p1=l1,p2=l2;;)
        {
          
            int sum=p1->val+p2->val+overflow;
            if(sum>9)
            {
                overflow=1;
                end->val=sum-10;
            }
            else
            {
                end->val = sum;
                overflow = 0;
            }
        //    cout<<end->val<<endl;
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == nullptr)
            {
                if (p2 == nullptr)
                {
                    if(overflow==1)
                    {
                        end->next=new ListNode(0);
                        end=end->next;
                        end->val=1;
                    }
                  //  end->next = nullptr;
                    return result;
                }
                else
                {

                    for (; p2 != nullptr; p2 = p2->next)
                    {
                        end->next = new ListNode(0);
                        end = end->next;
                        sum = p2->val + overflow;
                        if (sum > 9)
                        {
                            overflow = 1;
                            end->val = sum - 10;
                        }
                        else
                        {
                            end->val = sum;
                            overflow = 0;
                        }
                    }
                    if (overflow == 1)
                    {
                        end->next = new ListNode(0);
                        end = end->next;
                        end->val = 1;
                    }
                    return result;
                }
            }
            else
            {
                if (p2 != nullptr)
                {

                    end->next = new ListNode(0);
                    end = end->next;
                }
                else
                {

                    for (; p1 != nullptr; p1 = p1->next)
                    {
                        end->next = new ListNode(0);
                        end = end->next;
                        sum = p1->val + overflow;
                        if (sum > 9)
                        {
                            overflow = 1;
                            end->val = sum - 10;
                        }
                        else
                        {
                            end->val = sum;
                            overflow = 0;
                        }
                    }
                    if (overflow == 1)
                    {
                        end->next = new ListNode(0);
                        end = end->next;
                        end->val = 1;
                    }
                   return result;
                }
         
            }
        
        }
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}