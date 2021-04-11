/********************************************************/
/*                   HW#4 : Callback 프로그램-Idle 콜백 */
/*       작성자 : 김동용         날짜 : 2020년 10월 19일*/
/*                   문제 정의 : 방향키로 Idle콜백 구현 */
/*                     - - - - - - -                    */
/********************************************************/
#include <GL/glut.h>
GLfloat x1 = -0.5, x2 = 0.5, y1 = 0.5, y2 = -0.5; //도형 좌표

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON); //도형을 그려줌
	glVertex3f(x1, y1, 0.0); //도형의 좌표
	glVertex3f(x2, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x1, y2, 0.0);
	glEnd();
	glFlush();
}

void MySpecial(int key, int pos1, int pos2) {
	switch (key) {
	case GLUT_KEY_RIGHT: //오른쪽 방향키
		if (x2 >= 1.0f) { //도형의 오른쪽 x좌표가 1.0을 벗어나면
			x2 += 0.0; //그대로
			x1 += 0.0;
		}
		else { //아니면
			x2 += 0.1; //오른쪽으로 0.1이동 
			x1 += 0.1;
		}
		break;
	case GLUT_KEY_LEFT: //왼쪽 방향키
		if (x1 <= -1.0f) { //도형의 왼쪽 x좌표가 -1.0을 벗어나면
			x2 -= 0.0; //그대로
			x1 -= 0.0;
		}
		else { //아니면
			x2 -= 0.1; //왼쪽으로 0.1이동
			x1 -= 0.1;
		}
		break;
	case GLUT_KEY_UP: //위쪽 방향키
		if (y1 >= 1.0f) { //도형의 위쪽 y좌표가 1.0을 벗어나면
			y1 += 0.0; //그대로
			y2 += 0.0;
		}
		else {
			y1 += 0.1;
			y2 += 0.1;
		}
		break;
	case GLUT_KEY_DOWN:
		if (y2 <= -1.0f) { //도형의 아래쪽 y좌표가 1.0을 벗어나면
			y2 -= 0.0; //그대로
			y1 -= 0.0;
		}
		else {
			y2 -= 0.1; //아래쪽으로 -0.1이동
			y1 -= 0.1;
		}
		break;
	}
	glutPostRedisplay();
}

void MyIdle() {  //아무 이벤트가 없을 시에 실행되는 콜백함수로 이 안에서 specialkeyboardcallback을 등록하면서 활용함
	glutSpecialFunc(MySpecial); //콜백함수 등록
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay); //디스플레이 함수등록
	glutIdleFunc(MyIdle); //아이들 함수등록
	glutMainLoop();
	return 0;
}