from board import Board, Piece


def parse_pieces(pieces_str: str) -> list[Piece | None]:
    ranks = pieces_str.split("/")
    pieces = []
    for rank in ranks:
        for piece in rank:
            try:
                for _ in range(int(piece)):
                    pieces.append(None)
            except ValueError:
                pieces.append(piece)
        # Every time we finish with a rank, we should have appended 8 items
        # to the list. If that's not the case, that's an error.
        assert len(pieces) % 8 == 0
    return pieces


def parse_castling_rights(rights_str: str) -> dict[Piece, bool]:
    rights = {}
    for piece in rights_str:
        rights[piece] = True
    return rights


def parse_en_passant_target(target_str: str) -> int:
    if target_str == "-":
        return -1
    # The ascii value of 'a' is 97
    # Bear in mind that the index of a8 is 0
    file = ord(target_str[0]) - 97
    rank = (8 - int(target_str[1])) * 8
    return file + rank


def parse(fen: str) -> Board:
    parts = fen.split()
    return Board(
        pieces=parse_pieces(parts[0]),
        side_to_move=parts[1],
        castling_rights=parse_castling_rights(parts[2]),
        en_passant_target=parse_en_passant_target(parts[3]),
        halfmove_clock=int(parts[4]),
        fullmove_count=int(parts[5]),
    )

