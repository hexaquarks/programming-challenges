class Solution
{
public:
    int romanToInt(string s)
    {
        int size = s.size();
        int ans = 0;
        map<char, int> symbols { {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} };
        
        for (int i = 0; i < size; ++i)
        {
            if (i + 1 < size && 
                symbols.find(s.at(i))->second < symbols.find(s.at(i + 1))->second)
            {
                ans += symbols.find(s.at(i + 1))->second - symbols.find(s.at(i))->second;
                ++i;
            }
            else
            {
                ans += symbols.find(s.at(i))->second;      
            }
        }
        return ans;
    }
};