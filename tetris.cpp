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
  state *gameTree = new state;

  loadInstance(archiveName, boardHeight, boardWidth, piecesQuantity, activePieces, sequence);

  initBoard(gameTree, boardWidth, boardHeight);



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

  std::cout << "gameTree: " << '\n';

  for (int i = 0; i < boardHeight; i++) {
    for (int j = 0; j < boardWidth; j++) {
      std::cout << gameTree->board[i][j];
    }
    std::cout << '\n';
  }

  return 0;
}
