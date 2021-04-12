/********************************************************/
/*               HW#4 : Callback ���α׷�-���콺�ݹ�(2) */
/*       �ۼ��� : �赿��         ��¥ : 2020�� 10�� 19��*/
/*              ���� ���� : ���콺 Ŭ������ ���� �׸��� */
/*                     - - - - - - -                    */
/********************************************************/
#include< GL/glut.h>
GLboolean IsSphere = true; //sphere, torus, teapot, small���θ� �˷��ִ� ����
GLboolean IsTorus = true;
GLboolean IsTeapot= true;
GLboolean IsSmall = true;

GLfloat R=1.0, G=0.0, B=0.0;
void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(R, G, B);

	if ((IsSphere) && (IsSmall)&& (!IsTeapot)&& (!IsTorus)) // small sphere�̸�
		glutWireSphere(0.5, 30, 30); //small shpere���
	else if ((IsSphere) && (!IsSmall)&&(!IsTeapot) && (!IsTorus)) // large sphere�̸�
		glutWireSphere(0.7, 30, 30); // large sphere���
	else if ((IsTorus) && (IsSmall)&&(!IsSphere) && (!IsTeapot)) // small torus�̸�
		glutWireTorus(0.1, 0.3, 40, 20); // small torus���
	else if ((IsTorus) && (!IsSmall) && (!IsSphere) && (!IsTeapot)) // large torus�̸�
		glutWireTorus(0.2, 0.5, 40, 20); // large torus���
	else if (IsTeapot && (IsSmall) && (!IsSphere) && (!IsTorus)) // small teapot�̸�
		glutWireTeapot(0.3);  // small teapot���
	else if (IsTeapot && (!IsSmall) && (!IsSphere) && (!IsTorus)) // large teapot�̸�
		glutWireTeapot(0.5); // large teapot���
	glFlush();
}

void MySphereMenu(int entryID) { //sphere�޴�
	if (entryID == 1) { IsSphere = true; IsTeapot = false; IsTorus = false; IsSmall = true; } //small sphere
	else if (entryID == 2) { IsSphere = true; IsTeapot = false; IsTorus = false; IsSmall = false;} //large sphere
	glutPostRedisplay();
}

void MyTorusMenu(int entryID) { //torus�޴�
	if (entryID == 1) { IsSphere = false; IsTeapot = false; IsTorus = true; IsSmall = true; } //small torus
	else if (entryID == 2) { IsSphere = false; IsTeapot = false; IsTorus = true; IsSmall = false; } //large torus
	glutPostRedisplay();
}

void MyTeapotMenu(int entryID) { //teapot�޴�
	if (entryID == 1) { IsSphere = false; IsTeapot = true; IsTorus = false; IsSmall = true; } //small teapot
	else if (entryID == 2) { IsSphere = false; IsTeapot = true; IsTorus = false; IsSmall = false; } //large teapot
	glutPostRedisplay();
}

void MyMainMenu(int entryID) { //���θ޴�
	if (entryID == 4) exit(0); //exit�� �߰�����
	glutPostRedisplay();
}

void MyColorMenu(int entryID) { //�÷��޴�
	if (entryID == 1) { R = 1.0, G = 0.0, B = 0.0; } //����������
	else if (entryID == 2) { R = 0.0, G = 1.0, B = 0.0; } //�ʷϻ�����
	else if (entryID == 3) { R = 0.0, G = 0.0, B = 1.0; } //�Ķ�������
	glutPostRedisplay();
}

void MyInit(){ //�޴� �ʱ�ȭ
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	
	GLint MySphereID = glutCreateMenu(MySphereMenu); //sphere�޴�
	glutAddMenuEntry(" Small Sphere", 1);
	glutAddMenuEntry(" large Sphere", 2);

	GLint MyTorusID = glutCreateMenu(MyTorusMenu); //torus �޴�
	glutAddMenuEntry(" Small Torus", 1);
	glutAddMenuEntry(" large Torus", 2);

	GLint MyTeapotID = glutCreateMenu(MyTeapotMenu); //teapot�޴�
	glutAddMenuEntry(" Small Teapot", 1);
	glutAddMenuEntry(" large Teapot", 2);

	GLint MyColorID = glutCreateMenu(MyColorMenu); //color�޴�
	glutAddMenuEntry(" Red", 1);
	glutAddMenuEntry(" Green", 2);
	glutAddMenuEntry(" Blue", 3);
	
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //���θ޴� ���
	glutAddSubMenu(" Draw Sphere", MySphereID); //����޴��� ���
	glutAddSubMenu(" Draw Torus", MyTorusID); //����޴��� ���
	glutAddSubMenu(" Draw Teapot", MyTeapotID); //����޴��� ���
	glutAddSubMenu(" Change Color", MyColorID); //����޴��� ���
	glutAddMenuEntry(" Exit", 4); //���θ޴��� exit���
	glutAttachMenu(GLUT_RIGHT_BUTTON); //������ ���콺 Ŭ���ϸ� �޴� �˾�
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Menu Callback");
	MyInit();
	glutDisplayFunc(MyDisplay); //���÷��� �Լ� ���
	glutMainLoop();
	return 0;
}