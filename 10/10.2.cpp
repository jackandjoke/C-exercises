#include<vector>
#include<algorithm>
#include<iostream>
#include<string>


int main(){
	std::vector<std::string> vect;
	int num;
    std::cout << "Please enter the size of vector\n";
	std::cin >> num;
	for(int i = 0; i < num; i++){
        std::cout << "Please enter a string element\n";
        std::string tmp;
		std::cin >> tmp;
		vect.push_back(tmp);
	}
    std::string ele1 = "hello";
	int v1 = std::count(vect.cbegin(),vect.cend(),ele1);
	std::cout << ele1 << " appears " << v1 << " times\n";
    std::string ele2 = "world";
	int v2 = std::count(vect.cbegin(),vect.cend(),ele2);
	std::cout << ele2 << " appears " << v2 << " times\n";

	return 0;
}
