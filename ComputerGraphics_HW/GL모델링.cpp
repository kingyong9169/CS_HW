#include <GL/glut.h> //openGL Utility Toolkit ���̺귯���� ����

void Points() { //���� �׸��� �Լ�
	GLfloat Size[2], Angle; //���� ũ��� ���� ��ġ�� ���� ����
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //���� ������ ���Ѵ�
	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
	glPointSize(Size[0] * 10); //���� ũ�⸦ 10�� ���Ѵ�
	glBegin(GL_POINTS); //�� vertex���� �ϳ��� point�� ǥ���Ѵ�.
	glVertex3f(0.2, 0.5, 0.0); //���� ��ǥ
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void Lines() { //���� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 5.0, 5.0); //���� ������ ���Ѵ�.
	glBegin(GL_LINES); //vertex���� �� ���� ��� line�� �����.
	glVertex3f(0.0, 0.5, 0.0); //�·�1
	glVertex3f(-0.5, 0.25, 0.0); //�·�2
	glVertex3f(-0.5, -0.25, 0.0); //�·�3
	glVertex3f(0.0, -0.5, 0.0); //�·�4
	glVertex3f(0.5, -0.25, 0.0); //�·�5
	glVertex3f(0.5, 0.25, 0.0); //�·�6
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void LineStrip() { //�� strip�� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //������ �� ����
	glBegin(GL_LINE_STRIP); //line���� �� �ٷ� �����Ѵ�.
	glVertex3f(0.0, 0.5, 0.0); //��ǥ1
	glVertex3f(-0.5, 0.25, 0.0); //��ǥ2
	glVertex3f(-0.5, -0.25, 0.0); //��ǥ3
	glVertex3f(0.0, -0.5, 0.0); //��ǥ4
	glVertex3f(0.5, -0.25, 0.0); //��ǥ5
	glVertex3f(0.5, 0.25, 0.0); //��ǥ6
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void LineLoop() { //��loop�� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //������ �� ����
	glBegin(GL_LINE_LOOP); //������ vertex�� ù ���� vertex�� �����ϴ� line�� �߰��� GL_LINE_STRIP
	glVertex3f(0.0, 0.5, 0.0); //��ǥ1
	glVertex3f(-0.5, 0.25, 0.0); //��ǥ2
	glVertex3f(-0.5, -0.25, 0.0); //��ǥ3
	glVertex3f(0.0, -0.5, 0.0); //��ǥ4
	glVertex3f(0.5, -0.25, 0.0); //��ǥ5
	glVertex3f(0.5, 0.25, 0.0); //��ǥ6
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void TriangleFan() { //�ﰢ��fan�� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //������ �� ����
	glBegin(GL_TRIANGLE_FAN); //�ﰢ������ ��ä ������� �����Ѵ�.
	glVertex3f(0.0, 0.0, 0.0); //��ǥ1
	glVertex3f(-0.5, 0.25, 0.0); //��ǥ2
	glVertex3f(-0.5, -0.25, 0.0); //��ǥ3
	glVertex3f(0.0, -0.5, 0.0); //��ǥ4
	glVertex3f(0.5, -0.25, 0.0); //��ǥ5
	glVertex3f(0.5, 0.25, 0.0); //��ǥ6
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void Triangles() { //�ﰢ���� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //������ �� ����
	glBegin(GL_TRIANGLES); //�� ���� vertex�� ��� �ﰢ���� �����.
	glVertex3f(0.0, 0.0, 0.0); //��ǥ1
	glVertex3f(-0.5, 0.25, 0.0); //��ǥ2
	glVertex3f(-0.5, -0.25, 0.0); //��ǥ3
	glVertex3f(0.0, -0.5, 0.0); //��ǥ4
	glVertex3f(0.5, -0.25, 0.0); //��ǥ5
	glVertex3f(0.5, 0.25, 0.0); //��ǥ6
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void TriangleStrip() { //�ﰢ��strip�� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //������ �� ����
	glBegin(GL_TRIANGLE_STRIP); //�ﰢ������ ��� �����Ѵ�
	glVertex3f(0.0, 0.0, 0.0); //��ǥ1
	glVertex3f(-0.5, 0.25, 0.0); //��ǥ2
	glVertex3f(-0.5, -0.25, 0.0); //��ǥ3
	glVertex3f(0.0, -0.5, 0.0); //��ǥ4
	glVertex3f(0.5, -0.25, 0.0); //��ǥ5
	glVertex3f(0.5, 0.25, 0.0); //��ǥ6
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void Polygons() { //polygon�� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //������ �� ����
	glBegin(GL_POLYGON); //�ܼ�, ��� polygon
	glVertex3f(0.0, 0.5, 0.0); //��ǥ1
	glVertex3f(-0.5, 0.25, 0.0); //��ǥ2
	glVertex3f(-0.5, -0.25, 0.0); //��ǥ3
	glVertex3f(0.0, -0.5, 0.0); //��ǥ4
	glVertex3f(0.5, -0.25, 0.0); //��ǥ5
	glVertex3f(0.5, 0.25, 0.0); //��ǥ6
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void Quads() { //quad�� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //������ �� ����
	glBegin(GL_QUADS); //vertex���� �� ���� ��� ���� �� ���� �𼭸��� ���� polygon�� �����.
	glVertex3f(0.0, 0.5, 0.0); //��ǥ1
	glVertex3f(-0.5, 0.25, 0.0); //��ǥ2
	glVertex3f(-0.5, -0.25, 0.0); //��ǥ3
	glVertex3f(0.0, -0.5, 0.0); //��ǥ4
	glVertex3f(0.5, -0.25, 0.0); //��ǥ5
	glVertex3f(0.5, 0.25, 0.0); //��ǥ6
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

void QuadStrip() { //quadstrip�� �׸��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT); //�� ���� ����
	glColor3f(1.0, 1.0, 1.0); //������ �� ����
	glBegin(GL_QUAD_STRIP); //�簢������ ��� �����Ѵ�.
	glVertex3f(0.0, 0.5, 0.0); //��ǥ1
	glVertex3f(-0.5, 0.25, 0.0); //��ǥ2
	glVertex3f(-0.5, -0.25, 0.0); //��ǥ3 
	glVertex3f(0.0, -0.5, 0.0); //��ǥ4
	glVertex3f(0.5, -0.25, 0.0); //��ǥ5
	glVertex3f(0.5, 0.25, 0.0); //��ǥ6
	glVertex3f(0.1, 0.0, 0.0); //��ǥ7
	glVertex3f(0.5, 0.1, 0.0); //��ǥ8
	glEnd(); //GL�� ��ħ
	glFlush(); //ť �����ϱ� : ���� ������� ���� ����� ����ǵ��� ��
}

int main(int argc, char** argv) { //�����Լ�
	glutInit(&argc, argv); //window os�� session ����, GLUT Library�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB); //Display Mode ����
	glutInitWindowSize(500, 500); //window�� ũ�� ����
	glutCreateWindow("My First OpenGL Code"); //���ο� window����
	glutDisplayFunc(QuadStrip); //�ش� �Լ��� ����
	glutMainLoop(); //GLUT Eventó�� Loop �Է�
	return 0;
}