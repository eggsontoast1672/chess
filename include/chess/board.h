#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * This represents a piece. A null byte indicates that the current square has no
 * piece on it. Perhaps it is not a good design decision to allow the piece enum
 * to represent that case, but I could not be bothered to do it differently.
 */
typedef enum {
  PIECE_NONE = '\0',
  PIECE_BLACK_BISHOP = 'b',
  PIECE_BLACK_KING = 'k',
  PIECE_BLACK_KNIGHT = 'n',
  PIECE_BLACK_PAWN = 'p',
  PIECE_BLACK_QUEEN = 'q',
  PIECE_BLACK_ROOK = 'r',
  PIECE_WHITE_BISHOP = 'B',
  PIECE_WHITE_KING = 'K',
  PIECE_WHITE_KNIGHT = 'N',
  PIECE_WHITE_PAWN = 'P',
  PIECE_WHITE_QUEEN = 'Q',
  PIECE_WHITE_ROOK = 'R',
} piece_t;

/**
 * The side to move. If it is 'b', it is black's turn to move, and if it is 'w',
 * it is white to play.
 */
typedef enum {
  SIDE_BLACK = 'b',
  SIDE_WHITE = 'w',
} side_to_move_t;

/**
 * A bit field representing castling rights.
 */
typedef enum {
  CASTLE_NONE = 0x00,
  CASTLE_WHITE_KING = 0x01,
  CASTLE_WHITE_QUEEN = 0x02,
  CASTLE_BLACK_KING = 0x04,
  CASTLE_BLACK_QUEEN = 0x08,
} castling_rights_t;

/**
 * A square on the board is simply an index into the array of pieces. Index 0 of
 * that array represents the a8 square, and subsequent indices walk down the
 * ranks of the board, wrapping around to the opposite file when the rank's end
 * is reached, meaning that the h1 square is index 63.
 */
typedef size_t square_t;

/**
 * Encodes all the information about a chess position that a fen string does. We
 * need to be able to parse fen strings into positions and compile positions to
 * fen strings, for which this type should be more than suitable.
 */
typedef struct {
  piece_t pieces[64];
  side_to_move_t side_to_move;
  castling_rights_t castling_rights;
  square_t en_passant_target;
  uint8_t halfmove_clock;
  uint16_t fullmove_count;
} board_t;

/**
 * Parses the null-terminated fen string provided and writes the result to the
 * board pointer. It is an error to pass NULL to either parameter.
 */
void board_from_fen(const char *fen, board_t *out_board);

/**
 * Prints the board to standard out. It is an error to pass NULL into this
 * function.
 */
void board_print(const board_t *board);

/**
 * Creates a fen string out of a board object. It is up to the caller to ensure
 * that the buffer passed is large enough to fit the fen string. A buffer that
 * is 128 bytes large is more than enough to contain any fen string. It is an
 * error to pass NULL as the board.
 */
bool board_to_fen(const board_t *board, char out_fen[]);
