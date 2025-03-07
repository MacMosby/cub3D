# cub3D

*A first-person 3D ray-casting project inspired by Wolfenstein 3D.*

## Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Map Format](#map-format)
- [Bonus Features](#bonus-features)
- [Technologies Used](#technologies-used)
- [Acknowledgments](#acknowledgments)

---

## About the Project
cub3D is a project inspired by the legendary Wolfenstein 3D, widely considered the first FPS game. The objective is to implement a simple 3D graphics engine using ray-casting, allowing the player to navigate a maze from a first-person perspective.

## Features
- **Ray-Casting Rendering:** Generates a 3D perspective from a 2D map.
- **Player Movement:** Navigate using `W, A, S, D` keys and rotate with arrow keys.
- **Wall Textures:** Different textures for North, South, East, and West walls.
- **Color Configurations:** Set floor and ceiling colors separately.
- **Smooth Window Management:** Handles window resizing, focus change, and exit cleanly.
- **Configurable Scene File:** Uses `.cub` files for map configuration.

## Installation
```sh
# Clone the repository
git clone https://github.com/yourusername/cub3D.git
cd cub3D

# Compile the project
make
```

## Usage
Run the program with a `.cub` map file:
```sh
./cub3D maps/example.cub
```
Exit the program:
- Press `ESC`
- Click the window’s close button

## Map Format
Maps must follow a strict `.cub` format. Example:
```
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```
- `1` → Wall
- `0` → Empty space
- `N, S, E, W` → Player’s spawn position and orientation
- The map must be enclosed by walls (`1`).

## Bonus Features
- **Wall Collisions:** Prevents walking through walls.
- **Minimap System:** Displays a top-down view of the map.
- **Interactive Doors:** Doors that can open and close.
- **Animated Sprites:** Adds dynamic objects.
- **Mouse Control:** Rotate the camera using the mouse.

## Technologies Used
- **C** (standard libraries and system calls)
- **miniLibX** (lightweight graphical library)
- **Math Library (`-lm`)** (for ray-casting calculations)

## Acknowledgments
This project is based on a university assignment to develop a deeper understanding of 3D rendering, ray-casting, and low-level graphics programming. If you have any questions, feel free to reach out!

---

Happy coding! 🎮

