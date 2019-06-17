#include <iostream>
#include <cmath>
#include <time.h>
#include <GL/glut.h>
#include <GL/gl.h>

#include "waves_constants.hpp"
#include "waves_structs.hpp"

struct Point points[N_POINTS] = {};

#include "waves_func.hpp"


int main(int argc, char ** argv)
{
    srand(time(0));
    SetCircleWaveCoords(0.5, 0.5);
    SetCircleWaveSpeeds(MAX_SPEED * 20);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(1210, 1300);
    glutCreateWindow("Window");
    Initialization();
    glutDisplayFunc(DrawScreen);
    glutIdleFunc(Reshape);
    glutMainLoop();
    return 0;
}
