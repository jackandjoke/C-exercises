#include<vector>
#include<iostream>
#include<string>
#include<algorithm>


inline
bool predicate(const std::string &s){
    return s.size() >= 5;
}


int main(){
    std::vector<std::string> words = {"hello","world","to","you","and","cn","shanghai"};
    auto end_long = std::partition(words.begin(),words.end(),predicate);
    for(auto it = words.begin(); it != end_long; it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
