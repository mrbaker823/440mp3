#ifndef _IMAGE_H
#define _IMAGE_H

#include<iostream>
#include<vector>


class Image {
	
private:
	
	/*
	data:
	- predictedClass is what the class was classified by the classify function
	- realClass is what the class is defined in its label file
	- stringyImage is the raw input from the ImageSet populate function; it's a string-by-string input, instead of char-by-char
	- imageData stores the chars that make up the individual image in a 2d vector
	*/

	int predictedClass;
	int realClass;
	std::vector<std::string> stringyImage;
	std::vector< std::vector<char> > imageData;

public:
	
	/*
	constructors:
	- default constructor
	- constructor that sets the stringy image
	*/
	Image(){};
	Image(std::vector<std::string> inputStringSet)
	{
		stringyImage = inputStringSet;

	};
	Image(std::vector<std::string> inputStringSet, int realLabel);



	/*
	functions:
	- getters for realClass and predictedClass
	- print prints the stringy verion of the image
	- classify attempts to determine what number class the image defines
	*/

	int getRealClass()
	{
		return realClass;
	};
	int getPredictedClass()
	{
		return predictedClass;
	};
	int getDimension()
	{
		return imageData.size();
	};
	void populateImageData();
	void print();
	int classify();
};

#endif
