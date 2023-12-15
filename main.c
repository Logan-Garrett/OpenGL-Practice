// OpenGL
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#include <unistd.h>
// #include <windows.h>
#define pi 3.142857

struct Letter {
	struct Letter *next;
	struct Letter *prev;
	char character;
};

struct List {
	struct Letter *head;
	struct Letter *tail;
	int length;
};

struct List *list;

struct Letter *createLetter(char character) {
	struct Letter *letter = malloc(sizeof(struct Letter));
	if (letter == NULL) {
		printf("Error malloc for letter\n");
		exit(-1);
	}

	letter->character = character;
	letter->next = NULL;
	letter->prev = NULL;
	return letter;
}

struct List *createList() {
	struct List *list = malloc(sizeof(struct List));
	if (list == NULL) {
		printf("Error malloc for list\n");
		exit(-1);
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

void insertNextLetter(struct Letter *letter, struct List *list) {
	if (list->head == NULL && list->tail == NULL) {
                list->head = letter;
                list->tail = letter;
        } else {
                list->tail->next = letter; 
                letter->prev = list->tail;
                list->tail = letter; 
        }       
        list->length++;
}

void printLetterList(struct List *list) {
        struct Letter *ptr = list->head;
        
        while (ptr != NULL) {
                printf("(Letter: %c)\n", ptr->character);  
                ptr = ptr->next;
        }       
        printf("\n");
}


float convertColorToFloat(float number) {
	float numberReturn = number / 255;
	return numberReturn;
}

void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
	string++;
    }
}

void displayKeyPress(int ascii) {

	glClear(GL_COLOR_BUFFER_BIT);

    	glColor3f(1.0, 0.0, 0.0); // Set text color to red

    	// Example text to be displayed
	char conversion = (char)ascii;
	char text[2];  // Create an array to hold the character and null terminator
	text[0] = conversion; // Assign the converted character to the first element of the array
	text[1] = '\0'; // Null-terminate the string

    	// Set the position and font for the text
    	renderBitmapString(-0.5, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, text);

    	glFlush(); 
}

void displayWord(struct List *list) {
	struct Letter *ptr = list->head;
	char word[1000] = "";
	int i = 0;
	while (ptr != NULL) {
		char conversion[2] = {ptr->character, '\0'};
		strcat(word, conversion);
		// printf("Ptr->character: %c\n", ptr->character);
		ptr = ptr->next;
		i++;
	}

	printf("word: %s\n", word);
	glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);

	renderBitmapString(-0.5, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, word);
        glFlush(); 
}

void addKeyPress(int ascii, struct Letter *letter) {
        char conversion = (char)ascii;
	letter = createLetter(conversion);
	insertNextLetter(letter, list);
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
	// struct List *list = createList();
	struct Letter *word = NULL;
	// 13 is ascii for enter
	// 27 is ascii for esc
	if (keyClick == 27) {
		printf("ESC\n");
		exit(0);
	} else if (keyClick == 13) {
		printf("ENTER\n");
        	// drawTriangle(); // Draw the triangle
		displayWord(list);
	} else {
		addKeyPress(keyClick, word);
		// printLetterList(list); // debugging
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

	float x, y, i; 
        
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

	list = createList();

	glutKeyboardFunc(keyPressed);
	
	glutDisplayFunc(display); 
	
	// Loads everything that has been called.
	// Avoid calling many times supposedly.
	glutMainLoop();
} 

