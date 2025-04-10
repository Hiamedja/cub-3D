# 🕹️ cub3D

`cub3D` is a 42 Network team project that introduces basic 3D graphics using raycasting.  
Inspired by *Wolfenstein 3D*, the program renders a first-person view of a 2D map using a custom engine built in C with the MiniLibX graphics library.

---

## 💡 Project Goal

The objective of `cub3D` is to render a simple 3D game world based on a 2D map using raycasting techniques, and to allow user interaction via keyboard navigation. The core challenge lies in low-level graphic rendering, data parsing, and input handling.

---

## 🔍 Focus: Map Parsing System

I was responsible for the **entire parsing part** of the project, which is a critical foundation for the game to run properly.

### ✅ Parsing Responsibilities

- 📜 Reading and validating the `.cub` map file
- 🧭 Identifying and storing player starting position and orientation
- 🧱 Ensuring map structure is valid and closed (no holes or open edges)
- 🖼️ Handling texture paths and RGB color values for floor and ceiling
- ⚠️ Comprehensive error detection and message output
- 💾 Memory management for all parsed data

Without a clean and correct parsing process, the game would crash or behave incorrectly. My work ensures that all map data is reliable before the rendering engine starts.

---

## 📁 Map File Format

The `.cub` map file contains:

- Texture paths for each wall (`NO`, `SO`, `WE`, `EA`)
- RGB values for `F` (floor) and `C` (ceiling)
- The 2D map layout using:
  - `1` = Wall
  - `0` = Walkable space
  - `N`, `S`, `E`, `W` = Player start direction

Example:
NO ./textures/north.xpm SO ./textures/south.xpm WE ./textures/west.xpm EA ./textures/east.xpm F 220,100,0 C 225,30,0

111111 100001 1000N1 100001 111111

---

## 🚀 Project Features

- 🧱 3D wall rendering using raycasting (implemented by teammate)
- ⌨️ Keyboard movement (WASD) and camera rotation
- 🧭 2D minimap (optional)
- 🗺️ Fully functional map parsing and validation system
- ❌ Real-time error handling and parsing feedback

---

## 👨‍💻 My Contribution

I handled the **map and configuration file parsing**, which included:

- Reading `.cub` files
- Validating structure, texture paths, and colors
- Allocating and managing memory for map and settings
- Detecting and reporting format errors and inconsistencies

---

## 📦 How to Run

### 1. Compile the project:
2. Launch the game with a .cub map:

./cub3D maps/example.cub
🛠 Requires MiniLibX and a graphical Linux environment

📚 42 Project Info
cub3D is the entry point into the Graphics branch of 42's curriculum. It builds foundational skills in graphics programming, memory management, and data parsing in a low-level environment.

📝 License
This project is part of the 42 Network curriculum. Educational use only.

🙌 Acknowledgements
42 Network

MiniLibX Library

Classic FPS inspiration: Wolfenstein 3D
