#include<GL/glut.h> //glut�ҷ�����
#include<stdlib.h>// rand() �Լ����뵵

/***************************************************/
/*                        HW#3 : 3D ������ ���α׷�*/
/*  �ۼ��� : �赿��         ��¥ : 2020�� 10�� 07��*/
/* ���� ���� : 2D�� 3D�� 3-3������ ���α׷� ����� */
/*                - - - - - - -                    */
/***************************************************/

void MyReshape(int NewWidth, int NewHeight) { //Reshape callback�� ���� �ְ� ���� �ذ�
	glViewport(0, 0, NewWidth, NewHeight); //�׸��� �׷����� ���÷��� ��ġ������ �簢 ����
	// �̺�Ʈ�����غ���Ʈ�����ӰԹ������οͼ��α��̷μ����մϴ�.
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)300;
	// �̺�Ʈ�����ػ��ӰԹ������οͼ��θ����Ͽ��������������մϴ�.
	glMatrixMode(GL_PROJECTION); //���� ��� ����
	glLoadIdentity(); //������ķ� �ʱ�ȭ
	glMatrixMode(GL_MODELVIEW); //�𵨺� ��� ����
	glLoadIdentity(); //������ķ� �ʱ�ȭ
	glOrtho(-100.0 * Widthfactor, 500.0 * Widthfactor, -100.0 * Heightfactor, 500.0 * Heightfactor, 500.0, -500.0); //�������� ��ȯ �Լ�
	//���� ���� ���� ���ú��ǰ� ���ϹǷ� ȸ�� ���� ����
	glRotatef(10.0, 1.0, 0.0, 0.0); //x������ 10�� ȸ��
	glRotatef(30.0, 0.0, 1.0, 0.0); //y������ 30�� ȸ��
}

void MyDisplay(void) //���÷����Լ�
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // �Ͼ������μ���
	glColor3f(0.0, 0.0, 0.0); // ���������μ���
	float vertices[4][3] = { { 0.0,0.0 },{ 250.0,500.0 },
		{ 500.0,0.0 }, {0.0,0.0,500.0} }; //�ʱ⼼��
	int i, j;
	float p[3] = { 50.0, 50.0, 50.0 }; // ���� ����Ʈ
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�����ۿ� ���̹��۸� ����ش�.
	
	for (j = 0; j < 50000; j++) //50000�� �ݺ�
	{
		i = rand() % 4; // ������������. 0-3�ǰ�
		
		p[0] = (p[0] + vertices[i][0]) / 2.0;
		p[1] = (p[1] + vertices[i][1]) / 2.0;
		p[2] = (p[2] + vertices[i][2]) / 2.0;
		// ���μ��õ��������������������λ��ο�����ġ���( ��������ġ���)
		glBegin(GL_POINTS); //������ glbegin
		glVertex3fv(p); // ������ġ�������
		glEnd(); //glend
	}
	glFlush(); //������� ���� �͵��� ���� �� ��������ش�.
}

void main(int argc, char** argv) //�����Լ�
{
	glutInit(&argc, argv); //glut ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //���÷��̸�� �ʱ�ȭ
	glutInitWindowSize(500, 500); //������ ȭ�� ũ�� �ʱ�ȭ
	glutInitWindowPosition(0, 0); //������������ �ʱ�ȭ
	glutCreateWindow("SierpinskiGasket"); //���α׷� ����
	glutDisplayFunc(MyDisplay); //���÷��� �ݹ��Լ����
	glutReshapeFunc(MyReshape); // reshape �ݹ��Լ����
	glutMainLoop(); //���η��� ����
}