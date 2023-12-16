# Boids Simulation

Boids algorithm implemented in C++

## Boids algorithm

Introduced in 1986 to simulate the movement of bird-oids *(boids)* as they
flock together. Based on three rules

1. Boids Flock towards the center of mass
2. Boids avoid boids that are too close 
3. Boids align themselves with the speed of other boids near them

## Demo

![Demo *(with compressed colors)*](assets/demo.fig)

## Implementation 

The `Boid` class in *(defined in `Boid.hpp`)* has a position `Pos2D` and 
velocity `Vec2D` as well as several constants which define a max velocity and 
ranges for alignment and avoidance. The `Environment` class defined in 
`Environment.hpp` defines the grid in which the birds exist. `Boid`s 
turn in the opposite direction when they reach the edge of the grid, which 
leads to buggy behavior *(flocks tend to stay stuck to the edge of the window)*

## Project Structure

```bash
├── assets
│   └── sky.jpg
├── boids
├── Makefile
├── README.md
├── src
│   ├── inc
│   │   ├── Boid.hpp
│   │   ├── Environment.hpp
│   │   ├── Pos2D.hpp
│   │   ├── Vec2D.hpp
│   │   └── Velocity2D.hpp
│   ├── lib
│   │   ├── Boid.cpp
│   │   ├── Environment.cpp
│   │   ├── Pos2D.cpp
│   │   └── Vec2D.cpp
│   └── main
│       └── main.cpp
└── test
    ├── test-boid.cpp
    ├── test-main.cpp
    ├── test-pos2d.cpp
    ├── test-utility.cpp
    ├── test-utility.hpp
    └── test-vec2d.cpp

```

- `boids` is the main exectuable
- `assets/` contains the sky background image used in `main.cpp`
- `src/` contains all source files 
    - `inc/`: all header files
    - `lib/`: all function definition files
    - `main/`: contains the `main.cpp` file
- `test` contains google test files
- `build/` *(not shown)* is there the `.o` object files are placed during
compilation

## Compiling and Running

Compile the main executable with `make boids` from the project root. Requires 
`libsfml` to be installed for drawing the boids

To compile the test executable, run `make test` from the project root. Requires
`gtest`.

## TODO:

Gets slow as more boids are added. Will implement a multi-threaded version at 
some point

