# CSE261_Fall2025_Topic12_HeatEquation
# Numerical analysis of 1D Heat Equation

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A numerical simulation of the 1D Heat Equation comparing **FTCS (Forward Time, Center Space)** and **CN (Crank-Nicolson)** methods.

## Key Features
- **FTCS Implementation:** A simple, explicit approach for the fast computation within stability limits (r <= 5).
- **Crank-Nicolson Implementation:** A robust, implicit way to solving heat equation using **Thomas Algorithm**.
- **Output Analysis:** Built in capability to compare output at specific time.

***Note on Design**:
This simulation uses Static Configuration. Parameters such as nx(grid width), nt(time steps), alpha(thermal diffusivity), and values at certain points are defined within the source code to optimize performance. All the outputs are obtained by statically changing some parameters.*

## Configuration & Usage
The project uses Static Configuration for mathematical consistency. To modify the simulation parameters:

1. Locate Parameters: Open crank_nicolson.c or ftcs.c
2. Edit Variabels: Modify values such as nx, nt, or t_target, depending on the desired output.
3. Compile:

```Bash
gcc -o crank_nicolson crank_nicolson.c
gcc -o ftcs ftcs.c
```

4. Execute: Run `./crank_nicolson` or `./ftcs` to generate .dat output files.
5. Plot: The output format is **Space-Delimited Data** or **Gnuplot-Compatible Raw Data**. This format will work with gnuplot but is not compatible for csv-format plotting.

## Final Observations:
1. **Stability**: The FTCS method failed at time step 0.5 where r is 1.2 (violating the stablity condition of r; r <= 0.5>) producing stripe like patters. Crank-Nicolson method remained stable and physically accurate at the same time step and r.

2. **Accuracy**: Error analysis at 0.1 shows that numerical error is concentrated the the regions of the highest thermal gradient (the edges of the initial block).

Since, there is no r condition in Crank-Nicolson Method, time steps can be taken larger (though it might make huge errors but it will save computation time).


## Build With
- C Language
- Gnuplot
- Thomas Algorithm
