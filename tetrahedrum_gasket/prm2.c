#include<GL/glut.h>
#include<stdio.h>
int m;
typedef float point[3];
point v[]={{0.0,0.0,1.0},{0.0,1.0,0.0},{-1.0,-1.0,0.0},{1.0,-1.0,0.0}};

void init()
{	

	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
}

void triangle(point a,point b,point c)
{
	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);	
	glEnd();
	
}

void div_triangle(point a,point b,point c,int m)
{
	point v1,v2,v3;
	int j;
	if(m>0)
	{
		for(j=0;j<3;j++)
		v1[j]=(a[j]+b[j])/2;
		for(j=0;j<3;j++)
		v2[j]=(a[j]+c[j])/2;
		for(j=0;j<3;j++)
		v3[j]=(b[j]+c[j])/2;
		div_triangle(a,v1,v2,m-1);
		div_triangle(c,v2,v3,m-1);
		div_triangle(b,v3,v1,m-1);
	}
	else
	triangle(a,b,c);
}

void tetrahedron(int m)
{
		
	glColor3f(0,1,0);
	div_triangle(v[3],v[2],v[1],m);
	glColor3f(1,0,0);
	div_triangle(v[0],v[1],v[2],m);
	glColor3f(0,0,1);
	div_triangle(v[0],v[3],v[1],m);
	glColor3f(0,0,0);
	div_triangle(v[0],v[2],v[3],m);
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	tetrahedron(m);
	glFlush();
}
		
int main(int argc,char **argv)
{	
	printf("\n Enter the number of steps:");
	scanf("%d",&m);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("1cr21cs414");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

