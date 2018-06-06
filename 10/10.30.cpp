#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>




int main(){
    std::istream_iterator<int> seq_begin(std::cin), seq_end;
    std::vector<int> vi;
    while(seq_begin != seq_end){
        vi.push_back(*seq_begin++);
    }
    //std::copy(seq_begin,seq_end,std::back_inserter(vi));
    std::sort(vi.begin(),vi.end());
    std::copy(vi.cbegin(),vi.cend(),std::ostream_iterator<int>(std::cout," "));
    std::cout<<std::endl;


    return 0;
}
