// OpenGL
#include <stdlib.h>
#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#define pi 3.142857


float convertColorToFloat(float number) {
	float numberReturn = number / 255;
	return numberReturn;
}

void keyPressed(unsigned char keyClick, int x, int y) {
	if (keyClick == 'p') {
		printf("It worked\n");
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
	float x, x2, y, y2, i, j; 
	
	// iterate y up to 2*pi, i.e., 360 degree 
	// with small increment in angle as
	/*
	for ( i = 0; i < (2 * pi); i += 0.001) 
	{ 
		// 200 is size of object 
		// circle is defined as x = r*cos(i) and y=r*sin(i) 
		x = 200 * cos(i); 
		y = 200 * sin(i); 
		
		// Draws the dot/point which can be seen
		glVertex2i(x, y); 
	} */
	for (i = 0; i < 5; i += 0.01) {
		/* for (j = 0; j < 5; j+= 0.001) {
			x2 = 200 * j;
			y2 = 200 * j;
			glVertex2i(x2, y2);
		} */
		x = 10 * i;
		y = 10 * i;
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
	glutCreateWindow("Harpocrates");
	createBackground();

	glutKeyboardFunc(keyPressed);
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

