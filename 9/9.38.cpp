#include<vector>
#include<string.h>
#include<iostream>



int main(){
    std::vector<int> vi; 
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    for(int i = 0; i < 7 ; i++)
        vi.push_back(i);
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    int num = vi.capacity() - vi.size();
    for(int i = 0; i < num;i++)
        vi.push_back(i);
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    vi.push_back(1);
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    vi.pop_back();
    vi.shrink_to_fit();
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    vi.reserve(50);
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    vi.reserve(4);
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    vi.shrink_to_fit();
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    vi.resize(4);
    std::cout << vi.size() << " " << vi.capacity() << std::endl;
    vi.shrink_to_fit();
    std::cout << vi.size() << " " << vi.capacity() << std::endl;


    return 0;
}
