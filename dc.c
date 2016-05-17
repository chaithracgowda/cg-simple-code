#define WHITE 1
#define PINK 2
#include<GL/glut.h>
#include<stdlib.h>

#include<stdio.h>

#include<string.h>

float a=0.0,b=0.0,c=0.0,d=0.0;
int x1;
void myinit()
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,300.0,0.0,200.0);
}

void Sprint( int xx1, int yy1, char *st)

{

 int l4,i4;

 l4=strlen( st ); 

 glRasterPos2i(xx1,yy1);	 

 for(i4=0;i4<l4;i4++)		 

 {

   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st[i4]);			 

 }

}


void draw(GLfloat x0,GLfloat y0,GLfloat x1,GLfloat y1)
{
glBegin(GL_LINES);
glVertex2i(x0,y0);
glVertex2i(x1,y1);
glEnd();
}
void buret(void)
{
glColor3f(0.0,0.0,1.0);
draw(100,80,98,90);
draw(98,90,94,111);
draw(94,111,94,200);
draw(100,80,102,90);
draw(102,90,106,111);
draw(106,111,106,200);
draw(94,200,106,200);
draw(97,90,106,90);
draw(106,90,106,93);
draw(106,90,106,87);
glColor3f(1.0,1.0,1.0);
draw(94,111,106,111);
draw(94,185,106,185);
}
void edge(float xmin,float ymin,float xmax,float ymax,int *le,int *re)
{
float mx,x2,temp;
int i;
if((ymax-ymin)<0)
{
temp=ymin;
ymin=ymax;
ymax=temp;
temp=xmin;
xmin=xmax;
xmax=temp;
}
if((ymax-ymin)!=0)
mx=(xmax-xmin)/(ymax-ymin);
else
mx=(xmax-xmin);
x2=xmin;
for(i=ymin;i<=ymax;i++)
{
if(x2<(float)le[i])
le[i]=(int)x2;
if(x2>(float)re[i])
re[i]=(int)x2;
x2+=mx;
}
}
void drawpixel(float x,float y,int value)
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}
void drawpixel1(float x,float y,int value)
{
glColor3f(1.0,0.0,1.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}

void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
int le[500],re[500];
int i,y;
for(i=0;i<500;i++)
{
le[i]=500;
re[i]=0;
}
edge(x1,y1,x2,y2,le,re);
edge(x2,y2,x3,y3,le,re);
edge(x3,y3,x4,y4,le,re);
edge(x4,y4,x1,y1,le,re);
for(y=0;y<500;y++)
{
if(le[y]<=re[y])
for(i=(int)le[y];i<(int)re[y];i++)
drawpixel(i,y,WHITE);
}
}
void scanfill1(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
int le[500],re[500];
int i,y;
for(i=0;i<500;i++)
{
le[i]=500;
re[i]=0;
}
edge(x1,y1,x2,y2,le,re);
edge(x2,y2,x3,y3,le,re);
edge(x3,y3,x4,y4,le,re);
edge(x4,y4,x1,y1,le,re);
for(y=0;y<500;y++)
{
if(le[y]<=re[y])
for(i=(int)le[y];i<(int)re[y];i++)
drawpixel1(i,y,PINK);
}
}
void conical()
{
glColor3f(0.0,0.0,1.0);
draw(90,65,90,50);
draw(90,50,75,25);
draw(110,65,110,50);
draw(110,50,125,25);
draw(75,25,78,22);
draw(125,25,122,22);
draw(78,22,122,22);
glColor3f(1.0,0.0,1.0);
draw(75,25,125,25);
}
void dro()
{
glColor3f(1.0,1.0,1.0);
draw(100,80,100,77);
draw(100,75,100,72);
draw(100,69,100,66);
draw(100,63,100,60);
draw(100,57,100,54);
draw(100,51,100,48);
}
update()
{
a=a;
b=b-0.20;
if(b<-21.0)
b=0.0;
glutPostRedisplay();

d=d;
c=c-0.20;
if(c<-10.0)
c=10.0;
glutPostRedisplay();


}
 


void display()
{
int i=0;
glClear(GL_COLOR_BUFFER_BIT);
buret();
glPushMatrix();
glutTimerFunc(400,update,0);
glTranslated(a,b,0.0);
dro();
glutPostRedisplay();
glPopMatrix();
glPushMatrix();
glTranslated(c,d,0.0);
conical();
scanfill1(75,25,78,22,122,22,125,25);
glutPostRedisplay();
glPopMatrix();
scanfill(94,185,106,185,106,111,94,111);
scanfill(95,111,107,111,103,90,99,90);
scanfill(95,111,103,90,101,80,101,80);
sprintf(125,100,"conical");
glColor3f(1.0,1.0,1.0);
glRasterPos2i(100,120);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,"L");
glFlush();
}


void stop()

{

 for(x1=0;x1<1000;x1++)

 { 

   x1+=1;

   display();
  
 }

}



void mouse(int btn,int stat,int x,int y)

{

 if(btn==GLUT_LEFT_BUTTON && stat==GLUT_DOWN)

 stop();

}



void diffmove(int id)

{

 switch (id) 

 {

   case 1:

	glutPostRedisplay();

        exit(0);

        break;

   case 2:

	glutPostRedisplay();

	stop();

	break;

   case 3:

        glutPostRedisplay();

        display();

        break;

  default:

        break;

  }

}



int main(int argc,char*argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutAddMenuEntry("exit",1);
glutAddMenuEntry("move",2);
glutAddMenuEntry("quit titration",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutInitWindowSize(640,480);
glutCreateWindow("TITRATION");
glutDisplayFunc(display);
myinit();
glutCreateMenu(diffmove);

     glutAddMenuEntry("Exit ",1);

     glutAddMenuEntry("Stop",2);		

     glutAddMenuEntry("Move",3);

     glutAttachMenu(GLUT_RIGHT_BUTTON);

 glutMouseFunc(mouse);


glutMainLoop();
}




























