/***************************************************/
/*              HW#5-2 : �κ� �� ����              */
/*  �ۼ��� : �赿��     ��¥ : 2020�� 11�� 11��    */
/*                                                 */
/*   ���� ���� : �հ��� 3���� ���� Robot Arm ����  */
/*                - - - - - - -                    */
/***************************************************/
#include <gl/glut.h>
#include <stdlib.h>
static int shoulder = 0, elbow = 0, finger1 = 0, finger2 = 0, finger3 = 0, 
check1=0, check2 = 0, check3 = 0, check4=0, check5=0; //ȸ��Ƚ�� üũ��
void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix(); //finger1
		glTranslatef(-1.0, 0.0, 0.0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat )shoulder, 0.0, 0.0, 1.0); // ������ �������� ȸ��
		glTranslatef(1.0, 0.0, 0.0); // Pivot ���� ������ ��ġ�� �������� �̵�
		glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(1.0);
		glPopMatrix();

		glTranslatef(1.0, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);// ������ �������� ȸ��
		glTranslatef(1.0, 0.0, 0.0);// Pivot ���� ������ ��ġ�� �������� �̵�

		glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
			glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(2.0, 0.4, 1.0);
				glutWireCube(1.0);
			glPopMatrix();
			glTranslatef(1.0, 0.0, -0.5);// Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);// ù ��° �հ��� ù ��° ����
			glTranslatef(0.2, 0.0, 0.0);// Pivot ���� ������ ��ġ�� �������� �̵�
			glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.3, 0.2, 0.2); // ù ��° �հ��� ù ��° ������ ũ�⸦ ���ϰ� �׸���
				glutWireCube(1.0);
			glPopMatrix();
				glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
				glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);// ù ��° �հ��� �� ��° ����
				glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
				glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
					glScalef(0.3, 0.2, 0.2); // ù ��° �հ��� �� ��° ������ ũ�⸦ ���ϰ� �׸���
					glutWireCube(1.0);
				glPopMatrix();
				glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
					glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);// ù ��° �հ��� �� ��° ����
					glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
					glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
						glScalef(0.3, 0.2, 0.2); // ù ��° �հ��� �� ��° ������ ũ�⸦ ���ϰ� �׸���
						glutWireCube(1.0);
					glPopMatrix();
		glPopMatrix();

		glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
			glTranslatef(1.0, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);// �� ��° �հ��� ù ��° ����
			glTranslatef(0.2, 0, 0.0);// Pivot ���� ������ ��ġ�� �������� �̵�
			glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.3, 0.2, 0.2); // �� ��° �հ��� ù ��° ������ ũ�⸦ ���ϰ� �׸���
				glutWireCube(1.0); 
			glPopMatrix();
			glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);// �� ��° �հ��� �� ��° ����
			glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
				glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
					glScalef(0.3, 0.2, 0.2); // �� ��° �հ��� �� ��° ������ ũ�⸦ ���ϰ� �׸���
					glutWireCube(1.0);
				glPopMatrix();
				glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
				glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);// �� ��° �հ��� �� ��° ����
				glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
					glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
						glScalef(0.3, 0.2, 0.2); // �� ��° �հ��� �� ��° ������ ũ�⸦ ���ϰ� �׸���
						glutWireCube(1.0);
					glPopMatrix();
		glPopMatrix();

		glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
			glTranslatef(1.0, 0.0, 0.5);// Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);// �� ��° �հ��� ù ��° ����
			glTranslatef(0.2, 0.0, 0.0);// Pivot ���� ������ ��ġ�� �������� �̵�
			glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.3, 0.2, 0.2); // �� ��° �հ��� ù ��° ������ ũ�⸦ ���ϰ� �׸���
				glutWireCube(1.0);
			glPopMatrix();
			glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);// �� ��° �հ��� �� ��° ����
			glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
				glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
					glScalef(0.3, 0.2, 0.2); // �� ��° �հ��� �� ��° ������ ũ�⸦ ���ϰ� �׸���
					glutWireCube(1.0);
				glPopMatrix();
				glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
				glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);// �� ��° �հ��� �� ��° ����
				glTranslatef(0.2, 0.0, 0.0);// Pivot ���� �� ��ü �̵�
					glPushMatrix();// ������ �������� ��ü ���� �� ��� Ȯ��
						glScalef(0.3, 0.2, 0.2); // �� ��° �հ��� �� ��° ������ ũ�⸦ ���ϰ� �׸���
						glutWireCube(1.0);
					glPopMatrix();
		glPopMatrix();
	
	glPopMatrix(); //�������� ���ư�
	glutSwapBuffers();
}

void MyInit(void){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}

void MyReshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void MyTimer1(int Value) { //ȸ���� �� 38�� �ϰ� �ȴ�.
	if (check1 > 37) //ȸ���� 38�� �̻��ϸ�
	{
		check1 = 0; //ȸ�� Ƚ�� 0
		return;
	}
	else if (check1 <= 18) //ȸ���� 18�� ���Ϸ� �ϰ� �Ǹ�
	{
		check1 += 1; //ȸ�� Ƚ�� ����
		finger1 = (finger1 + 5) % 180; //���� ���θ���
		glutPostRedisplay(); //�����
		glutTimerFunc(200, MyTimer1, 1); //�ݹ��Լ� ���
	}
	else if (check1 > 18) //ȸ�� Ƚ���� 19�̻��̸�
	{
		check1 += 1; //ȸ�� Ƚ�� ����
		finger1 = (finger1 - 5) % 180; //���� �ɴ�
		glutPostRedisplay(); //�����
		glutTimerFunc(200, MyTimer1, 1); //�ݹ��Լ� ���
	}
}

void MyTimer2(int Value) { //ȸ���� �� 38�� �ϰ� �ȴ�.
	if (check2 > 37) //ȸ���� 38�� �̻��ϸ�
	{
		check2 = 0; //ȸ�� Ƚ�� 0
		return;
	}
	else if (check2 <= 18) //ȸ���� 18�� ���Ϸ� �ϰ� �Ǹ�
	{
		check2 += 1; //ȸ�� Ƚ�� ����
		finger2 = (finger2 + 5) % 180; //���� ���θ���
		glutPostRedisplay(); //�����
		glutTimerFunc(200, MyTimer2, 1); //�ݹ��Լ� ���
	}
	else if (check2 > 18) //ȸ�� Ƚ���� 19�̻��̸�
	{
		check2 += 1; //ȸ�� Ƚ�� ����
		finger2 = (finger2 - 5) % 180; //���� �ɴ�
		glutPostRedisplay(); //�����
		glutTimerFunc(200, MyTimer2, 1); //�ݹ��Լ� ���
	}
}

void MyTimer3(int Value) { //ȸ���� �� 38�� �ϰ� �ȴ�.
	if (check3 > 37) //ȸ���� 38�� �̻��ϸ�
	{
		check3 = 0; //ȸ�� Ƚ�� 0
		return;
	}
	else if (check3 <= 18) //ȸ���� 18�� ���Ϸ� �ϰ� �Ǹ�
	{
		check3 += 1; //ȸ�� Ƚ�� ����
		finger3 = (finger3 + 5) % 180; //���� ���θ���
		glutPostRedisplay(); //�����
		glutTimerFunc(200, MyTimer3, 1); //�ݹ��Լ� ���
	}
	else if (check3 > 18) //ȸ�� Ƚ���� 19�̻��̸�
	{
		check3 += 1; //ȸ�� Ƚ�� ����
		finger3 = (finger3 - 5) % 180; //���� �ɴ�
		glutPostRedisplay(); //�����
		glutTimerFunc(200, MyTimer3, 1); //�ݹ��Լ� ���
	}
}

void MyTimer_left(int Value) { //��Ŭ�� Ÿ�̸� �Լ�
	if (finger1 == 90 && finger2 == 90 && finger3 == 90 && shoulder == 90 && elbow == 90) //��� ������ 90���� �Ǹ�
		return; //�����
	if (finger1 < 90)
		finger1 = (finger1 + 5) % 180; //�հ����� ���θ���
	if (finger2 < 90)
		finger2 = (finger2 + 5) % 180; //�հ����� ���θ���
	if (finger3 < 90)
		finger3 = (finger3 + 5) % 180; //�հ����� ���θ���
	if (shoulder < 90)
		shoulder = (shoulder + 5) % 180; //����� ���θ���
	if (elbow < 90)
		elbow = (elbow + 5) % 180; //�Ȳ�ġ�� ���θ���
	glutPostRedisplay(); //�����
	glutTimerFunc(200, MyTimer_left, 1); //�ݹ��Լ� ���
}

void MyTimer_right(int Value) { //��Ŭ�� Ÿ�̸� �Լ�
	if (finger1 == 0&& finger2 == 0&& finger3 == 0 && shoulder == 0 && elbow==0) //��� ������ 0���� �Ǹ�
		return; //�����
	if(finger1>0)
		finger1 = (finger1 - 5) % 180; //�հ����� ���θ���
	if (finger2 > 0)
		finger2 = (finger2 - 5) % 180; //�հ����� ���θ���
	if (finger3 > 0)
		finger3 = (finger3 - 5) % 180; //�հ����� ���θ���
	if (shoulder > 0)
		shoulder = (shoulder - 5) % 180; //����� ���θ���
	if (elbow > 0)
		elbow = (elbow - 5) % 180; //�Ȳ�ġ�� ���θ���
	glutPostRedisplay(); //�����
	glutTimerFunc(200, MyTimer_right, 1); //�ݹ��Լ� ���
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case'1':
		glutTimerFunc(200, MyTimer1, 1); //�ݹ��Լ� ���
		break;
	case'2':
		glutTimerFunc(200, MyTimer2, 1); //�ݹ��Լ� ���
		break;
	case'3':
		glutTimerFunc(200, MyTimer3, 1); //�ݹ��Լ� ���
		break;
	case's':
		shoulder = (shoulder + 5) % 180; //����� ���θ���
		break;
	case'S':
		shoulder = (shoulder - 5) % 180; //����� �ɴ�
		break;
	case'e':
		elbow = (elbow + 5) % 180; //�Ȳ�ġ�� ���θ���
		break;
	case'E':
		elbow = (elbow - 5) % 180; //�Ȳ�ġ�� �ɴ�
		break;
	case 27: 
		exit(0); //�����Ѵ�
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { //���콺 ���ʹ�ư�� ����ä��
		glutTimerFunc(200, MyTimer_left, 1); //�ݹ��Լ� ���
	}
	else if(Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN)//�ƴϸ�
		glutTimerFunc(200, MyTimer_right, 1); //�ݹ��Լ� ���
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot Arm");
	MyInit();
	glutDisplayFunc(MyDisplay); //���÷��� �Լ� ���
	glutReshapeFunc(MyReshape); //reshape�Լ� ���
	glutKeyboardFunc(MyKeyboard); //Ű�����Լ� ���
	glutMouseFunc(MyMouseClick); //���콺Ŭ���Լ� ���
	glutMainLoop();
	return 0;
}