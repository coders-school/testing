#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include "Game.hpp"

void make_file(const std::string& filePath) {
  std::ofstream file(filePath, std::ios_base::out);
  file << "Wojtek:55|21|33|X|21\n";
  file << "Jadzia:21|17|7/|3-|X|0-|11|18|X|X||11\n";
  file << "Robert:X|X|X|X|1/|2/|3/|1-|0-|1/||6\n";
  file.close();
}
void remove_file(const std::string& filePath) {
  std::filesystem::remove(std::filesystem::path(filePath));
}

int main() {
  Game game;
  std::string filePath = std::filesystem::current_path().string() + "/franek.txt";
  make_file(filePath);
  game.loadFromFile(filePath);
  auto players = game.getPlayers();
  for (auto player : players) {
      std::cout << player.name << '\n';
      for (auto frame : player.rolls) {
          std::cout << frame.firstRoll << ", " << frame.secondRoll << '\n';
      }
  }
  remove_file(filePath);
}
