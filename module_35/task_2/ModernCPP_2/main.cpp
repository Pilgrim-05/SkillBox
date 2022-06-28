#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
#include <map>

int main() {
    std::vector<int> v{2, 4, 2, 5, 6, 3, 6, 3, 2, 5};
    auto lmd = [](const std::vector<int> &v)
    {
        std::unordered_set<int> st;
        std::map<int, int> mp;
        std::vector<int> newVec;
        for(auto at : v)
        {
            if(st.insert(at).second)
            {
                mp[at] = 1;
                newVec.emplace_back(at);
            }else
            {
                mp[at] +=1;
            }
        }

        for(auto at : mp)
            std::cout << at.first << " => " << at.second << std::endl;

        return std::make_unique<std::vector<int>>(newVec);
    };

    auto pt = lmd(v);

    for(auto at : *pt)
        std::cout << at << " ";
    std::cout << std::endl;
}
