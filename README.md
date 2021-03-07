# Bacon Game Engine

This project is my introduction into the field of game engine development.
I will be following some guides in the beginning, namely The Cherno's Hazel game engine series on youtube. Links to all sources or 3rd party libraries and systems will be added below.

## RoadMap
Developed as a learning exercise but planned to be a fully functional and powerful 3D game engine. Updates and development is slow because I go as a I learn on my own.

### Upcoming Features
- Powerful and robust 3D rendering (character models, geometry, terrain generation. etc)
- 2D rendering for UI, sprites, etc (easier transition from 3D to 2D rather than 2D to 3D)
- Camera system for control over viewing
- Fully functional physics system
- World and terrain generation
- Audio system
- Artificial Intelligence

## 3rd Party systems

### Graphics
Currently windows and rendering are handled by GLFW and Glad

GLFW is a framework for a simplified OpenGL API.  
Glad is an OpenGl Loading Library for lading pointers to OpenGL functions at runtime for OpenGL versions above 1.1

### Gui
Gui is currently handled by dear ImGui, a simple and robust API for easily creating complex data GUIs.

### Logging
Logging information is handled using the Spdlog library.

## Acknowledgements
- The Cherno
  - [Youtube Channel](https://www.youtube.com/c/TheChernoProject)
  - [Game Engine Development Series](https://thecherno.com/engine)
  - [Hazel Engine Github Page](https://github.com/TheCherno/Hazel)

- spdlog
  - [Github](https://github.com/gabime/spdlog)

- GLFW
  - [Website](https://www.glfw.org)
  - [Github](https://github.com/glfw/glfw)

- Glad
  - [Website](https://glad.dav1d.de)
  - [Github](https://github.com/Dav1dde/glad)

- dear imgui
  - [Github](https://github.com/ocornut/imgui)