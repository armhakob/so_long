# so_long

**so_long** is a 2D game project developed as part of the 42 curriculum. It involves creating a small, fun game using the **MiniLibX** library, focusing on rendering, event handling, and basic game mechanics.

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Gameplay](#gameplay)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)

## About the Project

The **so_long** project challenges you to create a simple 2D game. The game involves moving a player around a map, collecting items, and reaching an exit. It emphasizes working with graphics libraries and handling events such as keyboard inputs.

## Features

- 2D rendering using **MiniLibX**.
- Player movement and interaction with the environment.
- Collectible items and a reachable exit.
- Validations for the map format and gameplay rules.
- Error handling for invalid inputs and edge cases.

## Gameplay

The game uses a `.ber` file as the map, with specific elements:

- `0` for empty space.
- `1` for walls.
- `P` for the player starting position.
- `C` for collectibles.
- `E` for the exit.

The player must collect all the collectibles before reaching the exit to win.

## Getting Started

### Prerequisites

- A C compiler (GCC or Clang).
- **MiniLibX** library (provided as part of the project).
- GNU Make.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/armhakob/so_long.git
   cd so_long
2. Compile the game:
   ```bash
   make
This will create the executable `so_long` .

###Usage

Run the game with a valid `.ber` map files as an argument:
```bash
./so_long path/to/map.ber
```
Example:
```bash
./so_long maps/example.ber
```
###Controls
- `W`: Move up
- `A`: Move left
- `S`:Move down
- `D`:Move right
- `ESC`:Quit the game
