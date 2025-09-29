# Fractol - 42 Project

A fractal visualization program that renders beautiful mathematical fractals using the MiniLibX graphics library.

## Features

- **Three fractal types:**
  - Mandelbrot set
  - Julia sets (with customizable parameters)
  - Burning Ship fractal

- **Interactive controls:**
  - Mouse wheel zoom (zooms towards cursor position)
  - Arrow key navigation
  - Adjustable iteration count
  - Multiple color schemes
  - Psychedelic color mode

## Prerequisites

Before compiling, you need to install MiniLibX and its dependencies:

### On Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Install MiniLibX:
```bash
# Clone MiniLibX repository
git clone https://github.com/42Paris/minilibx-linux.git mlx_linux

# Or download from the 42 intranet
# Extract MiniLibX to mlx_linux directory in your project root
```

## Compilation

```bash
make
```

This will create the `fractol` executable.

## Usage

### Basic syntax:
```bash
./fractol <fractal_type> [parameters]
```

### Examples:

**Mandelbrot set:**
```bash
./fractol mandelbrot
```

**Julia sets** (requires real and imaginary parts):
```bash
./fractol julia -0.7 0.27015
./fractol julia -0.835 -0.2321
./fractol julia -0.8 0.156
./fractol julia 0.285 0.01
```

**Burning Ship:**
```bash
./fractol burning_ship
```

## Controls

| Key/Mouse | Action |
|-----------|--------|
| **Mouse Wheel Up** | Zoom in (towards cursor) |
| **Mouse Wheel Down** | Zoom out (from cursor) |
| **Arrow Keys** | Navigate around the fractal |
| **+ / -** | Increase/decrease iteration count |
| **Space** | Cycle through color schemes |
| **C** | Toggle psychedelic color mode |
| **ESC** | Exit the program |

## Project Structure

```
fractol/
├── Makefile
├── README.md
├── include/
│   └── fractol.h
└── src/
    ├── main.c          # Main program and argument parsing
    ├── init.c          # MLX initialization
    ├── fractals.c      # Complex number operations and fractal dispatcher
    ├── mandelbrot.c    # Mandelbrot set calculation
    ├── julia.c         # Julia set calculation
    ├── burning_ship.c  # Burning Ship fractal calculation
    ├── render.c        # Rendering and pixel manipulation
    ├── colors.c        # Color generation and schemes
    ├── events.c        # Keyboard and mouse event handling
    └── utils.c         # Utility functions
```

## Mathematical Background

### Mandelbrot Set
The Mandelbrot set is defined as the set of complex numbers c for which the sequence:
- z₀ = 0
- z_{n+1} = z_n² + c

remains bounded (|z_n| ≤ 2) as n approaches infinity.

### Julia Sets
Julia sets are similar to the Mandelbrot set but use a fixed complex parameter c:
- z₀ = pixel coordinate
- z_{n+1} = z_n² + c

Different values of c produce different Julia set shapes.

### Burning Ship
The Burning Ship fractal uses the iteration:
- z₀ = 0
- z_{n+1} = (|Re(z_n)| + i|Im(z_n)|)² + c

## Tips for Beautiful Fractals

### Interesting Julia Set Parameters:
- `./fractol julia -0.7269 0.1889` - Spiral
- `./fractol julia -0.8 0.156` - Lightning
- `./fractol julia -0.4 0.6` - Dendrite
- `./fractol julia 0.285 0.01` - Galaxy
- `./fractol julia -0.835 -0.2321` - Dust

### Navigation Tips:
- Start with a general view and zoom into interesting areas
- Use different color schemes to highlight details
- Try the psychedelic mode for animated-like effects
- Higher iteration counts reveal more detail but render slower

## Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Rebuild everything
```

## Notes

- The program uses the MiniLibX library for graphics
- Designed for Linux systems (key codes may differ on other platforms)
- Optimized for 800x800 pixel window
- Uses double precision for mathematical calculations
- Error handling for invalid arguments and memory allocation failures

## 42 School Standards

This project follows 42 School's coding standards:
- Norm compliant code
- No memory leaks
- Proper error handling
- Makefile with standard rules
- Header file protection