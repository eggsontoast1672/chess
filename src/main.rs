use raylib::color::Color;
use raylib::prelude::*;

// Dark:    0xb58863
// Light:   0xf0d9b5

const SCREEN_WIDTH: i32 = 800;
const SCREEN_HEIGHT: i32 = 800;

const CELL_WIDTH: i32 = SCREEN_WIDTH / 8;
const CELL_HEIGHT: i32 = SCREEN_HEIGHT / 8;

fn draw_board(d: &mut RaylibDrawHandle) {
    for x in 0..8 {
        for y in 0..8 {
            let color = if (x + y) % 2 == 0 {
                Color::new(0xf0, 0xd9, 0xb5, 0xff)
            } else {
                Color::new(0xb5, 0x88, 0x63, 0xff)
            };

            d.draw_rectangle(
                x * CELL_WIDTH,
                y * CELL_HEIGHT,
                CELL_WIDTH,
                CELL_HEIGHT,
                color,
            );
        }
    }
}

fn main() {
    let (mut rl, thread) = raylib::init()
        .size(SCREEN_WIDTH, SCREEN_HEIGHT)
        .title("Chess")
        .build();

    rl.set_target_fps(60);

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        d.clear_background(Color::WHITE);
        draw_board(&mut d);
    }
}
