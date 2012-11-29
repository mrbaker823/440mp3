#include"Image.h"
#include"ImageSet.h"
#include<iostream>

int main(int argc, char** argv)
{
	std::cout << "Check for which number?\n";
	int num;
	std::cin >> num;
	std::cout << "Enter 1 for training data, 0 for test data\n";
	int testNum;
	std::cin >> testNum;
	bool test = (testNum == 0) ? false:true;
	ImageSet testSet = ImageSet(test);
	testSet.checkForNums(num);

return 0;
}
