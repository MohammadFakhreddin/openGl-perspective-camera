
#define GL_SILENCE_DEPRECATION

#include <SFML/Window/Window.hpp>
#include <SFML/OpenGL.hpp>
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Constants.h"

void update(){

}

void render(){
    glClear( GL_COLOR_BUFFER_BIT);
    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(100.0, 200.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(200.0, 100.0, 0.0);
    glVertex3f(200.0, 200.0, 0.0);
    glEnd();
    glFlush();
}

void mainLoop() {
    update();
    render();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    Constants::System::RealScreenWidth = sf::VideoMode::getDesktopMode().width;
    Constants::System::RealScreenHeight = sf::VideoMode::getDesktopMode().height;

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
#ifdef __DESKTOP__
    glutInitWindowSize(Constants::Window::screenWidth,Constants::Window::screenHeight);
    glutInitWindowPosition(
            (int)(Constants::System::RealScreenWidth/2 - Constants::Window::screenWidth/2),
            (int)(Constants::System::RealScreenHeight/2 - Constants::Window::screenHeight/2));
#endif
    glutCreateWindow(Constants::Window::appName);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glViewport(0,0,Constants::Window::screenWidth,Constants::Window::screenHeight);
    glOrtho(0.0, Constants::Window::screenWidth, 0.0, Constants::Window::screenHeight, -1.0, 1.0);
    glutDisplayFunc(mainLoop);
    glutMainLoop();
    return 0;
}