// OpenGL
#include <stdlib.h>
#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#include <unistd.h>
// #include <windows.h>
#define pi 3.142857


float convertColorToFloat(float number) {
	float numberReturn = number / 255;
	return numberReturn;
}

// Function to draw the triangle
void drawTriangle() {
    	glBegin(GL_TRIANGLES);
    	glColor3f(1.0, 0.0, 0.0); // Set color to red
   	
	// Increase the coordinates to make the triangle bigger
    	glVertex2f(0.0, 100.0);   // Top vertex
    	glVertex2f(-100.0, -100.0); // Bottom left vertex
    	glVertex2f(100.0, -100.0);  // Bottom right vertex

	glEnd();
    	glFlush(); // Ensure all drawing commands are executed
}

void keyPressed(unsigned char keyClick, int x, int y) {
	// 13 is ascii for enter
	// 27 is ascii for esc
	if (keyClick == 27) {
		printf("ESC\n");
		exit(0);
	} else if (keyClick == 13) {
		printf("ENTER\n");
        	drawTriangle(); // Draw the triangle
	}
}

void createBackground(void) {
	// Color for UI Background 
	float red = convertColorToFloat(149);
	float green = convertColorToFloat(165);
	float blue = convertColorToFloat(166);
	float alpha = 0.0;

	glClearColor(red, green, blue, alpha); // Set background color RGB with fourth being alpha
	
	glColor3f(0.0, 0.0, 1.0); // R(0.0.), G(0.0), B(1.0) ring color in this instance
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420); 
} 

void display(void) { 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POINTS);

	glEnd(); 
	glFlush(); 
} 

void displayCircle(void) {
	glClear(GL_COLOR_BUFFER_BIT); 
        glBegin(GL_POINTS);

	float x, x2, y, y2, i, j; 
        
        // iterate y up to 2*pi, i.e., 360 degree 
        // with small increment in angle as
        
        for ( i = 0; i < (2 * pi); i += 0.001) 
        { 
                // 200 is size of object 
                // circle is defined as x = r*cos(i) and y=r*sin(i) 
                x = 200 * cos(i); 
                y = 200 * sin(i); 
                
                // Draws the dot/point which can be seen
                glVertex2i(x, y); 
        } 
	glEnd(); 
        glFlush(); 
}

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("Apollo");
	createBackground();

	glutKeyboardFunc(keyPressed);
	
	glutDisplayFunc(display); 
	
	// Loads everything that has been called.
	// Avoid calling many times supposedly.
	glutMainLoop();
} 

