#include <iostream>
#include <GL/glut.h>

using namespace std;

void drawCircle();
void inputData();
void CoordinateAxes();
void plot(float x, float y);
void drawSymmetryPoints();

float x, y;
float Xc, Yc;
float radius;

int main(int argc, char** argv)
{
    inputData();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500,500);

    glutCreateWindow("Midpoint Algorithm Circle");
    glutDisplayFunc(drawCircle);

    glutMainLoop();
    return 0;
}

void drawCircle()
{
    CoordinateAxes();
    glColor3ub(255 ,255,255);
    glBegin(GL_POINTS);

        float P = (5/4) - radius;
        x = 0;
        y = radius;

        while (x <= y)
        {
            if (P < 0)
            {

                x++;
                P += 2*x + 1;

            }
            else
            {

                x++;
                y--;
                P += 2*x - 2*y + 1;

            }
            drawSymmetryPoints();
        }

    glEnd();
    glFlush();
}

void inputData()
{
    cout << "Enter center of circle: ";
    cin >> Xc >> Yc;

    cout << "Enter radius of circle: ";
    cin >> radius ;
}

void CoordinateAxes()
{
    glColor3ub(0,0,255);
    glBegin(GL_LINES);
        glVertex2f(0,1);
        glVertex2f(0,-1);
        glVertex2f(-1,0);
        glVertex2f(1,0);
    glEnd();
}

void plot(float x, float y)
{
    glVertex2f(x/500, y/500);
    //cout << "(" << x << "," << y << ")";
}

void drawSymmetryPoints()
{
    plot(Xc + x, Yc + y);
    plot(Xc - x, Yc + y);
    plot(Xc + x, Yc - y);
    plot(Xc - x, Yc - y);

    plot(Yc + y, Xc + x);
    plot(Yc - y, Xc + x);
    plot(Yc + y, Xc - x);
    plot(Yc - y, Xc - x);
}




