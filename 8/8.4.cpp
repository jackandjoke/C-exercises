#include<fstream>
#include<vector>
#include<iostream>


std::vector<std::string> read_and_print(std::string filename){
    std::vector<std::string> lines;
    std::ifstream ifs(filename);
    if(!ifs){
        std::cerr << "Cannot open file " << filename << std::endl;
        return lines;
    }
    std::string line;
    while(getline(ifs,line)){
        lines.push_back(line);
    }
    ifs.close();
    return lines;
}


int main(int argc, char *argv[]){
    if(argc !=2 ){
        std::cout << "Usage: ./8.4 <filename>\n";
        return 1;
    }
    std::vector<std::string> lines;
    lines = read_and_print(argv[1]);
    for(auto l:lines)
        std::cout << l << "\n";
    return 0;
}
