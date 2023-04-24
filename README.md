# so_long

The so_long project is a simple 2D game where the player must navigate a character through a maze, collecting items and avoiding obstacles along the way. In this project, you will write a program that can load and display a map, and allow the user to move a character through that map.

# Installation:

To use this program in your projects, you must first compile it by running the following command:

`make`

This will compile the program into an executable file called so_long. You can then run the program by entering the following command:

`./so_long <map_file>`

# Usage:

The program takes one argument, which is the path to the map file that you want to load. The map file must have a .ber extension and must be formatted in a specific way. The map file should have the following structure:

`1111111
1000001
1011101
1000001
1011101
1000201
1111111`


Where 1 represents a wall, 0 represents an empty space, and 2 represents the character's starting position.

To move the character through the map, you can use the arrow keys on your keyboard. The goal is to collect all of the items in the map and reach the exit without colliding with any walls or enemies.

# Functionality:
The program uses the MiniLibX library to load and display the map. It also uses images and sprites to represent the character and the items in the map.

The program handles edge cases, such as if the map file is not formatted correctly or if the user tries to move the character outside of the map boundaries.

# Conclusion:

The so_long project is a fun and engaging project that will help you to gain a better understanding of how to work with graphics in C and how to create simple games. By completing this project, you will gain a deeper understanding of how to use the MiniLibX library, how to load and display images and sprites, and how to handle user input in your C programs.
