# Simple SFML Particle System

[Русский](README.md) | **English**

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus)
![SFML](https://img.shields.io/badge/SFML-2.6.x-8CC445)

A compact educational particle-system example without textures or shaders.
Each particle stores a position, velocity, and color. For efficient rendering,
all particles are collected in a single `sf::VertexArray` using `sf::Points`.

## Demo

Press and hold the **left mouse button**. A stream of particles appears at the
initial click position with random directions, speeds, and colors. Particles
are removed automatically after leaving the window.

## What You Can Learn from the Code

- inheriting from `sf::Drawable` and `sf::Transformable`;
- implementing a custom `draw()` method for a game object;
- rendering many points with a single draw call;
- frame-rate-independent movement using `sf::Time`;
- generating random integer and floating-point values;
- keeping particle data synchronized with a vertex array;
- removing objects outside the screen.

## Structure

- `MyParticleSystem.cpp` — window, input, and particle creation;
- `ParticleSystem.h` — data structures and public interface;
- `ParticleSystem.cpp` — adding, updating, and rendering particles.

## Building with CMake

```powershell
cmake -S . -B build -DBUILD_SHARED_LIBS=OFF
cmake --build build --config Release
./build/Release/MyParticleSystem.exe
```

CMake downloads SFML 2.6.x through `FetchContent` during the first
configuration.

You can also open `MyParticleSystem.sln` in Visual Studio 2022. If SFML is not
installed at `C:\IT\SFML-2.6.1-windows-vc17-64-bit\SFML-2.6.1`, update the
include and library paths in the project properties.

## Experiment Ideas

- add particle lifetime and smooth fading;
- make the emitter follow the cursor;
- apply gravity and drag;
- replace points with textured quads;
- use an object pool to reduce memory allocations.
