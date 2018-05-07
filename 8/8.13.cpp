#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<fstream>
#include<cassert>

struct PersonInfo{
    std::string name;
    std::vector<std::string> phones;
};

void print_person(PersonInfo &p){
    std::cout << p.name << std::endl;
    for(auto ph: p.phones)
        std::cout << ph << std::endl;
    std::cout << "=======\n";
}

int main(int argc, char *argv[]){
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;

    std::ifstream ifs(argv[1]);
    assert(ifs);

    while(getline(ifs,line)){
        PersonInfo info;
        record.clear();     // !! clear the state
        record.str(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    for(auto & p : people){
        print_person(p);
    }
    return 0;
}


