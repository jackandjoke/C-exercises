#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cassert>
#include<iterator>



int main(int argc, char *argvs[]){
    assert(argc == 2);
    std::ifstream file(argvs[1]);
    std::istream_iterator<std::string> file_begin(file), file_end;
    std::vector<std::string> sents;
    std::copy(file_begin,file_end,back_inserter(sents));
    std::copy(sents.cbegin(),sents.cend(),std::ostream_iterator<std::string>(std::cout,"\n"));
    return 0;
}
