#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>


struct state {
  state *prevStep;
  std::vector<state *> nextStep;
  int board [100][200];
  int actualPiece;
  int totalDeletedLines;
  int thisStateDeletedLines;
  int stepNumber;
};

const std::vector<std::string> explode(const std::string& s, const char& c);
void loadInstance(const std::string& archiveName, int& boardHeight, int& boardWidth, int& piecesQuantity, std::vector<int>& activePieces, std::queue<int>& sequence);
void initBoard(state *&gameTree, int boardWidth, int boardHeight);
