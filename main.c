#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SIMULATIONS 10000000  // Number of simulation iterations

// Function to generate a random number between 0 and 1
double random() {
    return (double)rand() / RAND_MAX;
}

int main() {
    int count = 0;  // Counter for darts landing at least one unit distance apart

    // Perform the Monte Carlo simulation
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        // Generate random angle for the first dart in the range [0, 2π]
        double angle1 = 2.0 * M_PI * random();

        // Generate random angle for the second dart in the range [0, 2π]
        double angle2 = 2.0 * M_PI * random();

        // Generate random radius for the first dart in the range [0, 1]
        double radius1 = sqrt(random());

        // Generate random radius for the second dart in the range [0, 1]
        double radius2 = sqrt(random());

        // Calculate the coordinates for the first and second darts
        double x1 = radius1 * cos(angle1);
        double y1 = radius1 * sin(angle1);
        double x2 = radius2 * cos(angle2);
        double y2 = radius2 * sin(angle2);

        // Check if the distance between the two darts is at least 1 unit
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if (distance >= 1.0) {
            count++;
        }
    }

    // Calculate the estimated probability
    double probability = (double)count / NUM_SIMULATIONS;

    printf("Estimated Probability: %lf\n", probability);
    getch(); 
    return 0;
}
