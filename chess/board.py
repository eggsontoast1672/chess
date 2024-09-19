from typing import Literal


Piece = Literal["B", "K", "N", "P", "Q", "R",
                "b", "k", "n", "p", "q", "r"]


class Board:
    def __init__(
        self,
        pieces: list[Piece | None],
        side_to_move: Literal["w", "b"],
        castling_rights: dict[Piece, bool],
        en_passant_target: int,
        halfmove_clock: int,
        fullmove_count: int,
    ) -> None:
        self.pieces = pieces
        self.side_to_move = side_to_move
        self.castling_rights = castling_rights
        self.en_passant_target = en_passant_target
        self.halfmove_clock = halfmove_clock
        self.fullmove_count = fullmove_count
