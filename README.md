# README

## Project Overview
This project simulates an aquatic ecosystem where various types of creatures, called `Bestiole`, interact with one another in a virtual environment. The simulation features different behaviors and strategies for these creatures, controlled by a strategy pattern. It provides a graphical interface using the CImg library.

---

## Files and Structure

### Source Code Files

- **Aquarium.cpp / Aquarium.h**:
  Implements the `Aquarium` class, the main container for the ecosystem. It initializes the simulation environment and orchestrates the interactions between `Bestiole` instances.

- **Bestiole.cpp / Bestiole.h**:
  Defines the `Bestiole` class, representing individual creatures. Includes properties like position, speed, and various sensory and defensive capabilities.

- **Gregaire.cpp / Gregaire.h**:
  Implements the `Gregaire` behavior, where a `Bestiole` aligns its orientation with its neighbors.

- **Peureuse.cpp / Peureuse.h**:
  Defines a "fearful" behavior, where a `Bestiole` moves away from others if they are detected within its sensory range.

- **Kamikaze.cpp / Kamikaze.h**:
  Implements an aggressive behavior, where a `Bestiole` seeks the closest target and moves towards it with the intent of collision.

- **Prevoyant.cpp / Prevoyant.h**:
  Defines a predictive behavior where the `Bestiole` estimates the future position of other creatures to avoid imminent collisions.

- **Milieu.cpp / Milieu.h**:
  Implements the `Milieu` class, which acts as the environment containing all `Bestiole` instances and handles their interactions and updates.

- **IComportementStrategy.h**:
  Defines the interface for implementing different behavioral strategies for `Bestiole`.

- **CImg.h**:
  Part of the CImg library, providing image processing and graphical rendering capabilities.

- **UImg.h**:
  Wrapper for the `CImg` library to simplify its integration into the simulation.

- **main.cpp**:
  Entry point for the application. Sets up the aquarium dimensions and initializes the population of `Bestiole` instances with different behavior strategies. Starts the simulation loop.

### Supporting Files

- **Makefile**:
  Defines the build process for compiling and linking the project.

- **Object Files (.o)**:
  Compiled object files for each source file.

---

## Key Features

1. **Strategy Pattern**:
   Different behaviors for `Bestiole` are implemented using the strategy pattern, allowing dynamic behavior changes during runtime.

2. **Behavioral Diversity**:
   - `Gregaire`: Aligns orientation with the average orientation of neighbors.
   - `Peureuse`: Moves away from perceived threats.
   - `Kamikaze`: Aggressively targets the closest creature.
   - `Prevoyant`: Predicts and avoids potential collisions.

3. **Graphical Visualization**:
   The simulation is visualized in a window using the CImg library, displaying `Bestiole` movements and interactions in real time.

4. **Dynamic Behavior Switching**:
   `Bestiole` instances with the `hasMultipleBehavior` flag can switch between behaviors at runtime.

---

## How to Build

1. Ensure you have a compatible C++ compiler (e.g., g++) and the CImg library installed.
2. Run `make` to build the project:
   ```
   make
   ```
3. The executable will be generated in the project directory.

---

## How to Run

1. Execute the compiled program:
   ```
   ./main
   ```
2. Follow the prompts to input the percentage distribution of different `Bestiole` behaviors.
3. Observe the simulation in the graphical window.

---

## Dependencies

- **CImg Library**: Required for graphical rendering and image processing.
- **Standard C++ Libraries**: Includes `<iostream>`, `<vector>`, `<memory>`, `<cmath>`, and others.

---

## Future Improvements

1. Add more behaviors to enhance simulation dynamics.
2. Optimize collision detection for better performance with large populations.
3. Integrate additional visualization features, such as real-time statistics or detailed creature profiles.

---

## License

This project is distributed under a dual license: CeCILL-C and CeCILL, as per the CImg library license requirements. Refer to `CImg.h` for detailed licensing information.
