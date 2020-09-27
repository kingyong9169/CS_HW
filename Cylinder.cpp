/*#include<stdlib.h> //ǥ�� ���̺귯�� ����
#include<gl/glut.h> //glut ���̺귯�� ����

GLUquadricObj* qobj = gluNewQuadric(); //���ο� quadric object ����

int MyListID; //DisplayList�� ���� ID�� ���� �ĺ�

void MyCreateList() { //display list�Լ�
	MyListID = glGenLists(1); //DIsplayList ����
	//���̵� ���� ����Ʈ1���� ���� �����,
	//�������� �ʰ� ������ �Ϸ�� ������ �����.
	glNewList(MyListID, GL_COMPILE); //display list�� �����ϱ� ���� �Լ�

	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };//�ֺ���
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };//�ݻ籤
	GLfloat mat_shininess[] = { 50.0 };//����
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//������ġ
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; //���� �ֺ���

	glClearColor(0.0, 0.0, 0.0, 0.0); //���� ����
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); //�ֺ����� �����
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //�ݻ籤�� �����
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); //������ �����
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); //������ ��ġ�� �����ش�
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient); //������ ������ �����

	glEnable(GL_LIGHTING); //���� ��带 Ȱ��ȭ
	glEnable(GL_LIGHT0); //light0���� ����
	glEnable(GL_DEPTH_TEST); //���� ���۸� ������Ʈ

	glMatrixMode(GL_MODELVIEW); //�迭 ��带 �����Ѵ�(����� �𵨺並 ����)
	glLoadIdentity(); //���� �𵨺� ����� �ʱ�ȭ(���� ��ķ�)
	gluLookAt(0.5, 0.4, 1.4, 0.1, 0.0, -1.0, -5.0, -5.0, -5.0); //ī�޶� ����

	glShadeModel(GL_SMOOTH); //�� ������ ���� ������ �����Ͽ� ȥ���Ͽ� ĥ�ϰ� ����
	gluQuadricDrawStyle(qobj, GLU_LINE); //Quadric�� ���� ���ϴ� Draw Style ����
	gluQuadricNormals(qobj, GLU_SMOOTH); //�������� ����
	gluQuadricOrientation(qobj, GLU_OUTSIDE); //�������� ���� �� �ܺ� ��� ���� ���� ����
	gluQuadricTexture(qobj, GL_FALSE); //Texture ��ǥ ����� �������� ���� ����
	gluCylinder(qobj, 1.0, 0.3, 2.0, 20, 8); //�Ǹ����� �׸���.

	glEndList(); //����Ʈ ����
}

void MyDisplay() //display �ݹ� �Լ�
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�����ۿ� ���̹��۸� ����ش�.
	glCallList(MyListID); //�������� �Ϸ�� ����Ʈ�� ������ ����
	glutSwapBuffers(); //������ۿ� �ĸ���۸� ��°�� ��ü�Ѵ�.
}

void Reshape(int w, int h) { //������ â�� �������ÿ� ȣ��Ǵ� reshape �ݹ� �Լ�
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //������ ȭ���� ���ο� ũ��� ����
	glMatrixMode(GL_PROJECTION); //��ȯ ����� ������ȯ���� ����
	glLoadIdentity(); //��� �ʱ�ȭ

	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); //���� ���� ����
	glMatrixMode(GL_MODELVIEW); //�迭 ��带 �����Ѵ�(����� �𵨺並 ����)
	glLoadIdentity(); //��� �ʱ�ȭ
}

int main(int argc, char** argv) { //�����Լ�
	glutInit(&argc, argv); //glut ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //���÷��� ��� ����, ����2��, RGB, ���� ����
	glutInitWindowSize(800, 600); //������ ������ ����
	glutInitWindowSize(0, 0); //������ ���� �� ��ǥ(GLU��ǥ�� ���)
	glutCreateWindow("Cylinder"); //������ �̸� ����
	glutDisplayFunc(MyDisplay); //display �ݹ� �Լ� ���
	glutReshapeFunc(Reshape); //reshape �ݹ� �Լ� ���
	MyCreateList(); //DIsplay List����
	glutMainLoop(); //loop ����
	return 0;
}*/