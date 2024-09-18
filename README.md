# CX-Circus-Tower
Circus Tower program for calculating the maximum number of people that can be stacked based on height and weight constraints set for CX Interview

## Table of Contents

- [About](#about)
- [Features](#features)
- [How It Works](#how-it-works)
- [Getting Started](#getting-started)
  - [What You Need](#what-you-need)
  - [Setting It Up](#setting-it-up)
- [Using the Program](#using-the-program)
  - [Running the Application](#running-the-application)
  - [Running the Tests](#running-the-tests)
- [Project Layout](#project-layout)
- [License](#license)
- [Shoutouts](#shoutouts)

## About

Hello! Welcome to the **Circus Tower** project. This is a C++ application designed to determine the maximum number of people that can be stacked in a tower based on their height and weight. Each person in the tower must be shorter and lighter than the person below them.

## Features

- **Calculate Maximum Height:** Efficiently calculates the tallest tower that can be built using the provided height and weight data.
- **Dynamic Programming:** Utilizes a dynamic programming approach to find the optimal stacking configuration.
- **Error Handling:** Provides feedback if the input data is invalid or if no valid tower can be built.
- **Thorough Testing:** Includes unit tests using Google Test to ensure the correctness of the implementation.
- **Modular Design:** Organized into several classes for maintainability and clarity.

## How It Works

Here's a quick overview of the classes and `main.cpp`:

1. **Person:** Represents an individual with height and weight attributes.
2. **FileDataParser:** Loads and parses height and weight data from a specified file.
3. **TowerBuilder:** Contains the logic to calculate the maximum height of the tower based on the sorted list of people.
4. **Main Program:** Takes input from the command line, initializes the necessary components, and outputs the result.

## Getting Started

### What You Need

1. **C++ Compiler**: Supports C++17 or later (e.g., `g++`, `clang++`).
2. **CMake**:  Version 3.14 or newer.
3. **Google Test**: For running the unit tests.
4. **Git:** Useful for version control (optional but recommended).

### Setting It Up

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/ejh38/CX-Circus-Tower.git
   cd CX-Circus-Tower
   ```

2. **Create a Build Directory**:
   ```bash
   mkdir build
   cd build
   ```

3. **Configure with CMake**:
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Release ..
   ```

4. **Build the Project**:
   ```bash
   cmake --build . --config Release
   ```
   Your executable (`circus_tower.exe` on Windows or `circus_tower` on Unix-based systems) will be in the `build/bin/Release/` folder.

5. **NOTE: Executables will be included in the repo in case you do not want to build them yourself:**
   Executables will be in the `build/bin/Release/` folder.

## Using the Program

### Running the Application

You'll need two things to run the program:

1. **Data File:** A text file with height and weight data for the people. An example file is included in the `data` folder. If you would like to create your own please use the same format.
2. **Command Line Argument:** The path to the data file.

**How to Run the Main Program:**
```bash
./circus_tower(.exe for windows) <dataFilePath>
```

**Example:**

If you have a person list called `person_data.txt` located in the data folder:
```bash
./circus_tower ...\..\..\data\person_data.txt
```
**What You'll See using the demo data:**
Tower Configuration (from top to bottom):
Height: 160 cm, Weight: 50 kg
Height: 165 cm, Weight: 55 kg
Height: 170 cm, Weight: 65 kg
Height: 175 cm, Weight: 70 kg
Height: 180 cm, Weight: 75 kg
Height: 190 cm, Weight: 80 kg
Maximum number of people in the tower: 6


**How to Run test program:**
```bash
./circus_tower_tests(.exe for windows)
```