/***************************************************/
/*                HW#5-3 : ���� �κ�               */
/*  �ۼ��� : �赿��     ��¥ : 2020�� 11�� 11��    */
/*                                                 */
/*���� ���� : �� 2��, �ٸ� 2���� ���� Can Robot ����*/
/*                - - - - - - -                    */
/***************************************************/
#include <gl/glut.h>
#include <stdlib.h>
static int body = 0, head = 0, arm1 = 0, arm2 = 0, leg1 = 0, leg2 = 0, //����, �Ӹ�, ��, �ٸ�, ������ ����
arm1_2 = 0, arm2_2 = 0, leg1_2 = 0, leg2_2 = 0,
check1 = 0, check2 = 0; //45�� ȸ���ߴ��� üũ��
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix(); //body
		glTranslatef(0.0, -1.0, 0.0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)body, 0.0, 0.0, 1.0); //�Ӹ��� �������� ȸ��
		glTranslatef(0.0, 1.0, 0.0); // Pivot ���� ������ ��ġ�� �������� �̵�
		glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
			glScalef(1.5, 2.0, 1.0);
			glutWireCube(1.0); // ������ ������ش�
		glPopMatrix();
		//head
		glTranslatef(0.0, 1.0, 0.0); // Pivot ���� ������ ��ġ�� �������� �̵�
		glRotatef((GLfloat)head, 0.0, 0.0, 1.0); //�Ӹ��� �߾��� �������� ȸ��
		glTranslatef(0.0, 0.5, 0.0); // Pivot ���� ������ ��ġ�� �������� �̵�
		glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
			glScalef(1.0, 1.0, 1.0);
			glutWireCube(1.0); // �Ӹ��� ������ش�
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //arm1
		glTranslatef(-0.75, 1.0, 0.0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)arm1, 0.0, 0.0, 1.0);  //����� �������� ȸ��
		glTranslatef(-0.25, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
		glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
			glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.5, 1.0, 1.0); //�������� ù ��° ����
				glutWireCube(1.0);
			glPopMatrix();
			glTranslatef(0.0, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)arm1_2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
			glTranslatef(0.0, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
			glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.5, 1.0, 1.0); //�������� �� ��° ����
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //arm2
		glTranslatef(0.75, 1.0, 0.0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)arm2, 0.0, 0.0, 1.0); //����� �������� ȸ��
		glTranslatef(0.25, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
		glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
			glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.5, 1.0, 1.0); //�������� ù ��° ����
				glutWireCube(1.0);
			glPopMatrix();
			glTranslatef(0.0, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)arm2_2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
			glTranslatef(0.0, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
			glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.5, 1.0, 1.0); //�������� �� ��° ����
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5, -1.0, 0.0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)leg1, 0.0, 0.0, 1.0); // ����� �������� ȸ��
		glTranslatef(0.0, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
		glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
			glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.3, 1.0, 1.0);
				glutWireCube(1.0); //���� �ٸ��� ������ش�
			glPopMatrix();
			glTranslatef(0.0, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)leg1_2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
			glTranslatef(0.0, -0.2, 0.0); // Pivot ���� �� ��ü �̵�
			glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.5, 0.4, 1.0); //�������� �� ��° ����
				glutWireCube(1.0);
			glPopMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
		glPopMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5, -1.0, 0.0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)leg2, 0.0, 0.0, 1.0); // ����� �������� ȸ��
		glTranslatef(0.0, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
		glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
			glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.3, 1.0, 1.0);
				glutWireCube(1.0); //������ �ٸ��� ������ش�
			glPopMatrix();
			glTranslatef(0.0, -0.5, 0.0); // Pivot ���� �� ��ü �̵�
			glRotatef((GLfloat)leg2_2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
			glTranslatef(0.0, -0.2, 0.0); // Pivot ���� �� ��ü �̵�
			glPushMatrix(); // ������ �������� ��ü ���� �� ��� Ȯ��
				glScalef(0.5, 0.4, 1.0); //�������� �� ��° ����
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glPopMatrix(); //�������� ���ư�
	glutSwapBuffers();
}

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void MyTimer_left(int Value) { //��Ŭ�� Ÿ�̸� �Լ�
	if (check1==0&&arm1 == 45 && arm1_2 == 45 && arm2 == 45 && arm2_2 == 45) //��� ������ 45���� �Ǹ�
		check1 = 1;
	if (check1 == 0 && arm1 < 45)
		arm1 = (arm1 + 5) % 180; //������ �����δ�
	if (check1 == 0 && arm1_2 < 45)
		arm1_2 = (arm1_2 + 5) % 180; //������ ������ �����δ�
	if (check1 == 0 && arm2 < 45)
		arm2 = (arm2 + 5) % 180; //�������� �����δ�
	if (check1 == 0 && arm2_2 < 45)
		arm2_2 = (arm2_2 + 5) % 180; //�������� ������ �����δ�
	if (check1 == 1 && arm1 == 0 && arm1_2 == 0 && arm2 == 0 && arm2_2 == 0) { //��� ������ 0���� �Ǹ�
		check1 = 0;
		return;
	}
	if (check1 == 1 && arm1 >0)
		arm1 = (arm1 - 5) % 180; //������ �����δ�
	if (check1 == 1 && arm1_2 > 0)
		arm1_2 = (arm1_2 - 5) % 180; //������ ������ �����δ�
	if (check1 == 1 && arm2 > 0)
		arm2 = (arm2 - 5) % 180; //�������� �����δ�
	if (check1 == 1 && arm2_2 > 0)
		arm2_2 = (arm2_2 - 5) % 180; //�������� ������ �����δ�
	glutPostRedisplay(); //�����
	glutTimerFunc(200, MyTimer_left, 1); //�ݹ��Լ� ���
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) { //���콺 ���ʹ�ư�� ����ä��
		glutTimerFunc(200, MyTimer_left, 1); //�ݹ��Լ� ���
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Can Robot");
	MyInit();
	glutDisplayFunc(MyDisplay); //���÷��� �Լ� ���
	glutReshapeFunc(MyReshape); //reshape�Լ� ���
	glutMouseFunc(MyMouseClick); //���콺Ŭ���Լ� ���
	glutMainLoop();
	return 0;
}