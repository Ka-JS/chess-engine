# Simple Chess Game

A simplified chess engine built with **C++** and **Qt**. This project implements core chess mechanics and piece movement logic with an interactive GUI.

## How to Use

1. **Build & Run:** Open the project in Qt Creator and run it.
2. **Select:** Click on a chess piece to select it.
3. **Move:** Click on the target square.
   * Legal moves are highlighted in **red**.
   * If the move is valid, the piece will move.
4. **Turns:** White always starts. Players take turns automatically.

## Supported Features

* **Board:** Standard 8x8 grid.
* **Pieces:** King, Queen, Rook, Bishop, Knight, Pawn.
* **Movement:** All pieces follow standard chess movement rules.
* **Validation:** strict legal move validation (invalid moves are blocked).

## Limitations (Current Scope)

This version is designed to test movement logic and architecture. The following are **not implemented**:
* Special moves (Castling, En Passant, Pawn Promotion).
* Check/Checkmate/Stalemate detection.

---
*Created by Kalle Salminen*