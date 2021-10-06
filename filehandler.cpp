#include "filehandler.hpp"

FileHandler::FileHandler()
{

}
FileHandler::FileHandler(string filename, int *lambda, int *mu, int *M, int *total)
{
	string line;
	inFS.open(filename);

	if(inFS.is_open())
	{
		getline(inFS, line);
		*lambda = stoi(line);
		getline(inFS, line);
		*mu = stoi(line);
		getline(inFS, line);
		*M = stoi(line);
		getline(inFS, line);
		*total = stoi(line);
		/*while(getline(inFS, line))
		{
			cout << line << endl;
		}*/
		inFS.close();
	}
	else
		cout << "ERROR: Unable to Open File " << filename << endl;

}