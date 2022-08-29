#include <vector>
#include <string>

using namespace std;

/* My solution */
vector<string> solution(vector<string> picture) 
{
    if (picture.size() == 0) return {};
    if (picture[0].size() == 0) return {};
    
    int len = picture[0].size();
    string line;
    vector<string> ans;
    for (int i = 0; i < len + 2; ++i) line += '*';
    ans.push_back(line);
    for (const string& s : picture)
    {
        ans.push_back(string('*' + s + '*'));
    }
    ans.push_back(line);
    return ans;
}

/* More compact */
std::vector<std::string> solution(std::vector<std::string> picture) {
    for(auto &s: picture)
        s = "*"+s+"*";
    picture.insert(picture.begin(), string(picture[0].size(),'*'));
    picture.insert(picture.end(), string(picture[0].size(),'*'));
    return picture;
}
