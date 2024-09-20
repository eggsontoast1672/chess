#include <stdio.h>

#include "chess/board.h"

static const char *const starting_fen =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

int main(void) {
  board_t board;
  board_from_fen(starting_fen, &board);
  board_print(&board);
  printf("Everything is working!\n");
  return 0;
}
