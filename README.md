# COS214 Project: City Builder

## Project Overview
The **City Builder Simulation** is a C++ project designed to model the complexities of urban development and management. Players can construct and manage different aspects of a virtual city, including infrastructure, resources, transportation, and citizen satisfaction. The simulation applies various design patterns to ensure scalability, maintainability, and flexibility, making it a robust educational tool for software engineering concepts.

## Key Features

* **Building Management**: Construct residential, commercial, industrial, and landmark buildings with unique attributes
* **Resource Management**: Manage utilities like power, water, sewage, and waste disposal for efficient city operations
* **Transportation System**: Build roads and manage public transit to support city connectivity
* **Citizen Satisfaction**: Monitor and respond to citizen needs and satisfaction affected by policies and services
* **Government Policies**: Implement taxation and budget management to fund city development

## Design Patterns Used
The project integrates multiple design patterns, such as Singleton, Observer, Factory, Mediator, State, Strategy, Prototype, Proxy, Memento, Template and Command, to support a scalable and modular architecture.

## Prerequisites

* **Compiler**: A C++11 or higher compiler is required
* **SFML Library**: The project uses the SFML library for graphics. Install SFML by following the instructions at [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)

## Directory Structure

* **src/**: Contains all source code files (`.cpp` files)
* **include/**: Contains all header files (`.h` files)
* **docs/**: Documentation generated with Doxygen
* **Data/**: Contains the `media` folder with assets like textures and configuration files
* **build/**: Directory for compiled binary files (if using CMake)
* **README.md**: Project overview, setup instructions, and usage guidelines

## Setup and Installation Guide

### Step 1: Clone the Repository

```bash
git clone https://github.com/yourusername/CityBuilderSimulation.git
cd CityBuilderSimulation
```

### Step 2: Install Dependencies

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install libsfml-dev
```

### Step 3: Compile the Program

#### Option A: Direct Compilation with g++
```bash
g++ -std=c++11 -Iinclude src/*.cpp -o CityBuilderSimulation -lsfml-graphics -lsfml-window -lsfml-system
```

#### Option B: Using CMake
```bash
mkdir build
cd build
cmake ..
make
```

### Step 4: Data Files Setup

Ensure the following file structure is maintained:

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

## License

This project, **City Builder Simulation**, is the property of the University of Pretoria and was developed by its students as part of the COS214 course curriculum.

### Usage Restrictions

* This code and its associated assets are intended for educational purposes only and may not be used for commercial purposes without explicit permission from the University of Pretoria
* Redistribution, modification, and use of this project in academic or personal research are permitted, provided appropriate credit is given to the University of Pretoria and the contributing students

For questions regarding permissions and usage, please contact the University of Pretoria's Department of Computer Science.