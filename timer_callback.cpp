/********************************************************/
/*                 HW#4 : Callback 프로그램-타이머 콜백 */
/*       작성자 : 김동용         날짜 : 2020년 10월 19일*/
/*                문제 정의 : 타이머로 도형 색상 바꾸기 */
/*                     - - - - - - -                    */
/********************************************************/
#include<GL/glut.h>
#include<stdlib.h>
#include<time.h>
GLfloat Delta1 = 0.0, Delta2 = 0.0, Delta3 = 0.0;
void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(Delta1,Delta2,Delta3); //Delta를 좌표로하여 색깔을 계속 바꿔줌
	glVertex3f(-1.0, -0.5, 0.0); //사각형 그리기
	glVertex3f(0.0,-0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-1.0, 0.5, 0.0);
	glEnd();
	glutSwapBuffers(); //버퍼 바꾸기
}

void MyTimer(int Value){
	srand((unsigned)time(NULL));
	Delta1 = (rand() % 20); //Delta1변수 최신화
	Delta1 /= 25;
	Delta2 = (rand() % 20); //Delta2변수 최신화
	Delta2 /= 25;
	Delta3 = (rand() % 20); //Delta3변수 최신화
	Delta3 /= 25;

	glutPostRedisplay(); //재출력
	glutTimerFunc(400, MyTimer, 1); //콜백함수 등록
}

void MyInit(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Idle Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(400, MyTimer, 1); //콜백함수 등록
	glutMainLoop();
	return 0;
}