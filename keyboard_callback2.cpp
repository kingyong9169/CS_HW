/********************************************************/
/*               HW#4 : Callback ���α׷�-Ű�����ݹ�(2) */
/*       �ۼ��� : �赿��         ��¥ : 2020�� 10�� 19��*/
/* ���� ���� : ����Ű, pageup, downŰ�� Ű�����ݹ� ���� */
/*                     - - - - - - -                    */
/********************************************************/
#include <GL/glut.h>
GLfloat x1= -0.5, x2= 0.5, y1= 0.5, y2= -0.5; //������ ��ǥ

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON); //������ �׷���
	glVertex3f(x1, y1, 0.0); //������ ��ǥ
	glVertex3f(x2, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x1, y2, 0.0);
	glEnd();
	glFlush();
}

void MySpecial(int key, int pos1, int pos2) {
	switch (key) {
	case GLUT_KEY_RIGHT: //������ ����Ű
	if (x2 >= 1.0f) { //������ ������ x��ǥ�� 1.0�� �����
		x2 += 0.0; //�״��
		x1 += 0.0;
	}
	else{ //�ƴϸ�
		x2 += 0.1; //���������� 0.1�̵� 
		x1 += 0.1;
	}
		break;
	case GLUT_KEY_LEFT: //���� ����Ű
		if (x1 <= -1.0f) { //������ ���� x��ǥ�� -1.0�� �����
			x2 -= 0.0; //�״��
			x1 -= 0.0;
		}
		else { //�ƴϸ�
			x2 -= 0.1; //�������� 0.1�̵�
			x1 -= 0.1;
		}
		break;
	case GLUT_KEY_UP: //���� ����Ű
		if (y1 >= 1.0f) { //������ ���� y��ǥ�� 1.0�� �����
			y1 += 0.0; //�״��
			y2 += 0.0;
		}
		else { //�ƴϸ�
			y1 += 0.1; //�������� 0.1�̵�
			y2 += 0.1;
		}
		break;
	case GLUT_KEY_DOWN:
		if (y2 <= -1.0f) { //������ �Ʒ��� y��ǥ�� 1.0�� �����
			y2 -= 0.0; //�״��
			y1 -= 0.0;
		}
		else {
			y2 -= 0.1; //�Ʒ������� -0.1�̵�
			y1 -= 0.1;
		}
		break;
	case GLUT_KEY_PAGE_UP: //�������� ��ư
		if ((x1 <= -1.0f) || (y1 >= 1.0) || (x2 >= 1.0) || (y2 <= -1.0f)) { //���ڰ� ���� �ε����ų� ������ ���� ���̰� 2.0�� �Ǹ�
			x1 -= 0.0f; //�״��
			x2 += 0.0f;
			y1 += 0.0f;
			y2 -= 0.0f;
		}
		else { //�ƴϸ�
			x1 -= 0.1f; //Ȯ�� 
			x2 += 0.1f;
			y1 += 0.1f;
			y2 -= 0.1f;
		}
		break;
	case GLUT_KEY_PAGE_DOWN:
		if ((x1 <= -1.0f) || (y1 >= 1.0f) || (x2 >= 1.0f) || (y2 <= -1.0f)
			||(x2-x1<=0.2f)|| (y1 - y2 <= 0.2f)) { //���ڰ� ���� �ε����ų� ������ ���� ���̰� 0.2�� �Ǹ�
			x1 += 0.0f; //�״��
			x2 -= 0.0f;
			y1 -= 0.0f;
			y2 += 0.0f;
		}
		else { //�ƴϸ�
			x1 += 0.1f; //���
			x2 -= 0.1f;
			y1 -= 0.1f;
			y2 += 0.1f;
		}
		break;
	}
	glutPostRedisplay(); //�����
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay); //���÷��� �Լ����
	glutSpecialFunc(MySpecial); //Ű���� �ݹ� �Լ����
	glutMainLoop();
	return 0;
}