import pygame


def main() -> None:
    pygame.init()
    screen = pygame.display.set_mode((600, 600), vsync=1)
    chess_pieces = pygame.image.load("assets/chess-pieces.png")
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                return
        screen.fill((0xff, 0x00, 0x00))
        screen.blit(chess_pieces, (0, 0))
        pygame.display.flip()


if __name__ == "__main__":
    main()

