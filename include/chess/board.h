#pragma once

typedef enum {
  PIECE_BLACK,
  PIECE_WHITE,
} piece_color_t;

typedef enum {
  PIECE_BISHOP,
  PIECE_KING,
  PIECE_KNIGHT,
  PIECE_PAWN,
  PIECE_QUEEN,
  PIECE_ROOK,
} piece_kind_t;

typedef union {

} piece_t;

typedef struct {
  int field;
} board_t;

/**
 * Parses the null-terminated fen string provided and writes the result to the
 * board pointer. It is an error to pass NULL to either parameter.
 */
void board_from_fen(const char *fen, board_t *board);

/**
 * Prints the board to standard out. It is an error to pass NULL into this
 * function.
 */
void board_print(const board_t *board);
