# Snake Game with Ncurses

Explore the nostalgic realm of classic Snake with this console-based game coded in C using Ncurses. Challenge yourself to maneuver the snake, eat food, and grow longer while avoiding collisions with the walls and yourself.

## How to Play

### Prerequisites

Make sure you have the Ncurses library installed on your system.

### Build and Run

1. **Clone the repository:**

   ```bash
   git clone https://github.com/your-username/your-snake-game.git
   cd your-snake-game
    ```
2. **Build and run the game using the provided Makefile:**

    ```bash
    make run
    ```

# Snake Game Controls

- Use the arrow keys to control the snake's direction:
  - Press `KEY_UP` to go up
  - Press `KEY_DOWN` to go down
  - Press `KEY_LEFT` to go left
  - Press `KEY_RIGHT` to go right

- Enjoy the game! Try to eat the food and grow the snake without hitting the walls or yourself.

## Game Mechanics

- The snake's length is displayed at the top left corner of the game window.
- The game area is bounded by walls, and the snake cannot pass through them.
- Press `q` to exit the game at any time.

## Gameplay Features

- **Food:** The food appears as a white space in the game area. Direct the snake to eat the food and increase its length.
  
- **Scoring:** The length of the snake is a measure of your score. Aim to achieve the highest score possible.

## Development
### Code Structure

- `main.c`: Contains the main function to initialize the game, handle inputs, and run the game loop.
- `game.c`: Implements the core logic of the Snake game, including functions for initializing the game, handling inputs, updating the snake, generating food, and rendering the game window.

### How to Contribute

If you have ideas for improvements, new features, or bug fixes, feel free to contribute! Fork the repository, make your changes, and submit a pull request.

### Acknowledgments

Special thanks to the Ncurses library for making the creation of this console-based Snake game possible.
