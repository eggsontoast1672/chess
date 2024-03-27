import pygame
from chess import piece
from chess.piece import Piece


def main() -> None:
    pygame.init()
    screen = pygame.display.set_mode((600, 600), vsync=1)
    chess_pieces = pygame.image.load("assets/chess-pieces.png")
    chess_pieces = pygame.transform.scale_by(chess_pieces, 9 / 40)

    p = Piece(piece.Color.BLACK, piece.Kind.QUEEN)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                return
        screen.fill((0xff, 0x00, 0x00))
        p.draw(screen, chess_pieces)
        pygame.display.flip()


if __name__ == "__main__":
    main()

