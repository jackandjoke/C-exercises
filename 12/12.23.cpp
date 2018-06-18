#include<iostream>
#include<cstring>
#include<string>


int main(){
    const char* s1 = "hello ";
    const char* s2 = "world\n";
    char* vs = new char[strlen(s1)+strlen(s2)+1];
    strcpy(vs,s1);
    strcat(vs,s2);
    std::cout << vs;
    delete [] vs;


    std::string str1 = "hhhh";
    std::string str2 = "jjj";
    char *nstr = new char[str1.size()+str2.size()+1];
    for(int i = 0; i < str1.size(); i++)
        nstr[i] = str1[i];
    for(int i = 0; i < str2.size(); i++)
        nstr[i+str1.size()] = str2[i];

    std::cout << nstr;
    delete [] nstr;
    return 0;
}
