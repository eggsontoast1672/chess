use raylib::prelude::*;

fn main() {
    let (mut rl, thread) = raylib::init().size(800, 800).title("Chess").build();

    rl.set_target_fps(60);

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        d.clear_background(Color::WHITE);
        d.draw_text("Hello, world!", 12, 12, 20, Color::BLACK);
    }
}
