#include"Image.h"
#include"ImageSet.h"
#include<iostream>
#include<vector>

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
	std::vector< std::vector<char> > theGoodShit = testSet.makeClassAggregate(num);

	for (int i = 0; i<28; i++)
	{
		for (int j = 0; j<28; j++)
		{
			std::cout<<theGoodShit[i][j];
		}
		std::cout << "\n";
	}

return 0;
}
