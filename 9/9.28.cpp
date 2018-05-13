#include<forward_list>
#include<string>
#include<iostream>

void insert_str(std::forward_list<std::string> &fl, const std::string &s1, const std::string &s2){
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while(curr != fl.end()){
        if(*curr == s1){
            prev = curr;
            break;
        }else{
            prev = curr;
            curr ++;
        }
    }

    fl.insert_after(prev,s2);

}

int main(){
    std::forward_list<std::string> fl={"aa","ab","ac"};
    insert_str(fl,"ab","abb");
    for(const auto &ele : fl)
        std::cout << ele << " ";
    std::cout << std::endl;

    insert_str(fl,"ax","am");
    for(const auto &ele : fl)
        std::cout << ele << " ";
    std::cout << std::endl;

    return 0;
}
