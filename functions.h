#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>


const std::vector<std::string> explode(const std::string& s, const char& c);
void loadInstance(const std::string& archiveName, int& boardHeight, int& boardWidth, int& piecesQuantity, std::vector<int>& activePieces, std::queue<int>& sequence);
