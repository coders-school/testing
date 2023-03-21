# TDD

## Test Driven Development

Technika pisania testów przed napisaniem implementacji. Funkcjonalności implementujemy w następujących fazach:

1. Red
2. Green
3. Refactor

___

## Zanim zaczniemy

Zanim zaczniemy, warto zastanowić się nad architekturą rozwiązania i utworzyć szkielet aplikacji z systemem budowania.
Jeśli rozwijamy już istniejące funkcjonalności to lepiej, bo pewnie wszystko jest gotowe 🙂

___

## Przykład

### Gra w szachy

Chcemy zaimplementować grę w szachy.
Zakładamy, że każda figura będzie reprezentowana przez oddzielną klasę, a sama szachownica będzie 2 wymiarową tablicą (8x8) wskaźników na figury.

___

## Faza Red

Piszemy test. Po skompilowaniu kodu, test nie będzie przechodził, ponieważ nie mamy implementacji, która spełnia jego wymagania.

```cpp
TEST(BoardTest, PieceCanBePlacedOnBoard) {
  Board board;
  Piece* piece = new Pawn();
  board.setPiece(0, 0, piece);
  EXPECT_EQ(board.getPiece(0, 0), piece);
}
```

Powyższy test niejako narzuca nam też projekt klas. Zaczynamy od użycia (co jest właściwe).

___

### UWAGA! Ważne rzeczy:

* Piszemy tylko 1 test! Nie wszystkie testy dla danej klasy/funkcjonalności.
* Test oraz aplikacja muszę się kompilować po tej fazie. Oznacza to, że musimy utworzyć także używane klasy w możliwie jak najprostszej wersji

```cpp
class Piece {};

class Pawn : public Piece {};

class Board {
public:
   void setPiece(int row, int col, Piece* piece);
   Piece* getPiece(int row, int col) const;
};
```

___
<!-- .slide: style="font-size: 0.85em" -->

## Faza Green

Implementujemy MINIMALNĄ funkcjonalność potrzebną do tego, aby test przeszedł.

```cpp
class Board {
public:
    Board() {
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                board[row][col] = nullptr;
            }
        }
    }

    void setPiece(int row, int col, Piece* piece) {
        board[row][col] = piece;
    }

    Piece* getPiece(int row, int col) const {
        return board[row][col];
    }

private:
    Piece* board[8][8];
};
```

Po tej fazie ZAWSZE rób commit!

___

## Faza Refactor

Refaktoryzujemy kod i/lub testy. Myślimy co można poprawić.

```cpp
constexpr size_t boardSize = 8;

class Board {
public:
    Board() {
        for (int row = 0; row < boardSize; row++) {
            for (int col = 0; col < boardSize; col++) {
                board[row][col] = nullptr;
            }
        }
    }

    // ...

private:
    Piece* board[boardSize][boardSize];
};
```

___

### Pamiętaj o kilku zasadach refactoringu

1. NIGDY nie zmieniaj jednocześnie testów oraz implementacji. Jeśli test przestanie przechodzić, to nie będziesz wiedzieć, czy powodem jest zmiana testu czy implementacji na niepoprawne.
2. Usuwaj zduplikowany kod wyciągając go do funkcji.
3. Zmieniaj projekt klas i interfejsy, jeśli to uprości implementację.

   Np. zamiast podawać dwie współrzędne od 0 do 7, możemy podawać nazwę pola jako <code>std::string</code> typu "A2", "H8". Będziemy potrzebować nowej klasy - adaptera z jednym wartości do drugich z możliwością ich walidacji.

4. Nie pomijaj tej fazy. Często przy pierwszych testach nie będzie nic do refaktoryzacji, ale później ta faza jest obowiązkowa.

Po tej fazie również zrób commit. Może ich być kilka - jeden na każde ulepszenie.

___
<!-- .slide: style="font-size: 0.85em" -->

## Powtórz

Przechodź cyklicznie przez fazy Red-Green-Refactor dodając kolejne wymagania, aż zaimplementujesz rozwiązanie w całości.

### Red

```cpp
TEST(BoardTest, PieceCanBeMovedOnBoard) {
  Board board;
  Piece* piece = new Pawn();
  board.setPiece(0, 0, piece);
  board.makeMove(0, 0, 1, 0);
  EXPECT_EQ(board.getPiece(1, 0), piece);
  EXPECT_EQ(board.getPiece(0, 0), nullptr);
}
```

### Green

```cpp
void Board::makeMove(int fromRow, int fromCol, int toRow, int toCol) {
    Piece* piece = board[fromRow][fromCol];
    board[fromRow][fromCol] = nullptr;
    board[toRow][toCol] = piece;
}
```

___

## Zobacz demo

[Zrób swój pierwszy projekt w C++: baza danych krok po kroku](https://www.youtube.com/watch?v=y50a0UbE3nI)
