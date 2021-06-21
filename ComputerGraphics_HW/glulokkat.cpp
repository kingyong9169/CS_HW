/***************************************************/
/*        HW#5-4 : gluLookAt()의 실시간 제어       */
/*  작성자 : 김동용     날짜 : 2020년 11월 10일    */
/*                                                 */
/* 문제 정의 : 시점 좌표계를 keyboard callback함수로 실시간 제어가 가능하도록 구현*/
/*                - - - - - - -                    */
/***************************************************/

#include <gl/glut.h>

GLfloat x=0, y=3.5; //전역변수로 카메라의 위치x,y선언
GLfloat fx = 0, fy = 0, fz = 0; //전역변수로 초점의 위치 fx,fy,fz선언
void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON); //다각형을 그린다
	glVertex3f(-2.0, -0.71, 2.0); //점 4개
	glVertex3f(2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, -2.0);
	glVertex3f(-2.0, -0.71, -2.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES); //선을 그린다
	for(float a = -2.0; a <= 2.2; a += 0.2) { //선 21개를 그린다
		glVertex3f(a, -0.7, -2.0);
		glVertex3f(a, -0.7, 2.0);
	}
	for(float b = -2.0; b <= 2.2; b += 0.2) { //선 21개를 그린다
		glVertex3f(-2.0,- 0.7, b);
		glVertex3f(2.0,-0.7, b);
	}
	glEnd();
}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, 3.5, fx, fy, fz, 0.0, 1.0, 0.0); //세상 좌표계에서의 카메라 설정
	//gluLookAt(-1.0, 0.5, 3.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawGround(); //바닥을 그려줌
	glColor3f(1.0, 1.0, 0.0);
	glutWireTeapot(1.0); //티팟을 그려줌
	glFlush();
}

void MySpecial(int key, int pos1, int pos2) {
	switch (key) {
	case GLUT_KEY_RIGHT: //오른쪽 방향키
		x += 0.1; //카메라의 위치x를 0.1증가
		break;
	case GLUT_KEY_LEFT: //왼쪽 방향키
		x -= 0.1; //카메라의 위치x를 0.1감소
		break;
	case GLUT_KEY_UP: //위쪽 방향키
		y += 0.1; //카메라의 위치y를 0.1증가
		break;
	case GLUT_KEY_DOWN: //아래쪽 방향키
		y -= 0.1; //카메라의 위치y를 0.1감소
		break;
	}
	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int pos1, int pos2) {
	switch (key) {
	case 'a': //a, A키 누르면 
	case 'A':
		fx += 0.1; //카메라가 바라보는 초점 x의 위치를 0.1증가
		break;
	case 'f': //f, F키 누르면 
	case 'F':
		fx -= 0.1; //카메라가 바라보는 초점 x의 위치를 0.1감소
		break;
	case 'r': //r, R키 누르면
	case 'R':
		fy += 0.1; //카메라가 바라보는 초점 y의 위치를 0.1증가
		break;
	case 'v': //b, B키 누르면
	case 'V':
		fy -= 0.1; //카메라가 바라보는 초점 y의 위치를 0.1감소
		break;
	case 'z': //b, B키 누르면
	case 'Z':
		fz += 0.1; //카메라가 바라보는 초점 z의 위치를 0.1증가
		break;
	case 't':
	case 'T':
		fz -= 0.1; //카메라가 바라보는 초점 z의 위치를 0.1감소
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

void MyIdle() {  //아무 이벤트가 없을 시에 실행되는 콜백함수로 이 안에서 specialkeyboardcallback을 등록하면서 활용함
	glutSpecialFunc(MySpecial); //콜백함수 등록
	glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("VCS (View Coordinate System)");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay); //디스플레이 함수등록
	glutReshapeFunc(MyReshape); //reshape 함수등록
	glutIdleFunc(MyIdle); //아이들 함수등록
	glutKeyboardFunc(MyKeyboard); //키보드 함수 등록
	glutMainLoop();
	return 0;
}