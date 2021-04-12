/********************************************************/
/*                 HW#4 : Callback ���α׷�-Ÿ�̸� �ݹ� */
/*       �ۼ��� : �赿��         ��¥ : 2020�� 10�� 19��*/
/*                ���� ���� : Ÿ�̸ӷ� ���� ���� �ٲٱ� */
/*                     - - - - - - -                    */
/********************************************************/
#include<GL/glut.h>
#include<stdlib.h>
#include<time.h>
GLfloat Delta1 = 0.0, Delta2 = 0.0, Delta3 = 0.0;
void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(Delta1,Delta2,Delta3); //Delta�� ��ǥ���Ͽ� ������ ��� �ٲ���
	glVertex3f(-1.0, -0.5, 0.0); //�簢�� �׸���
	glVertex3f(0.0,-0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-1.0, 0.5, 0.0);
	glEnd();
	glutSwapBuffers(); //���� �ٲٱ�
}

void MyTimer(int Value){
	srand((unsigned)time(NULL));
	Delta1 = (rand() % 20); //Delta1���� �ֽ�ȭ
	Delta1 /= 25;
	Delta2 = (rand() % 20); //Delta2���� �ֽ�ȭ
	Delta2 /= 25;
	Delta3 = (rand() % 20); //Delta3���� �ֽ�ȭ
	Delta3 /= 25;

	glutPostRedisplay(); //�����
	glutTimerFunc(400, MyTimer, 1); //�ݹ��Լ� ���
}

void MyInit(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Idle Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(400, MyTimer, 1); //�ݹ��Լ� ���
	glutMainLoop();
	return 0;
}