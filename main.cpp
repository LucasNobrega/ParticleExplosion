#include <time.h>
#include <iostream>
#include <sstream>
#include "Particle.h"
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace particles;

int main(int argc, char** argv) {
    int NUMBER_OF_PARTICLES;
    double CURL;
    int redCoef, greenCoef, blueCoef;

    // Command line arguments
    if (argc == 1) {
        NUMBER_OF_PARTICLES = 1000;
        CURL = 3;
        redCoef = 5;
        greenCoef = 12;
        blueCoef = 10;
    } else {
        stringstream ss1;
        ss1 << argv[1];
        ss1 >> NUMBER_OF_PARTICLES;
        stringstream ss2;
        ss2 << argv[2];
        ss2 >> CURL;
        stringstream ss3;
        ss3 << argv[3];
        ss3 >> redCoef;
        stringstream ss4;
        ss4 << argv[4];
        ss4 >> greenCoef;
        stringstream ss5;
        ss5 << argv[5];
        ss5 >> blueCoef;
    }

    srand(time(NULL));

    // Creating window
    Screen screen;
    if (screen.init() == false) {
        cout << "Error initialising SDL." << endl;
    }

    Swarm swarm1(NUMBER_OF_PARTICLES, CURL);

    bool quit = false;

    int max = 0;
    // Game loop
    while (true) {
        int elapsed = SDL_GetTicks();

        //Update particles
        swarm1.update(elapsed);

        // Change color
        unsigned char red = (1 + sin(elapsed * 0.0001 * redCoef)) * 128;
        unsigned char green = (1 + sin(elapsed * 0.0001 * greenCoef)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0001 * blueCoef)) * 128;

        // Draw particles
        for (std::vector<Particle>::iterator it = swarm1.getParticleVector().begin(); it != swarm1.getParticleVector().end(); it++) {
            int x = 0.5 * Screen::SCREEN_WIDTH * (it->getX() + 1);
            int y = (0.5 * Screen::SCREEN_HEIGHT * it->getY()) + Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(x, y, red, green, blue);
        }

        // Blur image
        screen.boxBlur();

        // Draw the screen
        screen.update();

        // Check for messages/events
        if (screen.processEvent() == false) {
            break;
        }
    }

    screen.close();

    return 0;
}