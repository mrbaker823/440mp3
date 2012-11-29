#include"Image.h"
#include<vector>

void Image::print()
{

	for (int x = 0; x<28; x++)
	{
		for (int y = 0; y<28; y++)
		{
			std::cout << imageData[x][y];
		}
		std::cout << "\n";
	}

	std::cout << "Labelled as: " << realClass << std::endl;
};


void Image::populateImageData()
{
	for (int i = 0; i <28; i++)
	{
		std::string shredee = stringyImage[i];
		std::vector<char> data(shredee.begin(), shredee.end());
		imageData.push_back(data);
	}


};


Image::Image(std::vector<std::string> inputStringSet, int realLabel)
{
	stringyImage = inputStringSet;
	realClass = realLabel;
	populateImageData();
}

