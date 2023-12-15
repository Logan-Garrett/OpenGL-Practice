// OpenGL
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 


float convertColorToFloat(float number) {
	float numberReturn = number / 255;
	return numberReturn;
}

void myInit (void) 
{
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

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POINTS);
	float x, y, i; 
	
	// iterate y up to 2*pi, i.e., 360 degree 
	// with small increment in angle as 
	// glVertex2i just draws a point on specified co-ordinate 
	for ( i = 0; i < (2 * pi); i += 0.001) 
	{ 
		// let 200 is radius of circle and as, 
		// circle is defined as x=r*cos(i) and y=r*sin(i) 
		x = 200 * cos(i); 
		y = 200 * sin(i); 
		
		glVertex2i(x, y); 
	}
	// Draw circle function above?

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
	glutCreateWindow("Circle Drawing"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

