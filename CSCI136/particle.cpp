/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Making your own class Particle .,Lab9F

This program will declare a new class called Particle, which stores position and velocity of the particle. It will have five functions: deleteParticle (must delete all dynamically allocated memory that is created by createParticle) function.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

class Particle{
public:
   Coord3D points;
   double px;
   double py;
   double pz;

}
// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz){
   Particle *p = new Particle();
   p->points.x = x;
   p->points.y = y;
   p->points.z = z;
   p->px = vx;
   p->py = vy;
   p->pz = vz;
   return p;
}
// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
   p->px = vx;
   p->py = vy;
   p->pz = vz;
}
// get its current position
Coord3D getPosition(Particle *p){
   return p->points;

}
// update particle's position after elapsed time dt
void move(Particle *p, double dt){
   p->points.x += ( p->px * dt);
   //for y
   p->points.y += (p->px * dt);
   //for z
   p->points.z += (p->px * dt);
}
// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
   delete p;
}

int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: " << getPosition(p).x << ", "<< getPosition(p).y << ", "<< getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}
