#include"ImageSet.h"
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<vector>


void ImageSet::populateLineUp(bool training)
{

	//if training == true, then set paths to training sets. else, set path to test sets
	
	std::string charLine, labelLine;
	const char* imagePath;
	const char* labelPath;

	switch (training)
	{
		case true:
			imagePath = "../data/trainingimages";
			labelPath = "../data/traininglabels";
			break;
		case false:
			imagePath = "../data/testimages";
			labelPath = "../data/testlabels";
			break;
	}

	std::ifstream imageFile (imagePath);
	std::ifstream labelFile (labelPath);

	if (imageFile.is_open() && labelFile.is_open())
	{
		while (imageFile.good() && labelFile.good())
		{	
			std::vector<std::string> imageStringVec;	//the vector to be populated by 28 strings
			for (int x = 0; x < 28; x++)			//loops for the (relative) size of all of the chars
			{
			
				getline (imageFile, charLine);		//retrieves the current string in the image file
				imageStringVec.push_back(charLine);	//and puts it on the current image string
			}

			getline (labelFile, labelLine);			//retrieves the current line in the labels listing

			if (labelFile.eof())				//HACK CITY HACK HACK CITY
				break;
			
			
			int labelVal = atoi (labelLine.c_str());	//converts the line to a const char ** then to an int
			Image x = Image(imageStringVec, labelVal);	//Creates an image with the corresponding char array and label
			imageLineUp.push_back(x);			//pushes the image onto the main vector in the ImageSet class
		}
		imageFile.close();
		labelFile.close();
	}

}

ImageSet::ImageSet(bool training)
{
	populateLineUp(training);
}

void ImageSet::checkForNums(int n)   			//(debug) finds all images with a certain label and prints them
{	
	for (std::vector<Image>::iterator it = imageLineUp.begin(); it != imageLineUp.end(); it++)
	{
		if (it->getRealClass() == n)
			it->print();
	}
};

std::vector< std::vector<double> > ImageSet::makeClassAggregate(int n)		//returns a 2d vector of doubles representing probabilities of the training set
{
	std::vector<Image> classDefinedSet;

	std::vector<double> classDefinedProbabilityLine;			//used in construction of the return vector
	std::vector< std::vector<double> > classDefinedProbabilitySet;		//the return vector
	
	for (std::vector<Image>::iterator it = imageLineUp.begin(); it != imageLineUp.end(); it++)   	/*constructs a vector of only
													images with a certain label*/
	{
		if (it->getRealClass() == n)
			classDefinedSet.push_back(*it);
	
	}

	for (std::vector<Image>::iterator it = classDefinedSet.begin(); it != classDefinedSet.end(); it++) /*iterates through the class-
													   defined set and constructs
													   an "average" digit  using
													   laplacian smoothing of the 
													   relative character frequency
													   ratios*/
	{													
	int blankCount = 0;
	int edgeCount = 0;
	int mainCount = 0;

		for (int i = 0; i < it->getDimension(); i++)
		{
			for (int j = 0; j < it->getDimension(); j++)
			{
				std::cout << it->imageData[i][j] << " ";
				switch(it->imageData[i][j])
				{
					case(' '):
						blankCount++;
						break;
					case('+'):
						edgeCount++;
						break;
					case('#'):
						mainCount++;
						break;
				}
				
			}
			std::cout << "\n";
		}
	std::cout << blankCount << "  " << edgeCount << "  " << mainCount << "\n";
	std::cout << "Counts aggregated!\n";

	}
	std::cout << "Iterator exited!\n";

};
