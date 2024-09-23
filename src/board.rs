use crate::piece::{Piece, PieceColor};

struct CastlingRights {
    white_kingside: bool,
    white_queenside: bool,
    black_kingside: bool,
    black_queenside: bool,
}

impl CastlingRights {
    pub fn none() -> Self {
        Self {
            white_kingside: false,
            white_queenside: false,
            black_kingside: false,
            black_queenside: false,
        }
    }
}

#[derive(Debug)]
enum ParseCastlingRightsError {
    InvalidCharacter,
    InvalidLength,
}

impl std::fmt::Display for ParseCastlingRightsError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::InvalidCharacter => write!(f, "invalid character found in string"),
            Self::InvalidLength => write!(f, "string is incorrect length"),
        }
    }
}

impl std::error::Error for ParseCastlingRightsError {}

impl std::str::FromStr for CastlingRights {
    type Err = ParseCastlingRightsError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        if s.is_empty() || s.len() > 4 {
            return Err(ParseCastlingRightsError::InvalidLength);
        }

        let mut rights = CastlingRights::none();
        if s == "-" {
            return Ok(rights);
        }

        for c in s.chars() {
            match c {
                'K' => rights.white_kingside = true,
                'Q' => rights.white_queenside = true,
                'k' => rights.black_kingside = true,
                'q' => rights.black_queenside = true,
                _ => return Err(ParseCastlingRightsError::InvalidCharacter),
            }
        }

        Ok(rights)
    }
}

struct Square(usize);

impl Square {
    pub fn new(index: usize) -> Option<Self> {
        if index < 64 {
            Some(Self(index))
        } else {
            None
        }
    }
}

struct Board {
    pieces: [Option<Piece>; 64],
    side_to_move: PieceColor,
    castling_rights: CastlingRights,
    en_passant_target: Option<Square>,
    halfmove_clock: u8,
    fullmove_count: u16,
}

impl std::str::FromStr for Board {
    type Err = ();

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        todo!()
    }
}
