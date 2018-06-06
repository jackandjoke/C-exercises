#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using std::placeholders::_1;

bool check_size(const std::string &s1, std::string::size_type sz){
    return s1.size() > sz;
}


int main(){
    std::vector<std::string> words = {"a","tw","the","maybe","sixsix","four","tententen"};
    std::string str;
    std::cout << "input string: \n";
    std::cin >> str;
    auto pivot = std::find_if(words.cbegin(),words.cend(),std::bind(check_size,_1,str.size()));
    if(pivot == words.cend())
        std::cout<<"Not found\n";
    else{
        std::string fi(*pivot);
        std::cout << fi.size() << std::endl;
    }

    return 0;
}
