#include<iostream>
#include<string>

class Screen{
public: 
    using pos = std::string::size_type;
    
    Screen() = default;    
    Screen(pos ht, pos wt, pos n): height(ht), width(wt),
    contents(n,' ')
    {}
    Screen(pos ht, pos wt, char c) : height(ht), width(wt),
    contents(ht * wt, c)
    {}

    void print() const{
        std::cout << contents;
    }


private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

};


int main(){
    Screen sc(3,5,'a');
    Screen sb = sc;
    Screen sd(sb);

    sc.print();
    std::cout << std::endl;

    sb.print();
    std::cout << std::endl;

    sd.print();
    std::cout << std::endl;
    return 0;
}
