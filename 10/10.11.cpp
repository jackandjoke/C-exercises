#include<vector>
#include<iostream>
#include<algorithm>
#include<string>


void elimDups(std::vector<std::string> &words){
    std::sort(words.begin(),words.end());
    auto end_unique = std::unique(words.begin(),words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const std::string &s1, const std::string &s2){
    return s1.size() < s2.size();
}

int main(){
    std::vector<std::string> words = {"jumps","slow","quick","turtle","over","the","red","fox"};
    elimDups(words);
    stable_sort(words.begin(),words.end(),isShorter);
    for(const auto &w:words)
        std::cout << w << " ";
    std::cout << std::endl;
    return 0;
}
