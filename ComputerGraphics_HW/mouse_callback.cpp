/********************************************************/
/*               HW#4 : Callback ���α׷�-���콺�ݹ�(1) */
/*       �ۼ��� : �赿��         ��¥ : 2020�� 10�� 19��*/
/*                ���� ���� : ���콺 Ŭ������ �ݹ� ���� */
/*                     - - - - - - -                    */
/********************************************************/
#include <GL/glut.h>
GLfloat x1 = -0.5, x2 = 0.5, y1 = 0.5, y2 = -0.5; //���� ��ǥ
GLboolean Check = true;

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //���ú���
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON); //�����׸���
	glVertex3f(x1, y1, 0.0); //���� ��ǥ
	glVertex3f(x2, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x1, y2, 0.0);
	glEnd();
	glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y ){
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) //���콺 ���ʹ�ư�� ����ä��
		Check = false; //check=false
	else //�ƴϸ�
		Check = true; //check=true
}

void MyTimer(int Value) {
	if (!Check) { //üũ�� false�̸�
		if (x2 >= 1.0f) { //x2�� 1.0���� ũ�ų� ������ ��, ���� �ε�����
			x2 += 0.0; //�״��
			x1 += 0.0;
		}
		else { //�ƴϸ�
			x2 += 0.1; //���������� �̵�
			x1 += 0.1;
		}
	}

	glutPostRedisplay(); //�����
	glutTimerFunc(200, MyTimer, 1); //�ݹ��Լ� ���
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay); //���÷����Լ� ���
	glutTimerFunc(200, MyTimer, 1); //�ݹ��Լ� ���
	glutMouseFunc(MyMouseClick ); //���콺Ŭ���Լ� ���
	glutMainLoop();
	return 0;
}