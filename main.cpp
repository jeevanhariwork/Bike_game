#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<GL/glut.h>
#include<stdio.h>
#include<conio.h>

int theta =0 ,n,j,axis=-1,t=10000,x=1,s=1,ax=15,wflag=0,gear=1,submenu;
double i;
float a=-175.0,ac=.50,b=195.0,x1=-195,x2=-155,x3=-175,x4=-200,x5=-150,x6=-170,x7=-180,x8=0,x9=20,cl1=1.0,cl2=0.0,cl3=0.0;
float d=0,dir=-1,st=0;

void wheels()	//Function to draw wheels
{
glLineWidth(2.5);
glPointSize(2.0);
glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex3f(5,0,1);
glVertex3f(-5,0,10);
glVertex3f(0,5,10);
glVertex3f(0,-5,10);
glEnd();


glBegin(GL_POINTS);
glVertex2f(0,0);
glEnd();

glBegin(GL_POINTS);
for(j=5;j<9;j++)
for(i=0;i<360;i++)
{
glVertex3f(j*cos(i),j*sin(i),10);
}
glEnd();
}

void body()
{
glColor3f(0.9,0.9,0.5); //headlight
glBegin(GL_POLYGON);
glVertex2f(28.0,14.0);
glVertex2f(35.0,15.0);
glVertex2f(34.0,25.0);
glVertex2f(27.0,27.0);
glEnd();

glColor3f(0.8,0.6,0.9);	//tank
glBegin(GL_POLYGON);
glVertex2f(13.0,22.5);
glVertex2f(26.0,22.5);
glVertex2f(30.0,10.0);
glVertex2f(10.0,10.0);
glEnd();

glColor3f(0,0,0);	//tail
glBegin(GL_TRIANGLES);
glVertex2f(-9.0,22.5);
glVertex2f(3.5,21.0);
glVertex2f(8.0,8.0);
glEnd();
glColor3f(1,0,0);	//centre part
glBegin(GL_POLYGON);
glVertex2f(10.0,-3.0);
glVertex2f(20.0,-3.0);
glVertex2f(35.0,15.0);
glVertex2f(0.0,17.5);
glEnd();
}

void geaar()
{
char *p="GEAR";
glColor3f(0.0,0.0,0.0);
for(int v=0;v<strlen(p);v++)
{
glRasterPos2i(40+(10*v),180);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,p[v]);
}

glColor3f(1.0,1.0,1.0);
if(gear==4)
{
glRasterPos2i(90,180);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
}
else if(gear==3)
{
glRasterPos2i(90,180);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
}
 else if(gear==2)
{
glRasterPos2i(90,180);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
}
  else
{
glRasterPos2i(90,180);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
}
}

void road()
{
    glColor3f(0.9,0.9,0.9); // Road Alignment
    for(int x=-500; x<500; x=x+40)
    {
        glBegin(GL_POLYGON);
        glVertex3f(x,-103,0);
        glVertex3f(x+15,-103,0);
        glVertex3f(x+15,-104,0);
        glVertex3f(x,-104,0);
        glEnd();
    }

    glColor3f(0.4,0.4,0.4);   // Road
    glBegin(GL_POLYGON);
    glVertex3f(500,-90,0);
    glVertex3f(-500,-90,0);
    glVertex3f(-500,-116,0);
    glVertex3f(500,-116,0);
    glEnd();

    glColor3f(0.6,0.6,1.0);   // Sky
    glBegin(GL_POLYGON);
    glVertex3f(-500,200,0);
    glVertex3f(500,200,0);
    glVertex3f(500,-103,0);
    glVertex3f(-500,-103,0);
    glEnd();

    glColor3f(0.0,0.6,0.0); // Grassland
    glBegin(GL_POLYGON);
    glVertex3f(-500,-110,0);
    glVertex3f(500,-110,0);
    glVertex3f(500,-200,0);
    glVertex3f(-500,-200,0);
    glEnd();

    glColor3f(0,0,0);             // Lamp
    int lampPositions[] = {-200, -150, -100}; // Existing lamp positions
    for(int i = 0; i < 3; i++)
    {
        glLineWidth(5.0);
        glBegin(GL_LINES);
        glVertex3f(lampPositions[i],-116,1);
        glVertex3f(lampPositions[i],10,1);
        glVertex3f(lampPositions[i],10,1);
        glVertex3f(lampPositions[i]+20,10,1);
        glEnd();
        glPointSize(15.0);

        glBegin(GL_POINTS);  // Lamp Light
        glVertex3f(lampPositions[i]+20,10,1);
        glEnd();
    }
}


void display()	//Function to display every thing and provide rotation
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glPushMatrix();
if(a>=220.0)
a=-220;
glTranslatef(a,-92,0);	//move front wheels
glRotatef(theta,0.0,0.0,1.0);
wheels();
glPopMatrix();
glPushMatrix();	//move rear wheel
glTranslatef(a+30,-92,0);
glRotatef(theta,0.0,0.0,1.0);
wheels();
glPopMatrix();

glPushMatrix();	//move body
glTranslatef(a,-92,0);
body();
glPopMatrix();

if(wflag==1)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
geaar();
glPushMatrix();
glTranslatef(a,-92,0);
glRotatef(theta,0.0,0.0,1.0);
wheels();
glPopMatrix();

glPushMatrix();
glTranslatef(a+24,-61,0);
wheels();
glPopMatrix();
glPushMatrix();
glTranslatef(a+1,-91,0);
glRotatef(46.0,0.0,0.0,1.0);
body();
glPopMatrix();
}

geaar();
glPushMatrix();	//move road
if(b<=-300.0)
b=+300;
glTranslatef(b,0,0);
road();
glPopMatrix();
glFlush();
glutSwapBuffers();
glutPostRedisplay();
}

void spin()
{
theta+=ax*axis;
if(theta>360)
theta=0;
glutPostRedisplay();
axis=0;
}

void mytimer(int v)
{
glutTimerFunc(t/60,mytimer,v);
spin();

}

void my_menu(int id)
{
switch(id)
{
case 7:exit(0);
break;
}
}

void menu()
{
glutCreateMenu(my_menu);
glutAddMenuEntry("Exit",7);

glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void keys(unsigned char key,int x,int y)
{
if(key=='x' || key=='X')
{
a--;
}
if(key=='U'||key=='u')
{
wflag=1;
}
if(key=='s'||key=='S')
{
wflag=0;
}

if(key=='I'  || key=='i')
{
ax=ax+10;
gear++;
if(ax>=45||gear>=4)
{
ax=45;
gear=4;
}
t/=10;
d+=0.15;
}
if(key=='D' || key=='d')
{
ax=ax-10;
gear--;
if(ax<=15||gear<=1)
{
gear=1;
ax=15;
}
t*=10;
d-=0.15;
}

if(key==87 || key==119)
{
t=10;
d+=0.15;
a=a+ac;
b=b-ac;
axis=-1;
if(gear==1)
ac=.50;
else if(gear==2)
ac=1;
else if(gear==3)
ac=2;
else
ac=3;
}
if(key==27)
exit(0);
}


int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(1280,800);
glutInitWindowPosition(0,0);
glutCreateWindow("Bike Ride");

glEnable(GL_DEPTH_TEST);

printf("\nKEY USAGE : \n\n");
printf("--------------------------------\n");
printf("I or i -> Increase Gear\n");
printf("D or d -> Decrease Gear\n");
printf("W or w -> Start Bike\n");
printf("U or u -> Perform Wheelie\n");
printf("S or s -> Stop Bike\n");
printf("ESC    -> Exit \n");
printf("--------------------------------\n");
glutTimerFunc(100,mytimer,60);
int flag=0;
glutKeyboardFunc(keys);
menu();
glOrtho(-200,200,-200,200,-10,10);
glClearColor(1,1,1,1);
glutDisplayFunc(display);
glutMainLoop();
}
