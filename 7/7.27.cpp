#include<iostream>
#include<string>
#include<istream>
#include<ostream>

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

    Screen & move(int r, int c);
    Screen & set(char c);
    Screen & display(std::ostream &);
    const Screen & display(std::ostream &) const;


private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream& os) const ;

};

void Screen::do_display(std::ostream &os)const{
    for(decltype(height) i = 0; i < height; i ++)
        os << contents.substr(i*width,width) << std::endl;
}


inline Screen & Screen::move(int r, int c){
    cursor = r * width + c;
    return *this;
}

inline Screen & Screen::set(char c){
    contents[cursor] = c;
    return *this;
}
inline Screen & Screen::display(std::ostream &os){
    do_display(os);
    return *this;
}
inline const Screen & Screen::display(std::ostream &os) const{
    do_display(os);
    return *this;
}


int main(){
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout <<"\n";
    myScreen.move(2,2);
    myScreen.set('*');
    myScreen.display(std::cout);
    std::cout <<"\n";
    return 0;
}
