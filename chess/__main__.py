import fen
import pprint

STARTING_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"


def main() -> None:
    board = fen.parse(STARTING_FEN)
    pprint.pprint(board.__dict__)


if __name__ == "__main__":
    main()

