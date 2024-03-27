from enum import Enum
from pygame.rect import Rect
from pygame.surface import Surface


class Color(Enum):
    WHITE = 0
    BLACK = 1

    def texture_coordinate(self) -> float:
        return self.value / 2


class Kind(Enum):
    KING = 0
    QUEEN = 1
    BISHOP = 2
    KNIGHT = 3
    ROOK = 4
    PAWN = 5

    def texture_coordinate(self) -> float:
        return self.value / 6


class Piece:
    def __init__(self, color: Color, kind: Kind) -> None:
        self.color = color
        self.kind = kind

    def __str__(self) -> str:
        return ""

    def draw(self, surface: Surface, t: Surface) -> None:
        x_ratio = self.kind.texture_coordinate()
        y_ratio = self.color.texture_coordinate()

        rect = (t.get_width() * x_ratio, t.get_height() * y_ratio, t.get_width() / 6, t.get_height() / 2)

        surface.blit(t, (0, 0), rect)


