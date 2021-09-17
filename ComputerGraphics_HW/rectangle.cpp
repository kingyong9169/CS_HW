#include<GL/glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, -30.0);
	glVertex3f(100.0, 0.0, -30.0);
	glVertex3f(100.0, 100.0, -30.0);
	glVertex3f(0.0, 100.0, -30.0);
	glEnd();
	glFlush();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// 투영행렬선택
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// 현재투영행렬을항등행렬로초기화
	// 행렬변환: 평면투영
	//glOrtho(0.0, 20.0, 0.0, 20.0, 10.0, 50.0);
	glOrtho(0.0, 500.0, 0.0, 500.0, 10.0, 50.0);
	// 모델뷰행렬선택
	// MODEL_VIEW의행렬에따라그려지는위치가다름
	glMatrixMode(GL_MODELVIEW);
	// 현재모델뷰행렬을항등행렬로초기화
	glLoadIdentity(); //단위행렬(초기행렬)로 초기화
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
