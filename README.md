# 2d Dodoi Engine 
ECS, SOLID, DRY, KISS and OOP with c++ 17 and SDL2 

#### Phase 1: Planning and Setup
1. **Define Requirements:**
   - List features and functionalities.
   - Identify target platforms.
   - Set performance goals.

2. **Project Setup:**
   - Set up version control (e.g., Git).
   - Create project structure.
   - Configure build system (e.g., Make).

3. **Dependencies:**
   - Install SDL2.
   - Set up other necessary libraries (e.g., SDL_image, SDL_ttf, SDL_mixer).

#### Phase 2: Core Engine Development
1. **Entity-Component-System (ECS) Framework:**
   - Implement Entity Manager.
   - Implement Component Manager.
   - Implement System Manager.

2. **Basic Components:**
   - Transform (position, rotation, scale).
   - Sprite (texture, rendering).
   - Input (keyboard, mouse).

3. **Basic Systems:**
   - Rendering System.
   - Input System.
   - Physics System (basic collision detection).

#### Phase 3: Advanced Features
1. **Additional Components:**
   - Animation.
   - Audio.
   - Particle System.
   - UI Elements.

2. **Advanced Systems:**
   - Animation System.
   - Audio System.
   - Particle System.
   - UI System.

3. **Resource Management:**
   - Implement Asset Manager (textures, sounds, fonts).
   - Implement Resource Loading and Caching.

#### Phase 4: Game Logic and Tools
1. **Scripting:**
   - Integrate a scripting language (e.g., Lua).
   - Bind scripting language to engine components.

2. **Level Editor:**
   - Create a basic level editor.
   - Implement saving and loading of levels.

3. **Debugging Tools:**
   - Implement logging system.
   - Create in-game debug console.
   - Implement performance profiling tools.

#### Phase 5: Optimization and Testing
1. **Performance Optimization:**
   - Optimize rendering pipeline.
   - Optimize memory usage.
   - Implement multi-threading where applicable.

2. **Testing:**
   - Write unit tests for core components.
   - Perform integration testing.
   - Conduct performance testing.

3. **Bug Fixing:**
   - Identify and fix bugs.
   - Refactor code to improve maintainability.

#### Phase 6: Documentation and Release
1. **Documentation:**
   - Write comprehensive documentation for the engine.
   - Create tutorials and examples.

2. **Community and Support:**
   - Set up a community forum or Discord server.
   - Provide support and gather feedback.

3. **Release:**
   - Package the engine for distribution.
   - Release the engine on platforms like GitHub.

### Detailed Steps for Each Phase

#### Phase 1: Planning and Setup
- **Define Requirements:**
  - Create a detailed feature list.
  - Identify the target audience and platforms.
  - Set clear performance and quality goals.

- **Project Setup:**
  - Initialize a Git repository.
  - Create a directory structure (e.g., 

src

, `include`, `assets`, `tests`).
  - Configure CMake or another build system.

- **Dependencies:**
  - Install SDL2 and other necessary libraries.
  - Set up the build system to include these dependencies.

#### Phase 2: Core Engine Development
- **ECS Framework:**
  - Implement an Entity Manager to handle entity creation and destruction.
  - Implement a Component Manager to handle component storage and retrieval.
  - Implement a System Manager to handle system updates.

- **Basic Components:**
  - Create a Transform component to store position, rotation, and scale.
  - Create a Sprite component to store texture and rendering information.
  - Create an Input component to handle keyboard and mouse input.

- **Basic Systems:**
  - Implement a Rendering System to draw sprites on the screen.
  - Implement an Input System to process input events.
  - Implement a basic Physics System for collision detection.

#### Phase 3: Advanced Features
- **Additional Components:**
  - Create an Animation component to handle sprite animations.
  - Create an Audio component to handle sound effects and music.
  - Create a Particle System component for visual effects.
  - Create UI components for buttons, labels, etc.

- **Advanced Systems:**
  - Implement an Animation System to update animations.
  - Implement an Audio System to play sounds and music.
  - Implement a Particle System to handle particle effects.
  - Implement a UI System to manage user interface elements.

- **Resource Management:**
  - Implement an Asset Manager to load and cache textures, sounds, and fonts.
  - Implement resource loading and caching mechanisms.

#### Phase 4: Game Logic and Tools
- **Scripting:**
  - Integrate a scripting language like Lua.
  - Bind the scripting language to engine components for game logic.

- **Level Editor:**
  - Create a basic level editor for designing game levels.
  - Implement saving and loading of levels in a suitable format (e.g., JSON, XML).

- **Debugging Tools:**
  - Implement a logging system for debugging.
  - Create an in-game debug console for real-time debugging.
  - Implement performance profiling tools to measure and optimize performance.

#### Phase 5: Optimization and Testing
- **Performance Optimization:**
  - Optimize the rendering pipeline for better performance.
  - Optimize memory usage to reduce memory footprint.
  - Implement multi-threading where applicable to improve performance.

- **Testing:**
  - Write unit tests for core components to ensure correctness.
  - Perform integration testing to ensure components work together.
  - Conduct performance testing to identify and fix performance bottlenecks.

- **Bug Fixing:**
  - Identify and fix bugs in the engine.
  - Refactor code to improve readability and maintainability.

#### Phase 6: Documentation and Release
- **Documentation:**
  - Write comprehensive documentation for the engine, including API references and usage guides.
  - Create tutorials and example projects to help users get started.

- **Community and Support:**
  - Set up a community forum or Discord server for users to ask questions and share feedback.
  - Provide support to users and gather feedback for future improvements.

- **Release:**
  - Package the engine for distribution, including binaries and source code.
  - Release the engine on platforms like GitHub and promote it to potential users.


