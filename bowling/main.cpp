#include <fstream>
#include <iostream>
#include <string>

#include "BowlingAlley.hpp"
#include "Game.hpp"
#include <algorithm>
#include <cstring>

bool isHelpFlag(int argc, const char** argv) {
  for (int i = 1; i < argc; ++i) {
    if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      return true;
    }
  }
  return false;
}

void printManual() {
  std::cout << "program ma przyjmować 2 parametry z linii komend.\n";
  std::cout << "Pierwszy to katalog, w którym będą pliki txt ze stanami gier na torach,\n";
  std::cout << "a drugi opcjonalny to plik wyjściowy, w którym mają zostać zapisane przetworzone wyniki.\n";
  std::cout << "Jeśli drugi parametr nie zostanie podany to wyniki mają zostać wypisane na ekran.\n";
  std::cout << "Przykład użycia: ./bowling inputDirectory results.txt\n";
}

int main(int argc, const char** argv) {
  if (argc <= 1) {
    return -1;
  }
  if (isHelpFlag(argc, argv)) {
    printManual();
    return 0;
  }
  BowlingAlley alley(argv[1]);
  if (argc >= 3) {
    std::ofstream file(argv[2]);
    alley.printOutputTo(file);
  } else {
    alley.printOutputTo(std::cout);
  }
}
