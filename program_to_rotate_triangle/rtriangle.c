#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

float triangle[3][3] = {{200,250,300},{200,300,200},{1,1,1}};
float rotate[3][3] = {{0},{0},{0}};
float result[3][3] = {{0},{0},{0}};
float theta, h, k, m, n;

void drawtriangle(float a[3][3])
{
	glBegin(GL_TRIANGLES);
		glVertex2f(a[0][0],a[1][0]);
		glVertex2f(a[0][1],a[1][1]);
		glVertex2f(a[0][2],a[1][2]);
	glEnd();
}

void multiply()
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			result[i][j] = 0;
			for(k=0;k<3;k++)
			{
				result[i][j] = result[i][j] + (rotate[i][k] * triangle[k][j]);
			}
		}
	}
}

void rrotate(float m, float n)
{
	rotate[0][0]=cos(theta);
	rotate[0][1]=-sin(theta);
	rotate[0][2]=m;

	rotate[1][0]=sin(theta);
	rotate[1][1]=cos(theta);
	rotate[1][2]=n;

	rotate[2][0]=0;
	rotate[2][1]=0;
	rotate[2][2]=1;
	multiply();
}



void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,0);
	drawtriangle(triangle);

	glColor3f(1,1,0);
	rrotate(0,0);
	drawtriangle(result);

	glColor3f(0,0,1);

	m= h*(1-cos(theta)) + (k*sin(theta));
	n = k*(1-cos(theta)) -  (h*sin(theta));

	rrotate(m,n);
	drawtriangle(result);

	glFlush();
}



int main(int argc, char **argv)
{
	printf("Enter the rotation angle\n");
	scanf("%f",&theta);
	theta = theta*(3.14/180);

	printf("Enter the fixed values\n");
	scanf("%f %f",&h,&k);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Triangle 1cr21cs414");
	init();

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


