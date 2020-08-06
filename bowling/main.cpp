#include <iostream>

#include "Game.hpp"

int main() {
  Game game;
  game.loadFromFile("file.txt");
  auto players = game.getPlayers();
  for (auto player : players) {
      std::cout << player.Name << '\n';
      for (auto frame : player.Rolls) {
          std::cout << frame.firstRoll << ", " << frame.secondRoll << '\n';
      }
  }
}
