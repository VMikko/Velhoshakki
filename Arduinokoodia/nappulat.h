#pragma once

char input() {
  char input;
  char apu;
  while (!Serial.available()) {
    delay(50);
  }
  input = Serial.read();
  delay(50);
  Serial.println(input);
  while (Serial.available() > 0) {
    char apu = Serial.read();
  }
  Serial.flush();

  return input;
}

using namespace std;

// Pieces and colors can only be these specific values
enum Piece {Empty, Pawn, Bishop, Rook, Knight, Queen, King};
enum Color {None, White, Black};


//A singular square in the chess-board
class Square {
public:
    Piece piece;
    Color color;
    /*int x;
    int y;*/

    // default constructor, every Square that isn't given any parameters will be like this
    Square() {
        piece = Empty;
        color = None;
    }
    // Sets the squares piece and color according to the parameters
    void setPieceColor(Piece p, Color c) {
        piece = p;
        color = c;
    }
    Piece getPiece() {
        return piece;
    }
    // useless
    void setColor(Color c) {
        color = c;
    }
    Color getColor() {
        return color;
    }
    void removePiece() {
        piece = Empty;
        color = None;
        // TODO: in arduino make the piece go off the board, if there is a piece there that is
    }

};

/*
// Not used currently, if time redo the whole thing with these
class Nappula {
public:
    // these might not be needed, but just in case
    int x;
    int y; 
    bool white;
    bool alive;
    //
    Board board;
    bool move();
    
    Nappula(Board b, bool w) {
        board = b;
        white = w;
    }
};

class pawn : public Nappula {
    bool move() {}
};

*/