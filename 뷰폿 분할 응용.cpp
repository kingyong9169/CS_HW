/***************************************************/
/*              HW#7 : ���� ���� ����              */
/*  �ۼ��� : �赿��     ��¥ : 2020�� 11�� 24��    */
/*                                                 */
/* ���� ���� : Ű����, ���콺 �ݹ��� ����Ͽ�      */
/* ī�޶� �̵�, ȸ�� �� ũ������ �� �����ϵ��� �Ѵ�*/
/* ������ ũ�⸦ �������� �� �������� ũ�⿡       */
/* ������� ��ü�� ���°� �ְ���� �ʵ��� �Ѵ�     */
/*                - - - - - - -                    */
/***************************************************/

#include<gl/glut.h>

int Width, Height; //ȭ�� ���� ��, ����
GLfloat x=0.0, y=0.0, z=0.0; //ī�޶� ��ġ�� ���� ����
GLfloat fx= 0.0, fy= 0.0, fz= 0.0; //ī�޶� ������ ���� ����
GLfloat sx=0.0, sy= 0.0, sz= 0.0; //ũ�⿡ ���� ����
GLfloat Widthfactor, Heightfactor; //ȭ�� ���� ��, ������ ����

void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix(); //��� ����
		glTranslatef(0.0, -1.0, 0.0);
		glBegin(GL_QUADS); //���� �׸���
			glVertex3f(2.0, 0.0, 2.0); //������ ��ǥ��
			glVertex3f(2.0, 0.0, -2.0);
			glVertex3f(-2.0, 0.0, -2.0);
			glVertex3f(-2.0, 0.0, 2.0);
		glEnd();
	glPopMatrix(); //��� ��

	glColor3f(0.3, 0.3, 0.7); //���� ����
	glPushMatrix(); //�ٽ� ��� ����
		glTranslatef(0.0, 0.0, -0.5); //T(�̵�)
		glScalef(1.0 + sx, 1.0 + sy, 1.0 + sz); //S(ũ�� ��ȯ)
		glutWireTeapot(1.0); //Ƽ�� �׸���
	glPopMatrix(); //��� ��
	glColor3f(0.7, 0.3, 0.7); //���� ����
	glPushMatrix(); //�ٽ� ��� ����
		glTranslatef(0.0, 0.0, -1.5); //T(�̵�)
		glScalef(1.0 + sx, 1.0 + sy, 1.0 + sz); //S(ũ�� ��ȯ)
		glutWireTorus(0.3,0.8,30,30); //�䷯�� �׸���
	glPopMatrix(); //��� ��
}

void MyDisplay() { //���÷��� �Լ�
	glClearColor(1.0, 1.0, 1.0, 1.0); //��� �� �ʱ�ȭ
	glMatrixMode(GL_PROJECTION); //���� ����
	glLoadIdentity(); //�׵���ķ� �ʱ�ȭ
	glOrtho(-2.0 * Widthfactor, 2.0 * Widthfactor, -2.0 * Heightfactor, 2.0 * Heightfactor, 0.5, 5.0); //���ú��Ǹ� ȭ�� ������ ����

	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 1.0); //���� ����

	// ���ϴܺ���
	glViewport(0, 0, Width / 2, Height / 2); //�� ��ǥ�� ������ȯ
	glPushMatrix(); //��� ����
		gluLookAt(0.0+x, 0.0 + y, 1.0 + z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 1.0, 0.0); //�� ��ǥ�� ���� ��ȯ
		DrawScene(); //drawscene�Լ� ȣ��
	glPopMatrix(); //��� ��

	// ���ϴܺ���
	glViewport(Width / 2, 0, Width / 2, Height / 2); //�� ��ǥ�� ������ȯ
	glPushMatrix(); //��� ����
		gluLookAt(1.0 + x, -1.0 + y, 0.0 + z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 1.0, 0.0); //�� ��ǥ�� ���� ��ȯ
		DrawScene(); //drawscene�Լ� ȣ��
	glPopMatrix(); //��� ��

	// �»�ܺ���
	glViewport(0, Height / 2, Width / 2, Height / 2); //�� ��ǥ�� ������ȯ
	glPushMatrix(); //��� ����
		gluLookAt(0.0 + x, 1.0 + y, 0.0 + z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 0.0, -1.0); //�� ��ǥ�� ���� ��ȯ
		DrawScene(); //drawscene�Լ� ȣ��
	glPopMatrix(); //��� ��

	// ���ܺ���
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2); //�� ��ǥ�� ������ȯ
	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); //��� ����
		glLoadIdentity(); //�׵���ķ� �ʱ�ȭ
		gluPerspective(30, 1.0 * Widthfactor/Heightfactor, 3.0, 50.0);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix(); //��� ����
			gluLookAt(5.0+x, 5.0+y, 5.0+z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 1.0, 0.0); //�� ��ǥ�� ���� ��ȯ
			DrawScene(); //drawscene�Լ� ȣ��
		glPopMatrix(); //��� ��

		glMatrixMode(GL_PROJECTION);
	glPopMatrix(); //��� ��

	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) { //reshape �Լ�
	glViewport(0, 0, NewWidth, NewHeight); //���ο� ȭ�� ��ǥ�� ���� ��ȯ
	Width = NewWidth; //width�� ���ο� width ����
	Height = NewHeight; //height�� ���ο� height ����
	// �̺�Ʈ�����غ���Ʈ�����ӰԹ������οͼ��α��̷μ����մϴ�.
	Widthfactor = (GLfloat)NewWidth / (GLfloat)500; //���ο� width�� ����
	Heightfactor = (GLfloat)NewHeight / (GLfloat)500; //���ο� height�� ����
	// �̺�Ʈ�����ػ��ӰԹ������οͼ��θ����Ͽ��������������մϴ�.
}

void MySpecial(int key, int pos1, int pos2) { //ī�޶� ��ġ�� �ٲ���
	switch (key) {
	case GLUT_KEY_RIGHT: //������ ����Ű
		x += 0.1; //ī�޶��� ��ġx�� 0.1����
		break;
	case GLUT_KEY_LEFT: //���� ����Ű
		x -= 0.1; //ī�޶��� ��ġx�� 0.1����
		break;
	case GLUT_KEY_UP: //���� ����Ű
		y += 0.1; //ī�޶��� ��ġy�� 0.1����
		break;
	case GLUT_KEY_DOWN: //�Ʒ��� ����Ű
		y -= 0.1; //ī�޶��� ��ġy�� 0.1����
		break;
	}
	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int pos1, int pos2) { //ī�޶� ������ �ٲ���
	switch (key) {
	case 'a': //a, AŰ ������ 
	case 'A':
		fx += 0.1; //ī�޶� �ٶ󺸴� ���� x�� ��ġ�� 0.1����
		break;
	case 'f': //f, FŰ ������ 
	case 'F':
		fx -= 0.1; //ī�޶� �ٶ󺸴� ���� x�� ��ġ�� 0.1����
		break;
	case 'r': //r, RŰ ������
	case 'R':
		fy += 0.1; //ī�޶� �ٶ󺸴� ���� y�� ��ġ�� 0.1����
		break;
	case 'v': //b, BŰ ������
	case 'V':
		fy -= 0.1; //ī�޶� �ٶ󺸴� ���� y�� ��ġ�� 0.1����
		break;
	case 'z': //b, BŰ ������
	case 'Z':
		fz += 0.1; //ī�޶� �ٶ󺸴� ���� z�� ��ġ�� 0.1����
		break;
	case 't': //t, TŰ ������
	case 'T':
		fz -= 0.1; //ī�޶� �ٶ󺸴� ���� z�� ��ġ�� 0.1����
		break;
	}
	glutPostRedisplay(); //������ ���÷���
}


void MyIdle() {  //�ƹ� �̺�Ʈ�� ���� �ÿ� ����Ǵ� �ݹ��Լ��� �� �ȿ��� specialkeyboardcallback�� ����ϸ鼭 Ȱ����
	glutSpecialFunc(MySpecial); //�ݹ��Լ� ���
	glutPostRedisplay(); //������ ���÷���
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //������ ũ�⸦ �ٲ���
	if (Button == GLUT_LEFT_BUTTON) { //���콺 ���ʹ�ư�� ����ä��
		sx += 0.1; //xũ�� ����
		sy += 0.1; //yũ�� ����
		sz += 0.1; //zũ�� ����
	}
	else if (Button == GLUT_RIGHT_BUTTON) { //�ƴϸ�
		sx -= 0.1; //xũ�� ����
		sy -= 0.1; //yũ�� ����
		sz -= 0.1; //zũ�� ����
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	Width = 500;
	Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); //���÷��̸�带 �̱�, RGBA�� �ʱ�ȭ
	glutInitWindowSize(Width, Height); //������ ������ �ʱ�ȭ
	glutInitWindowPosition(0, 0); //window��ǥ �ʱ�ȭ
	glutCreateWindow("ViewporyPartition"); //���α׷� �̸�
	glutDisplayFunc(MyDisplay); //���÷��� �Լ� ���
	glutIdleFunc(MyIdle); //���̵� �Լ� ���
	glutKeyboardFunc(MyKeyboard); //Ű���� �Լ� ���
	glutMouseFunc(MyMouseClick); //���콺Ŭ���Լ� ���
	glutReshapeFunc(MyReshape); //reshape�ݹ� �Լ� ���
	glutMainLoop(); //�����Լ�
	return 0;
}