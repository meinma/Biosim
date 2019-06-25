# Biosim
This is the implementation of my lab course of my bachelor of the university in Bayreuth.
The goal was to implement an interactive biosimulation in C++. 

# Description
This means the user should be able to create a working environment with several creatures just by clicking (f.g fishes, tigers, cows, trees). The user can select among all creatures from a list mene. Afterwards the user can place the creatures on a virtual, randomly created map. There are buttons to start and stop the simulation. While the simulation is running the animals are moving according to its rules of simple AI. For example plants are spreading if there's enough space in the environemnt around them. The animals are going around, recover afterwards or look for food if they are hungry. The limited lifespan forces them to look for a partner to reproduce themselves.

# Single Tasks
- Loading textfiles with attributes of creatures
- Reading of image files for creatures and environment graphics
- Creation of a GUI for application
- Creation and representation of a random map of the environment with Perlin Noise
- Implementation of placing and representation of creatures
- Implementation of A Star Algorithm for shortest path problem
- Implementation of AI of creatures by usage of state machine
- Creation of a testplan for the application


# Built with
Visual Studio
Qt