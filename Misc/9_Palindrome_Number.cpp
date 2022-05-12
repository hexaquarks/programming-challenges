class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x<0) return false;
        
        long reverse = 0;
        int original = x, remainder = 0;
        
        while(x)
        {
            remainder = x % 10;
            reverse = reverse * 10 + remainder;
            x /= 10;
        }
        return reverse == original;
    }
};