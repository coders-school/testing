#include <iostream>

#include "Game.hpp"

int main() {
  Game game;
  game.loadFromFile("file.txt");
  auto players = game.getPlayers();
  for (auto player : players) {
      std::cout << player.playerName << '\n';
      for (auto frame : player.playerRolls) {
          std::cout << frame.firstRoll << ", " << frame.secondRoll << '\n';
      }
  }
}
