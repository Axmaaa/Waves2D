void Frame();
void Initialization();
void Reshape();
void DrawScreen();
void SetCircleWaveCoords(double x, double y);
void SetCircleWaveSpeeds(double v);
void BorderCollisions();
void ChangeCoords();
void TimeShift();
void PrintVector(struct Vector2D a);


// Frame
void Frame()
{
    for (unsigned int i = 0; i < TIME_SHIFTS_IN_FRAME; i++)
        TimeShift();
    FrameIndex++;
}


void Initialization()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-0.01, 1.01, -0.01, 1.01, -1.0, 1.0);
}


void Reshape()
{
    Frame();
    glutPostRedisplay();
}


void DrawScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_POINTS);

    for(size_t i = 0; i < N_POINTS; i++)
    {
        glVertex3f((double)(points[i].coord.x), (double)(points[i].coord.y), 0.0);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex3f((double)(BORDER_X_MIN), (double)(BORDER_Y_MIN), 0.0);
    glVertex3f((double)(BORDER_X_MAX), (double)(BORDER_Y_MIN), 0.0);

    glVertex3f((double)(BORDER_X_MAX), (double)(BORDER_Y_MIN), 0.0);
    glVertex3f((double)(BORDER_X_MAX), (double)(BORDER_Y_MAX), 0.0);

    glVertex3f((double)(BORDER_X_MAX), (double)(BORDER_Y_MAX), 0.0);
    glVertex3f((double)(BORDER_X_MIN), (double)(BORDER_Y_MAX), 0.0);

    glVertex3f((double)(BORDER_X_MIN), (double)(BORDER_Y_MAX), 0.0);
    glVertex3f((double)(BORDER_X_MIN), (double)(BORDER_Y_MIN), 0.0);

    glEnd();

    glFlush();
}


// Set coords of atoms in one point
void SetCircleWaveCoords(double x, double y)
{
    for (unsigned int i = 0; i < N_POINTS; i++)
    {
        points[i].coord.x = x;
        points[i].coord.y = y;
    }
}


// Set speeds of atoms round from center
void SetCircleWaveSpeeds(double v)
{
    for (unsigned int i = 0; i < N_POINTS; i++)
    {
        points[i].speed.x = v * cos(2 * M_PI * i / N_POINTS);
        points[i].speed.y = v * sin(2 * M_PI * i / N_POINTS);
    }
}


// Collisions with borders and changing speeds
void BorderCollisions()
{
    for (unsigned int i = 0; i < N_POINTS; i++)
    {
        if (points[i].coord.x <= BORDER_X_MIN)
        {
            points[i].speed.x *= -1;
            points[i].coord.x = BORDER_X_MIN;
        }
        if (points[i].coord.x >= BORDER_X_MAX)
        {
            points[i].speed.x *= -1;
            points[i].coord.x = BORDER_X_MAX;
        }

        if (points[i].coord.y <= BORDER_Y_MIN)
        {
            points[i].speed.y *= -1;
            points[i].coord.y = BORDER_Y_MIN;
        }
        if (points[i].coord.y >= BORDER_Y_MAX)
        {
            points[i].speed.y *= -1;
            points[i].coord.y = BORDER_Y_MAX;
        }
    }
}


// Move atoms
void ChangeCoords()
{
    for (unsigned int i = 0; i < N_POINTS; i++)
    {
        points[i].coord.x += points[i].speed.x * TIMEDELTA;
        points[i].coord.y += points[i].speed.y * TIMEDELTA;
    }
}


// Time shift
void TimeShift()
{
    BorderCollisions();
    ChangeCoords();
    TimeIndex++;
}


// Print vecrot coords
void PrintVector(struct Vector2D a)
{
    int m = 3;
    printf("(%.*f, %.*f)\n", m, a.x, m, a.y);
}
