#include "utils/screen/ScreenSize.h"
#include "OpenGlHeaders.h"
#include "Constants.h"
#include <memory>
#include "application/Application.h"
#include <iostream>

std::unique_ptr<Application> application;

void update(){
	application->update();
}

void render(){
    glClear( GL_COLOR_BUFFER_BIT);
	application->render();
    glFlush();
}

void mainLoop() {
    update();
    render();
}

void timer(int value)
{
	glutTimerFunc(16, timer, 0);
	glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
#ifdef __DESKTOP__
	unsigned int realScreenHeight = 0;
	unsigned int realScreenWidth = 0;
    std::cout<<"Bootttttt"<<std::endl;
	ScreenSize::getScreenResolution(
		realScreenWidth,
		realScreenHeight
	);
    std::cout<<"ScreenSize width:"<<realScreenWidth<<" height:"<<realScreenHeight<<std::endl;
    glutInitWindowSize(Constants::Window::screenWidth,Constants::Window::screenHeight);
    glutInitWindowPosition(
            (int)(realScreenWidth/2 - Constants::Window::screenWidth/2),
            (int)(realScreenHeight/2 - Constants::Window::screenHeight/2));
#endif
    glutCreateWindow(Constants::Window::appName);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glViewport(0,0,Constants::Window::screenWidth,Constants::Window::screenHeight);
    glOrtho(0.0, Constants::Window::screenWidth, 0.0, Constants::Window::screenHeight, -1.0, 1.0);
	application = std::make_unique<Application>();
	glutTimerFunc(0, timer, 0);
	glutDisplayFunc(mainLoop);
    glutMainLoop();
    return 0;
}