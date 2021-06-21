/***************************************************/
/*          HW#4 : Callback 프로그램-키보드콜백(1) */
/*  작성자 : 김동용         날짜 : 2020년 10월 19일*/
/*   문제 정의 : a, f, r, v, b키로 키보드콜백 구현 */
/*                - - - - - - -                    */
/***************************************************/
#include <GL/glut.h>
GLfloat x, y;
GLfloat r=0.5, g=0.5, b=0.5; //r,g,b정보 저장
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //가시부피 설정
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON); //도형 그려줌
	glVertex3f(-0.5 + x, -0.5 + y, 0.0); //도형 좌표
	glVertex3f(0.5 + x, -0.5 + y, 0.0);
	glVertex3f(0.5 + x, 0.5 + y, 0.0);
	glVertex3f(-0.5 + x, 0.5 + y, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int pos1, int pos2) {
	switch (key) {
	case 'a': //a, A키 누르면 왼쪽으로 0.1씩 이동
	case 'A':
		x = x - 0.1f;
		break;
	case 'f': //f, F키 누르면 오른쪽으로 0.1씩 이동
	case 'F':
		x = x + 0.1f;
		break;
	case 'r': //r, R키 누르면 아래쪽으로 0.1씩 이동
	case 'R':
		y = y + 0.1f;
		r = 1.0; g = 0.0; b = 0.0;
		break;
	case 'v': //b, B키 누르면 위쪽으로 0.1씩 이동
	case 'V':
		y = y - 0.1f;
		break;
	case 'b': //b, B키 누르면 파란색으로 도형 칠함
	case 'B':
		r = 0.0; g = 0.0; b = 1.0;
		break;
	case 'q':
	case 'Q':
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay); //디스플레이 콜백함수 등록
	glutKeyboardFunc(MyKeyboard); //키보드 함수 등록
	glutMainLoop();
	return 0;
}