#include<map>
#include<iostream>

void wordCount(){
    std::map<std::string,int> mp;
    std::string word;
    while(std::cin >> word) {
        auto it = mp.insert({word,1});
        if(!it.second)
            it.first->second ++ ;
    }
    for(const auto &w:mp )
        std::cout << w.first << " appears " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
}

int main(){
    wordCount();

    return 0;
}
