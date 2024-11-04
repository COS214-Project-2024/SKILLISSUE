# COS214 Project : City Builder

## Project Overview
The **City Builder Simulation** is a C++ project designed to model the complexities of urban development and management. Players can construct and manage different aspects of a virtual city, including infrastructure, resources, transportation, and citizen satisfaction. The simulation applies various design patterns to ensure scalability, maintainability, and flexibility, making it a robust educational tool for software engineering concepts.

## Key Features
- **Building Management**: Construct residential, commercial, industrial, and landmark buildings with unique attributes.
- **Resource Management**: Manage utilities like power, water, sewage, and waste disposal for efficient city operations.
- **Transportation System**: Build roads and manage public transit to support city connectivity.
- **Citizen Satisfaction**: Monitor and respond to citizen needs and satisfaction affected by policies and services.
- **Government Policies**: Implement taxation and budget management to fund city development.

## Design Patterns Used
The project integrates multiple design patterns, such as Singleton, Observer, Factory, Mediator, and Command, to support a scalable and modular architecture.

## Prerequisites
- **Compiler**: A C++11 or higher compiler is required.
- **SFML Library**: The project uses the SFML library for graphics. Install SFML by following the instructions at [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php).

## Directory Structure
- **src/**: Contains all source code files (`.cpp` files).
- **include/**: Contains all header files (`.h` files).
- **docs/**: Documentation generated with Doxygen.
- **Data/**: Contains the `media` folder with assets like textures and configuration files required by the simulation.
- **build/**: Directory for compiled binary files (if using a build system like CMake).
- **README.md**: Project overview, setup instructions, and usage guidelines.

## Compilation and Setup

### Step 1: Clone the Repository
Clone the project repository from GitHub and navigate to the project directory:
```bash
git clone https://github.com/yourusername/CityBuilderSimulation.git
cd CityBuilderSimulation

### Step 2: Install Dependencies for City Builder Simulation

## Overview
To run the **City Builder Simulation**, you need to set up the environment by installing the required dependencies, particularly the **SFML (Simple and Fast Multimedia Library)**, which provides essential graphics functionality for the project.

## Prerequisites
Ensure you have:
- A **C++11 or higher compiler**.
- **SFML Library** for graphics, window handling, and more.

## Installation Instructions for SFML

### Ubuntu/Debian
If you are using Ubuntu or Debian, you can install SFML directly from the package manager:
```bash
sudo apt-get update
sudo apt-get install libsfml-dev

# Step 3: Compile the Program for City Builder Simulation

## Overview
Once dependencies like SFML are installed, you’re ready to compile the **City Builder Simulation** project. This step provides instructions for compiling the project using either `g++` directly or **CMake** for a more structured build process.

## Compilation Options

### Option A: Direct Compilation with g++
If you prefer a straightforward approach, you can compile the project directly using `g++`. This command will compile all `.cpp` files in the `src` directory and output an executable named `CityBuilderSimulation`.

1. Run the following command from the project’s root directory:
   ```bash
   g++ -std=c++11 -Iinclude src/*.cpp -o CityBuilderSimulation -lsfml-graphics -lsfml-window -lsfml-system

First, create a build/ directory in the project root and navigate into it:


Copy code
mkdir build
cd build
Run CMake to configure the project and generate makefiles:


Copy code
cmake ..
Once configured, compile the project with:


Copy code
make
After compilation, an executable named CityBuilderSimulation will be created in the build/ directory.

### Step 5 : 
# Step 5: Ensure Data Files Are Accessible for City Builder Simulation

## Overview
To run the **City Builder Simulation** properly, all necessary data files, such as textures and configuration files, must be accessible to the program. These files should be located in the `Data/media` folder.

## Setting Up Data Files

1. **Check the `Data/media` Directory**:
   - Ensure that the `Data/media` directory contains all required assets, including textures, fonts, and any configuration files.
   - These files are typically necessary for rendering graphics, managing resources, and defining simulation parameters.

2. **File Structure**:
   - The project expects a specific folder structure for data files. Below is an example structure that should be in place for the simulation to work:
     ```
     CityBuilderSimulation/
     ├── Data/
     │   └── media/
     │       ├── background.png
     │       ├── commercial.png
     │       ├── firestation.png
     │       ├── font.ttf
     │       ├── forest.png
     │       ├── grass.png
     │       ├── hospitals.png
     │       ├── industrial.png
     │       ├── landmarks.png
     │       ├── powerplants.png
     │       ├── residential.png
     │       ├── road.png
     │       ├── sewageplants.png
     │       ├── wastemanagement.png
     │       ├── water.png
     │       └── waterplants.png
     ```

3. **Configuring File Paths (if needed)**:
   - If you modify the folder structure, make sure to update any file paths in the source code to reflect the new structure.
   - Paths are typically set in the source code under `src` or `include` directories, especially where resources are loaded.

4. **Verify Data Accessibility**:
   - Before running the simulation, verify that all data files are present in the `Data/media` folder.
   - Missing files may cause runtime errors or result in blank or incorrectly rendered elements within the simulation.

## Running the Program with Data
After confirming that the data files are correctly set up, you can proceed to run the program as outlined in the previous steps. The simulation will automatically access the `Data/media` folder for required assets during runtime.

---

Ensuring proper data file access is critical for a smooth experience with the City Builder Simulation. Let me know if you have any questions!

## License

This project, **City Builder Simulation**, is the property of the University of Pretoria and was developed by its students as part of the COS214 course curriculum. 

### Usage Restrictions
- This code and its associated assets are intended for educational purposes only and may not be used for commercial purposes without explicit permission from the University of Pretoria.
- Redistribution, modification, and use of this project in academic or personal research are permitted, provided appropriate credit is given to the University of Pretoria and the contributing students.

For questions regarding permissions and usage, please contact the University of Pretoria’s Department of Computer Science.
