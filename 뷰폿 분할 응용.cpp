/***************************************************/
/*              HW#7 : 뷰폿 분할 응용              */
/*  작성자 : 김동용     날짜 : 2020년 11월 24일    */
/*                                                 */
/* 문제 정의 : 키보드, 마우스 콜백을 사용하여      */
/* 카메라 이동, 회전 및 크기조절 등 제어하도록 한다*/
/* 윈도우 크기를 변경했을 때 윈도우의 크기에       */
/* 상관없이 객체의 형태가 왜곡되지 않도록 한다     */
/*                - - - - - - -                    */
/***************************************************/

#include<gl/glut.h>

int Width, Height; //화면 상의 폭, 높이
GLfloat x=0.0, y=0.0, z=0.0; //카메라 위치에 대한 변수
GLfloat fx= 0.0, fy= 0.0, fz= 0.0; //카메라 초점에 대한 변수
GLfloat sx=0.0, sy= 0.0, sz= 0.0; //크기에 대한 변수
GLfloat Widthfactor, Heightfactor; //화면 상의 폭, 높이의 비율

void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix(); //행렬 삽입
		glTranslatef(0.0, -1.0, 0.0);
		glBegin(GL_QUADS); //장판 그리기
			glVertex3f(2.0, 0.0, 2.0); //장판의 좌표들
			glVertex3f(2.0, 0.0, -2.0);
			glVertex3f(-2.0, 0.0, -2.0);
			glVertex3f(-2.0, 0.0, 2.0);
		glEnd();
	glPopMatrix(); //행렬 팝

	glColor3f(0.3, 0.3, 0.7); //색상 변경
	glPushMatrix(); //다시 행렬 삽입
		glTranslatef(0.0, 0.0, -0.5); //T(이동)
		glScalef(1.0 + sx, 1.0 + sy, 1.0 + sz); //S(크기 변환)
		glutWireTeapot(1.0); //티팟 그리기
	glPopMatrix(); //행렬 팝
	glColor3f(0.7, 0.3, 0.7); //색상 변경
	glPushMatrix(); //다시 행렬 삽입
		glTranslatef(0.0, 0.0, -1.5); //T(이동)
		glScalef(1.0 + sx, 1.0 + sy, 1.0 + sz); //S(크기 변환)
		glutWireTorus(0.3,0.8,30,30); //토러스 그리기
	glPopMatrix(); //행렬 팝
}

void MyDisplay() { //디스플레이 함수
	glClearColor(1.0, 1.0, 1.0, 1.0); //배경 색 초기화
	glMatrixMode(GL_PROJECTION); //평행 투영
	glLoadIdentity(); //항등행렬로 초기화
	glOrtho(-2.0 * Widthfactor, 2.0 * Widthfactor, -2.0 * Heightfactor, 2.0 * Heightfactor, 0.5, 5.0); //가시부피를 화면 비율로 설정

	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 1.0); //색상 지정

	// 좌하단뷰폿
	glViewport(0, 0, Width / 2, Height / 2); //이 좌표로 뷰폿변환
	glPushMatrix(); //행렬 삽입
		gluLookAt(0.0+x, 0.0 + y, 1.0 + z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 1.0, 0.0); //이 좌표로 시점 변환
		DrawScene(); //drawscene함수 호출
	glPopMatrix(); //행렬 팝

	// 우하단뷰폿
	glViewport(Width / 2, 0, Width / 2, Height / 2); //이 좌표로 뷰폿변환
	glPushMatrix(); //행렬 삽입
		gluLookAt(1.0 + x, -1.0 + y, 0.0 + z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 1.0, 0.0); //이 좌표로 시점 변환
		DrawScene(); //drawscene함수 호출
	glPopMatrix(); //행렬 팝

	// 좌상단뷰폿
	glViewport(0, Height / 2, Width / 2, Height / 2); //이 좌표로 뷰폿변환
	glPushMatrix(); //행렬 삽입
		gluLookAt(0.0 + x, 1.0 + y, 0.0 + z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 0.0, -1.0); //이 좌표로 시점 변환
		DrawScene(); //drawscene함수 호출
	glPopMatrix(); //행렬 팝

	// 우상단뷰폿
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2); //이 좌표로 뷰폿변환
	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); //행렬 삽입
		glLoadIdentity(); //항등행렬로 초기화
		gluPerspective(30, 1.0 * Widthfactor/Heightfactor, 3.0, 50.0);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix(); //행렬 삽입
			gluLookAt(5.0+x, 5.0+y, 5.0+z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 1.0, 0.0); //이 좌표로 시점 변환
			DrawScene(); //drawscene함수 호출
		glPopMatrix(); //행렬 팝

		glMatrixMode(GL_PROJECTION);
	glPopMatrix(); //행렬 팝

	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) { //reshape 함수
	glViewport(0, 0, NewWidth, NewHeight); //새로운 화면 좌표로 뷰폿 변환
	Width = NewWidth; //width에 새로운 width 대입
	Height = NewHeight; //height에 새로운 height 대입
	// 이벤트를통해뷰포트를새롭게받은가로와세로길이로설정합니다.
	Widthfactor = (GLfloat)NewWidth / (GLfloat)500; //새로운 width의 비율
	Heightfactor = (GLfloat)NewHeight / (GLfloat)500; //새로운 height의 비율
	// 이벤트를통해새롭게받은가로와세로를통하여비율을새로정합니다.
}

void MySpecial(int key, int pos1, int pos2) { //카메라 위치를 바꿔줌
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

void MyKeyboard(unsigned char key, int pos1, int pos2) { //카메라 초점을 바꿔줌
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
	case 't': //t, T키 누르면
	case 'T':
		fz -= 0.1; //카메라가 바라보는 초점 z의 위치를 0.1감소
		break;
	}
	glutPostRedisplay(); //강제로 디스플레이
}


void MyIdle() {  //아무 이벤트가 없을 시에 실행되는 콜백함수로 이 안에서 specialkeyboardcallback을 등록하면서 활용함
	glutSpecialFunc(MySpecial); //콜백함수 등록
	glutPostRedisplay(); //강제로 디스플레이
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //도형의 크기를 바꿔줌
	if (Button == GLUT_LEFT_BUTTON) { //마우스 왼쪽버튼이 눌린채로
		sx += 0.1; //x크기 증가
		sy += 0.1; //y크기 증가
		sz += 0.1; //z크기 증가
	}
	else if (Button == GLUT_RIGHT_BUTTON) { //아니면
		sx -= 0.1; //x크기 감소
		sy -= 0.1; //y크기 감소
		sz -= 0.1; //z크기 감소
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	Width = 500;
	Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); //디스플레이모드를 싱글, RGBA로 초기화
	glutInitWindowSize(Width, Height); //윈도우 사이즈 초기화
	glutInitWindowPosition(0, 0); //window좌표 초기화
	glutCreateWindow("ViewporyPartition"); //프로그램 이름
	glutDisplayFunc(MyDisplay); //디스플레이 함수 등록
	glutIdleFunc(MyIdle); //아이들 함수 등록
	glutKeyboardFunc(MyKeyboard); //키보드 함수 등록
	glutMouseFunc(MyMouseClick); //마우스클릭함수 등록
	glutReshapeFunc(MyReshape); //reshape콜백 함수 등록
	glutMainLoop(); //메인함수
	return 0;
}