#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include "functions.h"

int main(int argc, char const *argv[]) {

  std::string archiveName = argv[1];
  int boardHeight, boardWidth, piecesQuantity;
  std::vector<int> activePieces;
  std::queue <int> sequence;

  loadInstance(archiveName, boardHeight, boardWidth, piecesQuantity, activePieces, sequence);

  int board[boardWidth][boardWidth];

  // Prints
  std::cout << "boardHeight: " << boardHeight << std::endl;
  std::cout << "boardWidth: " << boardWidth << std::endl;
  std::cout << "piecesQuantity: " << piecesQuantity << std::endl;

  std::cout << "Sequence: ";
  for (int i = 0; i < piecesQuantity; i++) {
    std::cout << sequence.front () << ", ";
    sequence.pop ();
  }


  std::cout << "\nactivePieces: ";
  std::vector<int>::iterator it = activePieces.begin();
  while(it != activePieces.end())
  {
      std::cout<<*it<<", ";
      it++;
  }

  std::cout << std::endl;
  return 0;
}
