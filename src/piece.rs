pub enum PieceColor {
    Black,
    White,
}

pub enum PieceKind {
    Bishop,
    King,
    Knight,
    Pawn,
    Queen,
    Rook,
}

pub struct Piece {
    color: PieceColor,
    kind: PieceKind,
}

impl Piece {
    fn new(color: PieceColor, kind: PieceKind) -> Self {
        Self { color, kind }
    }
}

impl std::str::FromStr for Piece {
    type Err = ();

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        use PieceColor as PC;
        use PieceKind as PK;

        match s {
            "b" => Ok(Piece::new(PC::Black, PK::Bishop)),
            "k" => Ok(Piece::new(PC::Black, PK::King)),
            "n" => Ok(Piece::new(PC::Black, PK::Knight)),
            "p" => Ok(Piece::new(PC::Black, PK::Pawn)),
            "q" => Ok(Piece::new(PC::Black, PK::Queen)),
            "r" => Ok(Piece::new(PC::Black, PK::Rook)),
            "B" => Ok(Piece::new(PC::White, PK::Bishop)),
            "K" => Ok(Piece::new(PC::White, PK::King)),
            "N" => Ok(Piece::new(PC::White, PK::Knight)),
            "P" => Ok(Piece::new(PC::White, PK::Pawn)),
            "Q" => Ok(Piece::new(PC::White, PK::Queen)),
            "R" => Ok(Piece::new(PC::White, PK::Rook)),
            _ => Err(()),
        }
    }
}
