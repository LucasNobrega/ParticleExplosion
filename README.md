# ParticleExplosion
Graphical C++ 11 application using SDL

## The application
This is a simple graphical application that simulates a particle explosion. Each particle has a different speed and curl. The colors of the particle are all the same and changes over time following a sinusoidal function on each component of the RGB spectrum.

## Parameters
The application let's you change a series of parameters. They are:
* Number of particles;
* Curl of each particle;
* Red Coefficient (How fast the red component of the RGB color spectrum changes);
* Green Coefficient (How fast the green component of the RGB color spectrum changes); and
* Blue Coefficient (How fast the blue component of the RGB color spectrum changes).

## Launching
Using the terminal you can launch application on your own PC. TO do this, you will need C++11. You can compile all the files using the MakeFile available in this repository by just typing: `make all`. This will create an executable called main, which can then be run by typing `./main`.
