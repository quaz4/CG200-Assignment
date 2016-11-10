# CG200-Assignment
CG200 assignment, theme is under the sea

# Compile/running
To make the program, run make in the CG200-Assignment folder.
	eg. "make"

To run the program, use the command "./a.out"

# Files
main.cpp:
	Contains all of the logic as well as the main function.
	Controls animation, camera, movement remembering the model locations.
main.hpp:
	Forward declarations for main.cpp and structs for main.cpp

seaweed.cpp:
	Contains functions for modeling the seaweed in high and low detail.
	Low detail implementation has issues so wasn't enabled in my final program.
seaweed.hpp:
	Forward declarations for seaweed.cpp

fish.cpp:
	Contains functions for modeling the seaweed in high and low detail.
fish.hpp:
	Forward declarations for fish.cpp

texture.cpp:
	Contians functions for loading texures clamped and repeated.
texture.hpp:
	Contains forward declarations for texture.cpp