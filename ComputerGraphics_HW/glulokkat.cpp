/***************************************************/
/*        HW#5-4 : gluLookAt()�� �ǽð� ����       */
/*  �ۼ��� : �赿��     ��¥ : 2020�� 11�� 10��    */
/*                                                 */
/* ���� ���� : ���� ��ǥ�踦 keyboard callback�Լ��� �ǽð� ��� �����ϵ��� ����*/
/*                - - - - - - -                    */
/***************************************************/

#include <gl/glut.h>

GLfloat x=0, y=3.5; //���������� ī�޶��� ��ġx,y����
GLfloat fx = 0, fy = 0, fz = 0; //���������� ������ ��ġ fx,fy,fz����
void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON); //�ٰ����� �׸���
	glVertex3f(-2.0, -0.71, 2.0); //�� 4��
	glVertex3f(2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, -2.0);
	glVertex3f(-2.0, -0.71, -2.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES); //���� �׸���
	for(float a = -2.0; a <= 2.2; a += 0.2) { //�� 21���� �׸���
		glVertex3f(a, -0.7, -2.0);
		glVertex3f(a, -0.7, 2.0);
	}
	for(float b = -2.0; b <= 2.2; b += 0.2) { //�� 21���� �׸���
		glVertex3f(-2.0,- 0.7, b);
		glVertex3f(2.0,-0.7, b);
	}
	glEnd();
}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, 3.5, fx, fy, fz, 0.0, 1.0, 0.0); //���� ��ǥ�迡���� ī�޶� ����
	//gluLookAt(-1.0, 0.5, 3.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawGround(); //�ٴ��� �׷���
	glColor3f(1.0, 1.0, 0.0);
	glutWireTeapot(1.0); //Ƽ���� �׷���
	glFlush();
}

void MySpecial(int key, int pos1, int pos2) {
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

void MyKeyboard(unsigned char key, int pos1, int pos2) {
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
	case 't':
	case 'T':
		fz -= 0.1; //ī�޶� �ٶ󺸴� ���� z�� ��ġ�� 0.1����
		break;
	}
	glutPostRedisplay();
}

void MyReshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
}

void MyIdle() {  //�ƹ� �̺�Ʈ�� ���� �ÿ� ����Ǵ� �ݹ��Լ��� �� �ȿ��� specialkeyboardcallback�� ����ϸ鼭 Ȱ����
	glutSpecialFunc(MySpecial); //�ݹ��Լ� ���
	glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("VCS (View Coordinate System)");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay); //���÷��� �Լ����
	glutReshapeFunc(MyReshape); //reshape �Լ����
	glutIdleFunc(MyIdle); //���̵� �Լ����
	glutKeyboardFunc(MyKeyboard); //Ű���� �Լ� ���
	glutMainLoop();
	return 0;
}