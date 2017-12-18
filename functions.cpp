#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>

// Split string function
const std::vector<std::string> explode(const std::string& s, const char& c)
{
	std::string buff{""};
	std::vector<std::string> v;

	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);

	return v;
}

void loadInstance(const std::string& archiveName, int& boardHeight, int& boardWidth, int& piecesQuantity, std::vector<int>& activePieces, std::queue<int>& sequence){

	std::ifstream instance(archiveName, std::ios::in);

  if (!instance.is_open()) {
    std::cerr << "Unable to open file\n";
    exit(1);
  }

  std::string line;
  std::vector<std::string> splitLine;

  // First line
  std::getline(instance, line);
  splitLine = explode(line, ' ');

  boardWidth = std::stoi(splitLine[0]);
  boardHeight = std::stoi(splitLine[1]);

  // Second line
  std::getline(instance, line);
  piecesQuantity = std::stoi(line);

  // Third line
  std::getline(instance, line);
  splitLine = explode(line, ' ');

  for (size_t i = 0; i < splitLine.size(); i++) {
    activePieces.push_back(std::stoi(splitLine[i]));
  }

  // Fourth line
  std::getline(instance, line);
  splitLine = explode(line, ' ');

  for (size_t i = 0; i < splitLine.size(); i++) {
    sequence.push(std::stoi(splitLine[i]));
  }

  // close archive
  instance.close();
}
