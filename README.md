
# Beam Reaction Calculator


## Live Calculator

Check this super awesomely cool Simply Supported Reaction Calculator Website

[Launch Beam Reaction Calculator](https://yushuahussain8-lgtm.github.io/beam-reaction-calculator/)


A C-based structural engineering calculator that determines support reactions for a simply supported beam carrying a single downward point load.

## Features
- Calculates vertical reactions at both supports.
- Accepts beam span, point load and load position.
- Uses static equilibrium equations.
- Checks inputs to prevent invalid values.

## Engineering Principles

The calculator uses two equilibrium equations:

- Sum of vertical forces = 0
- Sum of moments = 0

For a point load P at distance a from the left support on a beam of length L:

- Left reaction: RA = P(L - a)/L
- Right reaction: RB = Pa/L

## Technologies
- C programming language
- Visual Studio Code
- GCC compiler

## How to Run

1. Download the project.
2. Open the project folder in VS Code.
3. Compile the source code using GCC:

    gcc main.c -o beam

4. Run the compiled program:

    ./beam

On Windows PowerShell, use `.\beam.exe`.

## Example

Beam span: 6 m

Point load: 10 kN

Distance from left support: 2 m

Expected results:

- Left reaction: 6.67 kN
- Right reaction: 3.33 kN
