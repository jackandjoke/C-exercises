#include<vector>
#include<algorithm>
#include<iostream>


int main(){
	std::vector<int> vect;
	int num;
	std::cin >> num;
	for(int i = 0; i < num; i++){
		int tmp;
		std::cin >> tmp;
		vect.push_back(tmp);
	}
	int v1 = std::count(vect.cbegin(),vect.cend(),1);
	std::cout << "1 appears " << v1 << " times\n";
	int v2 = std::count(vect.cbegin(),vect.cend(),3);
	std::cout << "3 appears " << v2 << " times\n";

	return 0;
}
