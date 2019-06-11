# Simple Path Finder for Irregular, Directed Maze

This program calculates the number of ways there are to go from the starting to the ending point on a maze that user inputs. The paths must visit the arrows exactly n times (user input), and no intersection can be visited twice. 

## How It Works

Step 1: User draws a maze of any shape on the predefined grid, including starting and ending points. (Starting point has to be a point with right and down arrows).

Step 2: User inputs the number of arrows the path(s) can travel through.

Step 3: The program outputs the number of possible ways there are of paths that goes from starting to ending and visiting exactly n arrows.

## Features

- Users can choose to input their own maze in the console or use a predefined maze stored in `main.cpp`.
- The program automatically detects the correct starting location, without needing any user input.
- Users can choose the terminating location, and the program detects if the input is logical (possible) before making any calculation.
- The program pretty prints the inputted maze, with arrows indicating path directions and starting and ending locations.
- Users can choose to enter the path length manually or have the program calculate all possibilities automatically (up to 100 units long).

## Note

This program is originally created for Judy Chiang for her math research.