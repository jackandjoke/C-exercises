#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<functional>

using namespace std::placeholders;

bool check_size(const std::string &s1, std::string::size_type sz){
    return s1.size() >= sz;
}




void biggies(std::vector<std::string> &words, std::string::size_type sz){
    std::sort(words.begin(),words.end(),[](const std::string &s1, const std::string &s2){ return s1.size() < s2.size();}); 
    auto pivot = std::find_if(words.begin(),words.end(),std::bind(check_size,_1,sz));
    std::for_each(pivot, words.end() ,[](const std::string &s){ std::cout << s << " ";});
    std::cout<< std::endl;
}


int main(){
    std::vector<std::string> words = {"This","is","not","a","hard","problem"};
    biggies(words,1);
    biggies(words,2);
    biggies(words,3);
    biggies(words,4);
    biggies(words,5);
    biggies(words,8);

    return 0;
}
