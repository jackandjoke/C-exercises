#include<fstream>
#include<iostream>
#include<cassert>
#include<iterator>


int main(int argc, char *argvs[]){
    assert(argc == 4);
    std::ifstream in(argvs[1]);
    std::ofstream o1(argvs[2]),o2(argvs[3]);
    std::istream_iterator<int> in_it(in), in_end;
    std::ostream_iterator<int> o1_it(o1," "),o2_it(o2,"\n");
    while(in_it != in_end){
        if(*in_it % 2)
            o1_it = *in_it;
        else
            o2_it = *in_it;
        in_it ++;
    }
    

    return 0;
}
