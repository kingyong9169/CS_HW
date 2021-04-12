/********************************************************/
/*               HW#4 : Callback 프로그램-마우스콜백(1) */
/*       작성자 : 김동용         날짜 : 2020년 10월 19일*/
/*                문제 정의 : 마우스 클릭으로 콜백 구현 */
/*                     - - - - - - -                    */
/********************************************************/
#include <GL/glut.h>
GLfloat x1 = -0.5, x2 = 0.5, y1 = 0.5, y2 = -0.5; //도형 좌표
GLboolean Check = true;

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //가시부피
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON); //도형그리기
	glVertex3f(x1, y1, 0.0); //도형 좌표
	glVertex3f(x2, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x1, y2, 0.0);
	glEnd();
	glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y ){
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) //마우스 왼쪽버튼이 눌린채로
		Check = false; //check=false
	else //아니면
		Check = true; //check=true
}

void MyTimer(int Value) {
	if (!Check) { //체크가 false이면
		if (x2 >= 1.0f) { //x2가 1.0보다 크거나 작으면 즉, 벽에 부딪히면
			x2 += 0.0; //그대로
			x1 += 0.0;
		}
		else { //아니면
			x2 += 0.1; //오른쪽으로 이동
			x1 += 0.1;
		}
	}

	glutPostRedisplay(); //재출력
	glutTimerFunc(200, MyTimer, 1); //콜백함수 등록
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay); //디스플레이함수 등록
	glutTimerFunc(200, MyTimer, 1); //콜백함수 등록
	glutMouseFunc(MyMouseClick ); //마우스클릭함수 등록
	glutMainLoop();
	return 0;
}