#ifndef _IMAGESET_H
#define _IMAGESET_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"Image.h"



class ImageSet {

private:

	/*
	data: 
	- imageLineup is a vector of image objects 
	- filePath is the path to the set of images
	*/

	std::vector<Image> imageLineUp;
	Image aggregateZero;
	Image aggregateOne;
	Image aggregateTwo;
	Image aggregateThree;
	Image aggregateFour;
	Image aggregateFive;
	Image aggregateSix;
	Image aggregateSeven;
	Image aggregateEight;
	Image aggregateNine;

public:

	/*
	constructors:
	- default constructor
	- constructor that takes the path to the images and the path to the images and the path to the labels and populates the lineup
	*/

	ImageSet(){};
	ImageSet(bool training);
	
	/*
	functions:
	- searches imageLineUp for all images classified as as a certain int class and displays them
	- checks to see if imageLineUp has been populated (debug)
	- populateLineUp populates the imageLineUp vector with images from either the training set or the test set
 	- classify runs Image.classify on the image lineup and returns a vector of ints that it determined the images to be
	*/

	void checkForNums(int n);
	void makeClassAggregate(int n);
	void lineUpCheck();
	void populateLineUp(bool training);
	void classifyLineUp();

	/*
	aggregate functions:
	- generates the aggregate 

};

#endif
