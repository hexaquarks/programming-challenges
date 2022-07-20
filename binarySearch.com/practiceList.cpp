#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map> 

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solutions 
{
public:
    /*
    * TWO SUM
    */
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();

        if (n == 0) return {};
        unordered_map<int, int> mem;
        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            if (mem.find(target - nums[i]) != mem.end())
            {
                ans.push_back(i);
                ans.push_back(mem[target - nums[i]]);
                break;
            }
            else
            {
                mem[nums[i]] = i;
            }
        }

        return ans;
    }

    /*
    * ADD TWO NUMBERS
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode result(0);
        ListNode* curr = &result;
        int sum = 0;

        while (l1 || l2)
        {
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            sum /= 10;
        }

        if (sum > 0 )
        {
            curr->next = new ListNode(sum);
        }
        return result.next;
    }

    /*
    * LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
    * [sliding window]
    */
    int lengthOfLongest(string& s)
    {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> mem(256, -1);
        int ans = 0;
        int start = -1;

        for (int i = 0; i < n; ++i)
        {
            if (mem[s[i]] > start) 
            {
                start = mem[s[i]];
            }
            mem[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
    /*
    * LONGEST PALINDROMIC SUBSTRING 
    */
    int fromMiddle(int l, int r, string& s)
    {
        if (l > r) return -1;
        while (l > 0 && r < s.size() && s[l] == s[r])
        {
            --l; ++r;
        }
        return r - l - 1;
    }
    string length(string& s)
    {
        int n = s.size();
        int start = 0, end = 0;
        if (n == 0) return "";
        
        for (int i = 0; i < n; ++i)
        {
            int even = fromMiddle(i, i, s);
            int odd = fromMiddle(i, i + 1, s);
            int len = max(even, odd);

            if (len > end - start)
            {
                start = i - (len - 1) >> 1;
                end = i + len >> 1;
            }
            return s.substr(start, end + 1);
        }
    }

    /*
    * CONTAINER WITH MOST WATER
    */
   int maxArea(vector<int>& h)
   {
       int n = h.size();
       if (n == 0) return 0;

       int ans = 0;
       int i = 0, j = n - 1;

       while (i < j)
       {
           ans = max(ans, (j - i) * min(h[i], h[j]));
           if (h[i] < h[j]) ++i;
           else --j;
       }
       return ans;
   }

   /*
    * ROMAN TO INTEGER
    */
   int romanToInteger(string& s)
   {
       int n = s.size();
       if (n == 0) return 0;
       unordered_map<char, int> mem{{'I', 1}, {'V', 5}}; /* ... */
       int ans = 0;

       for (int i = 0; i < n; ++i)
       {
           if (mem.find(s[i])->second < mem.find(s[i + 1])->second) 
           {
               ans += mem.find(s[i+1])->second - mem.find(s[i])->second;
               ++i;
           }
           else ans += mem.find(s[i])->second;
       }
       return ans;
   }

   /*
    * LONGEST COMMON SUBSTRING
    */
   string longestCommonSubstring(vector<string>& strs)
   {
       int n = strs.size();
       if (n == 0) return "";

       sort(strs.begin(), strs.end());
       string first = strs[0];
       string last = strs[n - 1];
       string ans = "";

       for (int i = 0; i < first.size(); ++i)
       {
           if (first[i] == last[i]) ans += first[i];
           else break;
       }
       return ans;
   }
};