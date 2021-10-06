#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
#include <fstream>
#include<iostream>
#include<string>
using namespace std;

class FileHandler {
private:
	ifstream inFS;

public:
	FileHandler();
	FileHandler(string filename, int *lambda, int *mu, int *M, int *total);
};

#endif