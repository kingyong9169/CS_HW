/***************************************************/
/*          HW#4 : Callback ���α׷�-Ű�����ݹ�(1) */
/*  �ۼ��� : �赿��         ��¥ : 2020�� 10�� 19��*/
/*   ���� ���� : a, f, r, v, bŰ�� Ű�����ݹ� ���� */
/*                - - - - - - -                    */
/***************************************************/
#include <GL/glut.h>
GLfloat x, y;
GLfloat r=0.5, g=0.5, b=0.5; //r,g,b���� ����
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //���ú��� ����
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON); //���� �׷���
	glVertex3f(-0.5 + x, -0.5 + y, 0.0); //���� ��ǥ
	glVertex3f(0.5 + x, -0.5 + y, 0.0);
	glVertex3f(0.5 + x, 0.5 + y, 0.0);
	glVertex3f(-0.5 + x, 0.5 + y, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int pos1, int pos2) {
	switch (key) {
	case 'a': //a, AŰ ������ �������� 0.1�� �̵�
	case 'A':
		x = x - 0.1f;
		break;
	case 'f': //f, FŰ ������ ���������� 0.1�� �̵�
	case 'F':
		x = x + 0.1f;
		break;
	case 'r': //r, RŰ ������ �Ʒ������� 0.1�� �̵�
	case 'R':
		y = y + 0.1f;
		r = 1.0; g = 0.0; b = 0.0;
		break;
	case 'v': //b, BŰ ������ �������� 0.1�� �̵�
	case 'V':
		y = y - 0.1f;
		break;
	case 'b': //b, BŰ ������ �Ķ������� ���� ĥ��
	case 'B':
		r = 0.0; g = 0.0; b = 1.0;
		break;
	case 'q':
	case 'Q':
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay); //���÷��� �ݹ��Լ� ���
	glutKeyboardFunc(MyKeyboard); //Ű���� �Լ� ���
	glutMainLoop();
	return 0;
}