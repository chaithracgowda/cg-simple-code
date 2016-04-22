#include<GL/glut.h>
#include<stdio.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2f(10.0,10.0);
		glVertex2f(150.0,80.0);
		glVertex2f(100.0,20.0);
		glVertex2f(200.0,100.0);
	glEnd();
	glFlush();
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	gluOrtho2D(0.0,550.0,0.0,550.0);
}
void main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutCreateWindow("points");
 glutDisplayFunc(display);
 myinit();
 glutMainLoop();
 }
