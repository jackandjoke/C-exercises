#include<map>
#include<set>
#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

std::set<char> excludes={'.',',',':','!'};
void wordCount(){

    std::map<std::string,int> mp;
    std::string word;
    while(std::cin >> word) {
        std::transform(word.begin(),word.end(),word.begin(),::tolower);
        /*
        std::string key ="";
        for(const auto &c: word){
            if(excludes.find(c)==excludes.end())
                key+=c;
        }
        mp[key]++;
        */
        word.erase(std::remove_if(word.begin(),word.end(),ispunct),word.end());
        mp[word]++;
    }
    for(const auto &w:mp )
        std::cout << w.first << " appears " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
}

int main(){
    wordCount();

    return 0;
}
