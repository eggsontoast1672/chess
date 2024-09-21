#include "chess/board.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Copies a string into a heap allocated buffer.
 *
 * TODO: Finish this function documentation
 */
static char *copy_string(const char *s);

/**
 * Parses castling rights from the given string.
 *
 * This function will search the given string for the characters 'K', 'Q', 'k',
 * and 'q', returning castling rights for the white king, white queen, black
 * king, and black queen respectively. This function ignores any character that
 * isn't one of those four, or any duplicates.
 */
static castling_rights_t parse_castling_rights(const char *rights_string);
static void parse_pieces(char *pieces_string, piece_t out_pieces[64]);

void board_from_fen(const char *fen, board_t *board) {
  char *fen_copy = copy_string(fen);

  parse_pieces(strtok(fen_copy, " "), board->pieces);
  board->side_to_move = *strtok(NULL, " ");
  board->castling_rights = parse_castling_rights(strtok(NULL, " "));

  free(fen_copy);
}

void board_print(const board_t *board) {}
bool board_to_fen(const board_t *board, char out_fen[]) { return false; }

char *copy_string(const char *s) {
  size_t size = strlen(s) + 1;
  char *buffer = malloc(size);
  if (buffer == NULL) {
    perror("malloc");
    exit(1);
  }
  return memcpy(buffer, s, size);
}

castling_rights_t parse_castling_rights(const char *rights_string) {
  castling_rights_t rights = CASTLE_NONE;
  for (const char *p = rights_string; *p != '\0'; p++) {
    switch (*p) {
    case 'K':
      rights |= CASTLE_WHITE_KING;
      break;
    case 'Q':
      rights |= CASTLE_WHITE_QUEEN;
      break;
    case 'k':
      rights |= CASTLE_BLACK_KING;
      break;
    case 'q':
      rights |= CASTLE_BLACK_QUEEN;
      break;
    }
  }
  return rights;
}

void parse_pieces(char *pieces_string, piece_t out_pieces[64]) {
  piece_t *current_piece = out_pieces;
  for (char *rank = strtok(pieces_string, "/"); rank != NULL;
       rank = strtok(NULL, "/")) {
    for (size_t i = 0; rank[i] != '\0'; i++) {
      // We only check [1, 8] rather than [0, 9] because fen strings cannot have
      // zeroes or nines in them.
      if ('1' <= rank[i] && rank[i] <= '8') {
        for (size_t j = 0; j < rank[i] - '0'; j++) {
          *current_piece++ = PIECE_NONE;
        }
      } else {
        *current_piece++ = rank[i];
      }
    }
  }
}
