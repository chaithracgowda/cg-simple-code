#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

int global = 0,tex1=0;

void myinit()
{ glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;

GLfloat *make_texture(int maxs, int maxt)
{
    int s, t;
    static GLfloat *texture;

    texture = (GLfloat *)malloc(maxs * maxt * sizeof(GLfloat));
    for(t = 0; t < maxt; t++) {
	for(s = 0; s < maxs; s++) {
	    texture[s + maxs * t] = ((s >> 4) & 0x1) ^ ((t >> 4) & 0x1);
	}
    }
    return texture;
}

void wings()
{  	glBegin(GL_POLYGON);   
    glColor3f(0.0,0.0,0.0);    /*default color of fan*/
    glVertex2f(0.0,0.0);
    glVertex2f(-0.25,0.5);
    glVertex2f(0.25,0.5);
  
	glVertex2f(0.0,0.0);
	glVertex2f(0.5,0.25);
	glVertex2f(0.5,-0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(-0.5,-0.25);
	glVertex2f(-0.5,0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(0.25,-0.5);
	glVertex2f(-0.25,-0.5);
   glEnd();
   	
 if(global==1 && tex1==1)					/*Black texture color*/
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);             
  glColor3f(0.0,0.0,0.0);
  glTexCoord2i(0,0);
    glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,1);
    glVertex2f(-0.25,0.5);
  glColor3f(0.0,0.0,0.0);
  glTexCoord2i(0,0);
    glVertex2f(0.25,0.5);
  
  glColor3f(0.0,0.0,0.0);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.5,0.25);
  glColor3f(0.0,0.0,0.0);
  glTexCoord2i(0,1);
	glVertex2f(0.5,-0.25);

  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(-0.5,-0.25);
  glColor3f(0.0,0.0,0.0);
  glTexCoord2i(0,1);
	glVertex2f(-0.5,0.25);

  glColor3f(0.0,0.0,0.0);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,1);
	glVertex2f(0.25,-0.5);
  glColor3f(0.0,0.0,0.0);
  glTexCoord2i(0,0);
	glVertex2f(-0.25,-0.5);
   glEnd();
   glDisable(GL_TEXTURE_2D);
}

	
 if(global==2 && tex1==1)					/*Brown texture color*/
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);             
  glColor3f(0.6,0.3,0.1);
  glTexCoord2i(0,0);
    glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,1);
    glVertex2f(-0.25,0.5);
  glColor3f(0.6,0.3,0.1);
  glTexCoord2i(0,0);
    glVertex2f(0.25,0.5);

  glColor3f(0.6,0.3,0.1);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.5,0.25);
  glColor3f(0.6,0.3,0.1);
  glTexCoord2i(0,1);
	glVertex2f(0.5,-0.25);

  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(-0.5,-0.25);
  glColor3f(0.6,0.3,0.1);
  glTexCoord2i(0,1);
	glVertex2f(-0.5,0.25);

  glColor3f(0.6,0.3,0.1);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,1);
	glVertex2f(0.25,-0.5);
  glColor3f(0.6,0.3,0.1);
  glTexCoord2i(0,0);
	glVertex2f(-0.25,-0.5);
   glEnd();
   glDisable(GL_TEXTURE_2D);
}

 	
 if(global==3 && tex1==1)					/*purple texture color*/
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);             
  glColor3f(0.7,0.0,0.7);
  glTexCoord2i(0,0);
    glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,1);
    glVertex2f(-0.25,0.5);
 glColor3f(0.7,0.0,0.7);
  glTexCoord2i(0,0);
    glVertex2f(0.25,0.5);
  
  glColor3f(0.7,0.0,0.7);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.5,0.25);
  glColor3f(0.7,0.0,0.7);
  glTexCoord2i(0,1);
	glVertex2f(0.5,-0.25);

  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(-0.5,-0.25);
 glColor3f(0.7,0.0,0.7);
  glTexCoord2i(0,1);
	glVertex2f(-0.5,0.25);

  glColor3f(0.7,0.0,0.7);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,1);
	glVertex2f(0.25,-0.5);
 glColor3f(0.7,0.0,0.7);
  glTexCoord2i(0,0);
	glVertex2f(-0.25,-0.5);
   glEnd();
   glDisable(GL_TEXTURE_2D);
}

 	
 if(global==4 && tex1==1)					/*Blue texture color*/
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);             
  glColor3f(0.0,0.0,1.0);
  glTexCoord2i(0,0);
    glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,1);
    glVertex2f(-0.25,0.5);
  glColor3f(0.0,0.0,1.0);
  glTexCoord2i(0,0);
    glVertex2f(0.25,0.5);
  
  glColor3f(0.0,0.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.5,0.25);
  glColor3f(0.0,0.0,1.0);
  glTexCoord2i(0,1);
	glVertex2f(0.5,-0.25);

  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(-0.5,-0.25);
  glColor3f(0.0,0.0,1.0);
  glTexCoord2i(0,1);
	glVertex2f(-0.5,0.25);

  glColor3f(0.0,0.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glTexCoord2i(0,1);
	glVertex2f(0.25,-0.5);
  glColor3f(0.0,0.0,1.0);
  glTexCoord2i(0,0);
	glVertex2f(-0.25,-0.5);
   glEnd();
   glDisable(GL_TEXTURE_2D);
}

 if(global==1 && tex1==0)
 {
 	glBegin(GL_POLYGON);   
    glColor3f(0.0,0.0,0.0);    /*black color*/
    glVertex2f(0.0,0.0);
    glVertex2f(-0.25,0.5);
    glVertex2f(0.25,0.5);
  
	glVertex2f(0.0,0.0);
	glVertex2f(0.5,0.25);
	glVertex2f(0.5,-0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(-0.5,-0.25);
	glVertex2f(-0.5,0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(0.25,-0.5);
	glVertex2f(-0.25,-0.5);
   glEnd();
 }
 if(global==2 && tex1==0)
 {
  glBegin(GL_POLYGON);             /*Brown color*/
  glColor3f(0.6,0.3,0.1);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.25,0.5);
    glVertex2f(0.25,0.5);
  
	glVertex2f(0.0,0.0);
	glVertex2f(0.5,0.25);
	glVertex2f(0.5,-0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(-0.5,-0.25);
	glVertex2f(-0.5,0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(0.25,-0.5);
	glVertex2f(-0.25,-0.5);
   glEnd();
 }

 if(global==3 && tex1==0)
 {
  glBegin(GL_POLYGON);             /*Purple color*/
  glColor3f(0.7,0.0,0.7);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.25,0.5);
    glVertex2f(0.25,0.5);
  
	glVertex2f(0.0,0.0);
	glVertex2f(0.5,0.25);
	glVertex2f(0.5,-0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(-0.5,-0.25);
	glVertex2f(-0.5,0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(0.25,-0.5);
	glVertex2f(-0.25,-0.5);
   glEnd();
 }

  if(global==4 && tex1==0)
 {
  glBegin(GL_POLYGON);             /*Blue color*/
  glColor3f(0.0,0.0,1.0);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.25,0.5);
    glVertex2f(0.25,0.5);
  
	glVertex2f(0.0,0.0);
	glVertex2f(0.5,0.25);
	glVertex2f(0.5,-0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(-0.5,-0.25);
	glVertex2f(-0.5,0.25);

	glVertex2f(0.0,0.0);
	glVertex2f(0.25,-0.5);
	glVertex2f(-0.25,-0.5);
   glEnd();
 }   
}


void display(void)
{  
	 static GLfloat wall_mat[] = {1.f, 1.f, 1.f, 1.f};        /* Giving textures*/
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, wall_mat);

    /* floor */
    /* make the floor textured */
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glTexCoord2i(0, 0);
		glVertex2f(1.2,-0.7);
	glColor3f(0.0,0.0,0.0);
    glTexCoord2i(0, 1);
		glVertex2f(2.7,-2.0);
	glColor3f(1.0,1.0,1.0);
    glTexCoord2i(0,1);
		glVertex2f(-2.7,-2.0);
	glColor3f(0.0,0.0,0.0);
    glTexCoord2i(0,0);
		glVertex2f(-1.2,-0.7);
    glEnd();

   glDisable(GL_TEXTURE_2D);
  
	glBegin(GL_POLYGON);    /*background wall*/ 
  glNormal3f(1.f, 0.f, 0.f);
 glColor3f(1.0,1.0,1.0);
	   glVertex2f(1.2,-0.7);
	   glVertex2f(-1.2,-0.7);
	   glVertex2f(-1.2,1.5);
	   glVertex2f(1.2,1.5);
  glEnd();

  glEnable(GL_TEXTURE_2D);

  glBegin(GL_POLYGON);    /*wall at right side*/ 
	glColor3f(1.0,1.0,1.0);
    glTexCoord2i(0, 0);
	  glVertex2f(2.7,-2.0);
    glColor3f(0.0,0.0,0.0);
    glTexCoord2i(0, 0);
	  glVertex2f(1.2,-0.7);
	glColor3f(0.0,0.0,0.0);
    glTexCoord2i(0, 0);
	  glVertex2f(1.2,1.5);
	glColor3f(1.0,1.0,1.0);
    glTexCoord2i(0, 0);
	  glVertex2f(2.7,2.0);
  glEnd();

  glBegin(GL_POLYGON);   /*wall at left side*/
	glColor3f(1.0,1.0,1.0);
    glTexCoord2i(0, 0);
	  glVertex2f(-2.7,-2.0);
	glColor3f(0.0,0.0,0.0);
    glTexCoord2i(0, 0);
	  glVertex2f(-1.2,-0.7);
	glColor3f(0.0,0.0,0.0);
    glTexCoord2i(0, 0);
	  glVertex2f(-1.2,1.5);
	glColor3f(1.0,1.0,1.0);
    glTexCoord2i(0, 0);
	  glVertex2f(-2.7,2.0);
  glEnd();

    glBegin(GL_POLYGON);   /*Roof*/
	glColor3f(1.0,1.0,1.0);
    glTexCoord2i(0, 0);
	  glVertex2f(-2.7,2.0);
	glTexCoord2i(0, 0);
	  glVertex2f(2.7,2.0);
	glColor3f(0.0,0.0,0.0);
    glTexCoord2i(0, 0);
	  glVertex2f(1.2,1.5);
    glTexCoord2i(0, 0);
	  glVertex2f(-1.2,1.5);

  glEnd();

  glDisable(GL_TEXTURE_2D);
  
    glEnable(GL_TEXTURE_2D);
  glBegin(GL_POLYGON);      /*stand for fan*/
  glColor3f(0.0,0.0,0.0);
   glTexCoord2i(0, 0);
   glVertex2f(0.0,0.0);
   	glColor3f(1.0,0.0,0.0);
       glTexCoord2i(0, 0);
   glVertex2f(0.4,-1.0);
      	glColor3f(1.0,0.0,0.0);
       glTexCoord2i(0, 0);
   glVertex2f(0.0,-1.2);
    glColor3f(0.0,0.0,0.0);
       glTexCoord2i(0, 0);
   glVertex2f(-0.4,-1.0);
  glEnd();
    glDisable(GL_TEXTURE_2D);

  glBegin(GL_LINES);      /*lines outlining fan*/
  glColor3f(0.0,0.0,0.0);
   glVertex2f(0.0,0.0);
   glVertex2f(0.0,-1.2);
   glVertex2f(0.0,0.0);
   glVertex2f(0.4,-1.0);
   glVertex2f(0.4,-1.0);
   glVertex2f(0.0,-1.2);
   glVertex2f(0.0,-1.2);
   glVertex2f(-0.4,-1.0);
   glVertex2f(-0.4,-1.0);
   glVertex2f(0.0,0.0);
  glEnd();
                    /*buttons*/
  
  glBegin(GL_POLYGON);			/*start button*/
  glColor3f(1.0,0.7,0.0);
   glVertex2f(-0.1,-0.7);
   glVertex2f(-0.1,-0.75);
   glVertex2f(-0.15,-0.75);
   glVertex2f(-0.15,-0.7);
  glEnd();
  glBegin(GL_POLYGON);			/*stop button*/
  glColor3f(0.0,1.0,0.0);
   glVertex2f(-0.2,-0.7);
   glVertex2f(-0.2,-0.75);
   glVertex2f(-0.25,-0.75);
   glVertex2f(-0.25,-0.7);
  glEnd();
  glBegin(GL_POLYGON);          /*1st speed button*/
  glColor3f(0.0,0.0,0.7);
   glVertex2f(-0.15,-0.78);
   glVertex2f(-0.15,-0.82);
   glVertex2f(-0.2,-0.82);
   glVertex2f(-0.2,-0.78);
  glEnd();
  glBegin(GL_POLYGON);         /*2nd speed button*/
  glColor3f(0.0,0.0,0.8);
   glVertex2f(-0.15,-0.84);
   glVertex2f(-0.15,-0.88);
   glVertex2f(-0.2,-0.88);
   glVertex2f(-0.2,-0.84);
  glEnd();
    glBegin(GL_POLYGON);      /*3rd speed button*/
  glColor3f(0.0,0.0,1.0
	  );
   glVertex2f(-0.15,-0.90);
   glVertex2f(-0.15,-0.94);
   glVertex2f(-0.2,-0.94);
   glVertex2f(-0.2,-0.90);
  glEnd();
   
                             /*circled envelop*/
  glColor3f(0.0,0.1,0.9);          /*outer*/
   glutSolidSphere(0.65,100,15);
  
  glColor3f(1.0,1.0,1.0);          /*inner*/
  glutSolidSphere(0.62,100,15);
     
  glRotatef(theta[0],1.0,0.0,0.0);  /*rotation of the fan*/
  glRotatef(theta[1],0.0,1.0,0.0);
  glRotatef(theta[2],0.0,0.0,1.0);

  wings();

   glColor3f(1.5,0.0,0.2);       /*circle in middle*/
  glutSolidSphere(0.06,100,15);
  
   glFlush();
}



void idle()                      /*speed at start*/
{theta[axis]+=0.05;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}

void idle1()					/*speed at 1st level*/
{theta[axis]+=0.5;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}

void idle2()					/*speed at 2nd level*/
{theta[axis]+=1.0;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}

void idle3()					/*speed at 3rd level*/
{theta[axis]+=2.0;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}

void keys(unsigned char key,int x,int y) /*keyboard function to implement the fan rotation*/
{
  if(key=='s')
	{ glutIdleFunc(idle);
    }
  if(key=='1')
  {glutIdleFunc(idle1);
  }
   
  if(key=='2')
  {glutIdleFunc(idle2);
  }
  if(key=='3')
  {glutIdleFunc(idle3);
  }
  if(key=='q')
  {glutIdleFunc(NULL);
  }
}

void myreshape(int w,int h)
{glViewport(0,0,w,h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if(w<=h)
	  glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
  else
	  glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glutPostRedisplay();
 }

void demo_menu(int id)
{ switch(id)
{ case 3:exit(0);
         break;

}
glutPostRedisplay();
}

void color1(int id)
{ switch(id)
{ case 1:global=1;
         break;
  case 2:global=2;
         break;
  case 3:global=3;
         break;
   case 4:global=4;
         break;
}
glutPostRedisplay();
}

void func1(int id)
{ switch(id)
{ case 1:glutIdleFunc(idle);
         break;
  case 2:glutIdleFunc(NULL);
	     break;
  case 3:glutIdleFunc(idle1);
	     break;
  case 4:glutIdleFunc(idle2);
	     break;
  case 5:glutIdleFunc(idle3);
	     break;
}
glutPostRedisplay();
}

void tex2(int id)
{ switch(id)
{ case 1:tex1=1;
         break;
  case 2:tex1=0;
	     break;
}
glutPostRedisplay();
}

const int TEXDIM = 256;

void main(int argc,char **argv)
{ int color,func,text;
GLfloat *tex;
	
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(800,600);
  glutCreateWindow("                                                                                       The Table Fan");
  glutReshapeFunc(myreshape);
  myinit();

  color = glutCreateMenu(color1);
    glutAddMenuEntry("Black",1);
  glutAddMenuEntry("Brown",2);
  glutAddMenuEntry("Purple",3);
  glutAddMenuEntry("Blue",4);


  func = glutCreateMenu(func1);
  glutAddMenuEntry("Start",1);
  glutAddMenuEntry("Stop",2);
  glutAddMenuEntry("Speed1",3);
  glutAddMenuEntry("Speed2",4);
  glutAddMenuEntry("Speed3",5);

  text = glutCreateMenu(tex2);
  glutAddMenuEntry("Enable",1);
  glutAddMenuEntry("Disable",2);

  glutCreateMenu(demo_menu);
  glutAddSubMenu("Fan color",color);
  glutAddSubMenu("Fan texture",text);
  glutAddSubMenu("Functions",func);
  glutAddMenuEntry("Quit",3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutDisplayFunc(display);
  //glutMouseFunc(mouse);
  glutKeyboardFunc(keys);


 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   tex = make_texture(TEXDIM, TEXDIM);
    glTexImage2D(GL_TEXTURE_2D, 0, 1, TEXDIM, TEXDIM, 0, GL_RED, GL_FLOAT, tex);
    free(tex);
 
 glutMainLoop();
}
