///********************************************************/
///*                                term project : 경마장 */
///*        작성자 : 김동용         날짜 : 2020년 12월 8일*/
///*             문제 정의 : 행렬 스택을 이용한 말 모델링 */
///*                     - - - - - - -                    */
///********************************************************/
#include<gl/glut.h>

int Width, Height; //화면 상의 폭, 높이
GLfloat x = 0.0, y = 0.0, z = 0.0; //카메라 위치에 대한 변수
GLfloat fx = 0.0, fy = 0.0, fz = 0.0; //카메라 초점에 대한 변수
GLfloat Widthfactor, Heightfactor; //화면 상의 폭, 높이의 비율
GLfloat posX = 0.0, posY = 0.0, posZ[2] = { 0 }; //말의 위치
GLfloat R = 0, G = 0, B = 0; //말의 색깔
GLfloat bkR = 0.529412, bkG = 0.807843, bkB = 0.980392; //배경 색
GLfloat pos[4] = { 5.0 , 5.0 , 5.0 , 1.0 };//조명 배치

struct joint { //관절 부분
	GLfloat x = 0, y = 0, z = 0; //말의 방향 전환
	GLfloat neckbt = -80; //목 위
	GLfloat necktp = 0; //목 아래
	GLfloat head = 90; //머리

	GLfloat frtLLegtp = 90; //앞왼쪽다리 위
	GLfloat frtLLegbt = 10; //앞왼쪽다리 아래
	GLfloat frtRLegtp = 90; //앞오른쪽다리 위
	GLfloat frtRlegbt = 10; //앞오른쪽다리 아래

	GLfloat bkLLegtp = 90; //뒤왼쪽다리 위
	GLfloat bkLLegbt = 10; //뒤왼쪽다리 아래
	GLfloat bkRLegtp = 90; //뒤오른쪽다리 위
	GLfloat bkRLegbt = 10; //뒤오른쪽다리 아래

	GLfloat tail = -50; //꼬리
}puppy[3];

GLUquadricObj* g_normalObject = NULL;
GLfloat horsex = 0, horsey = 1;
void DrawHorse1(int i) {
	//말의 몸통
	glPushMatrix();
	glRotated(puppy[i].x, 0, 1, 0);
	glTranslated(i, 1, -(i + .7) + posZ[i]);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glColor3f(R + i - 0.3, G + i - 0.3, B + i - 0.3);
	gluCylinder(g_normalObject, 0.35, 0.4, 1.4, 20, 8);
	glPushMatrix(); //말의 몸통 앞부분, 뒷부분에 디스크 그리기
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);
	glPopMatrix();

	//말의 목 아랫부분
	glPushMatrix();
	glTranslatef(0, .4, 1.2);
	glRotated(puppy[i].neckbt, 1, 0, 0);
	gluCylinder(g_normalObject, 0.2, 0.19, 0.5, 20, 8);

	//말의 목 윗부분
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].necktp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.19, 0.10, 0.5, 20, 8);

	//말의 머리
	glPushMatrix();
	glTranslatef(0, 0, .5);
	glRotated(puppy[i].head, 1, 0, 0);
	gluCylinder(g_normalObject, 0.2, 0.1, 0.6, 20, 8);

	//말의 뿔
	glPushMatrix();
	glTranslatef(0, 0.1, 0.2);
	glRotated(-90, 1, 0, 0);
	glColor3f(.5 + i, 1.0 + i, .80 + i);
	gluCylinder(g_normalObject, 0.05, 0, 0.5, 20, 8);
	glPopMatrix();
	glPopMatrix();
	glColor3f(0.823529, 0.705882, 0.54902);
	glPopMatrix();
	glPopMatrix();

	//왼쪽 앞다리 윗부분
	glPushMatrix();
	glTranslatef(0.15, -.3, 1.3);
	glRotated(puppy[i].frtLLegtp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.1, 0.6, 20, 8);

	//왼쪽 앞다리 아랫부분
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].frtLLegbt, 10, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.13, 0.67, 20, 8);
	glPopMatrix();
	glPopMatrix();

	//오른쪽 앞다리 윗부분
	glPushMatrix();
	glTranslatef(-.15, -.3, 1.3);
	glRotated(puppy[i].frtRLegtp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.1, 0.6, 20, 8);

	//오른쪽 앞다리 아랫부분
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].frtRlegbt, 10, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.13, 0.67, 20, 8);
	glPopMatrix();
	glPopMatrix();

	//왼쪽 뒷다리 윗부분
	glPushMatrix();
	glTranslatef(0.15, -.3, 0.15);
	glRotated(puppy[i].bkLLegtp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.15, 0.1, 0.6, 20, 8);

	//왼쪽 뒷다리 아랫부분
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].bkLLegbt, -10, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.13, 0.67, 20, 8);
	glPopMatrix();
	glPopMatrix();

	//오른쪽 뒷다리 윗부분
	glPushMatrix();
	glTranslatef(-0.15, -.3, 0.15);
	glRotated(puppy[i].bkRLegtp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.15, 0.1, 0.6, 20, 8);

	//오른쪽 뒷다리 아랫부분
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].bkRLegbt, -10, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.13, 0.67, 20, 8);
	glPopMatrix();
	glPopMatrix();

	//말의 꼬리
	glPushMatrix();
	glRotated(puppy[i].tail, 1, puppy[i].z, 0);
	glTranslated(0, 0.07, -0.5);
	gluCylinder(g_normalObject, 0.1, 0.1, 0.8, 40, 18);
	glPopMatrix();
	glPopMatrix(); //말 만들기 끝
}
void DrawWood(int i) {
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(5 + 2 * i, 1, -(5 + .7 + 2 * i));
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glColor3f(0.647059, 0.164706, 0.164706);
	glPushMatrix(); //말의 몸통 앞부분, 뒷부분에 디스크 그리기
	gluCylinder(g_normalObject, 0.4, 0.4, 1.4, 20, 8);
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);

	glPushMatrix(); //말의 몸통 앞부분, 뒷부분에 디스크 그리기
	gluCylinder(g_normalObject, 0.4, 0.4, 1.4, 20, 8);
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);
	glPushMatrix(); //말의 몸통 앞부분, 뒷부분에 디스크 그리기
	gluCylinder(g_normalObject, 0.4, 0.4, 1.4, 20, 8);
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);
	glPushMatrix(); //말의 몸통 앞부분, 뒷부분에 디스크 그리기
	gluCylinder(g_normalObject, 0.4, 0.4, 1.4, 20, 8);
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void Draw() { //들판 및 나무, 말 2마리 그리기
	glColor3f(0, 1, 0.498039);
	glPushMatrix(); //행렬 삽입
	glTranslatef(0.0, 0, 0.0);
	glBegin(GL_QUADS); //들판 그리기
	glVertex3f(20.0, 0.0, 20.0); //들판의 좌표들
	glVertex3f(20.0, 0.0, -20.0);
	glVertex3f(-20.0, 0.0, -20.0);
	glVertex3f(-20.0, 0.0, 20.0);
	glEnd();
	glPopMatrix(); //행렬 팝

	DrawWood(5); //나무 그리기
	DrawHorse1(0); //말1 그리기
	DrawHorse1(1); //말2 그리기
}

void MyDisplay() { //디스플레이 함수
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //색상 지정
	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); //행렬 삽입
	glLoadIdentity(); //항등행렬로 초기화
	gluPerspective(30, 1.0 * Widthfactor / Heightfactor, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix(); //행렬 삽입
	gluLookAt(25.0 + x, 30.0 + y, 15.0 + z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 20.0, 0.0); //이 좌표로 시점 변환
	Draw(); //drawscene함수 호출
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

void InitVisibility() {
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_FILL);
	glCullFace(GL_FRONT);
	glEnable(GL_DEPTH_TEST);
}

void MySpecial(int key, int pos1, int pos2) { //카메라 위치를 바꿔줌
	switch (key) {
	case GLUT_KEY_RIGHT: //오른쪽 방향키
		x += 0.3; //카메라의 위치x를 0.1증가
		break;
	case GLUT_KEY_LEFT: //왼쪽 방향키
		x -= 0.3; //카메라의 위치x를 0.1감소
		break;
	case GLUT_KEY_UP: //위쪽 방향키
		y += 0.3; //카메라의 위치y를 0.1증가
		break;
	case GLUT_KEY_DOWN: //아래쪽 방향키
		y -= 0.3; //카메라의 위치y를 0.1감소
		break;
	}
	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int pos1, int pos2) { //카메라 초점을 바꿔줌
	switch (key) {
	case 'q': //q, Q키 누르면 
	case 'Q':
		fx += 0.3; //카메라가 바라보는 초점 x의 위치를 0.3증가
		break;
	case 'f': //f, F키 누르면 
	case 'F':
		fx -= 0.3; //카메라가 바라보는 초점 x의 위치를 0.3감소
		break;
	case 'r': //r, R키 누르면
	case 'R':
		fy += 0.3; //카메라가 바라보는 초점 y의 위치를 0.3증가
		break;
	case 'v': //b, B키 누르면
	case 'V':
		fy -= 0.3; //카메라가 바라보는 초점 y의 위치를 0.3감소
		break;
	case 'z': //b, B키 누르면
	case 'Z':
		fz += 0.3; //카메라가 바라보는 초점 z의 위치를 0.3증가
		break;
	case 't': //t, T키 누르면
	case 'T':
		fz -= 0.3; //카메라가 바라보는 초점 z의 위치를 0.3감소
		break;
	case 'w': //전진
	case 'W':
		if (puppy[0].frtLLegtp <= 105 && puppy[0].frtRLegtp >= 75 && puppy[0].bkLLegtp >= 75 && puppy[0].bkRLegtp <= 115) {
			if (puppy[0].neckbt <= -80 && puppy[0].necktp >= 0) {
				puppy[0].neckbt += 20; //목 위
				puppy[0].necktp += 20; //목 아래
			}
			else if (puppy[0].neckbt >= -60 && puppy[0].necktp <= 20) {
				puppy[0].neckbt -= 20; //목 위
				puppy[0].necktp -= 20; //목 아래
			}
			puppy[0].frtLLegtp += 15; //앞왼쪽다리 위
			puppy[0].frtRLegtp -= 15; //앞오른쪽다리 위
			puppy[0].bkLLegtp -= 15; //앞왼쪽다리 위
			puppy[0].bkRLegtp += 15; //앞오른쪽다리 위
		}
		else if (puppy[0].frtLLegtp >= 90 && puppy[0].frtRLegtp <= 90 && puppy[0].bkLLegtp <= 90 && puppy[0].bkRLegtp >= 90) {
			if (puppy[0].neckbt <= -80 && puppy[0].necktp >= 0) {
				puppy[0].neckbt += 20; //목 위
				puppy[0].necktp += 20; //목 아래
			}
			else if (puppy[0].neckbt >= -60 && puppy[0].necktp <= 20) {
				puppy[0].neckbt -= 20; //목 위
				puppy[0].necktp -= 20; //목 아래
			}
			puppy[0].frtLLegtp -= 15; //앞왼쪽다리 위
			puppy[0].frtRLegtp += 15; //앞오른쪽다리 위
			puppy[0].bkLLegtp += 15; //앞왼쪽다리 위
			puppy[0].bkRLegtp -= 15; //앞오른쪽다리 위
		}
		posZ[0] += 0.5;
		break;
	case 's': //후진
	case 'S':
		if (puppy[0].frtLLegtp <= 105 && puppy[0].frtRLegtp >= 75 && puppy[0].bkLLegtp >= 75 && puppy[0].bkRLegtp <= 115) {
			if (puppy[0].neckbt <= -80 && puppy[0].necktp >= 0) {
				puppy[0].neckbt += 20; //목 위
				puppy[0].necktp += 20; //목 아래
			}
			else if (puppy[0].neckbt >= -60 && puppy[0].necktp <= 20) {
				puppy[0].neckbt -= 20; //목 위
				puppy[0].necktp -= 20; //목 아래
			}
			puppy[0].frtLLegtp += 15; //앞왼쪽다리 위
			puppy[0].frtRLegtp -= 15; //앞오른쪽다리 위
			puppy[0].bkLLegtp -= 15; //앞왼쪽다리 위
			puppy[0].bkRLegtp += 15; //앞오른쪽다리 위
		}
		else if (puppy[0].frtLLegtp >= 90 && puppy[0].frtRLegtp <= 90 && puppy[0].bkLLegtp <= 90 && puppy[0].bkRLegtp >= 90) {
			if (puppy[0].neckbt <= -80 && puppy[0].necktp >= 0) {
				puppy[0].neckbt += 20; //목 위
				puppy[0].necktp += 20; //목 아래
			}
			else if (puppy[0].neckbt >= -60 && puppy[0].necktp <= 20) {
				puppy[0].neckbt -= 20; //목 위
				puppy[0].necktp -= 20; //목 아래
			}
			puppy[0].frtLLegtp -= 15; //앞왼쪽다리 위
			puppy[0].frtRLegtp += 15; //앞오른쪽다리 위
			puppy[0].bkLLegtp += 15; //앞왼쪽다리 위
			puppy[0].bkRLegtp -= 15; //앞오른쪽다리 위
		}
		posZ[0] -= 0.5;
		break;
	case 'd': //오른쪽으로 방향전환
	case 'D':
		puppy[0].x -= 10;
		break;
	case 'a': //왼쪽으로 방향전환
	case 'A':
		puppy[0].x += 10;
		break;
	case 'i': //전진
	case 'I':
		if (puppy[1].frtLLegtp <= 105 && puppy[1].frtRLegtp >= 75 && puppy[1].bkLLegtp >= 75 && puppy[1].bkRLegtp <= 115) {
			if (puppy[1].neckbt <= -80 && puppy[1].necktp >= 0) {
				puppy[1].neckbt += 20; //목 위
				puppy[1].necktp += 20; //목 아래
			}
			else if (puppy[1].neckbt >= -60 && puppy[1].necktp <= 20) {
				puppy[1].neckbt -= 20; //목 위
				puppy[1].necktp -= 20; //목 아래
			}
			puppy[1].frtLLegtp += 15; //앞왼쪽다리 위
			puppy[1].frtRLegtp -= 15; //앞오른쪽다리 위
			puppy[1].bkLLegtp -= 15; //앞왼쪽다리 위
			puppy[1].bkRLegtp += 15; //앞오른쪽다리 위
		}
		else if (puppy[1].frtLLegtp >= 90 && puppy[1].frtRLegtp <= 90 && puppy[1].bkLLegtp <= 90 && puppy[1].bkRLegtp >= 90) {
			if (puppy[1].neckbt <= -80 && puppy[1].necktp >= 0) {
				puppy[1].neckbt += 20; //목 위
				puppy[1].necktp += 20; //목 아래
			}
			else if (puppy[1].neckbt >= -60 && puppy[1].necktp <= 20) {
				puppy[1].neckbt -= 20; //목 위
				puppy[1].necktp -= 20; //목 아래
			}
			puppy[1].frtLLegtp -= 15; //앞왼쪽다리 위
			puppy[1].frtRLegtp += 15; //앞오른쪽다리 위
			puppy[1].bkLLegtp += 15; //앞왼쪽다리 위
			puppy[1].bkRLegtp -= 15; //앞오른쪽다리 위
		}
		posZ[1] += 0.5;
		break;
	case 'k': //후진
	case 'K':
		if (puppy[1].frtLLegtp <= 105 && puppy[1].frtRLegtp >= 75 && puppy[1].bkLLegtp >= 75 && puppy[1].bkRLegtp <= 115) {
			if (puppy[1].neckbt <= -80 && puppy[1].necktp >= 0) {
				puppy[1].neckbt += 20; //목 위
				puppy[1].necktp += 20; //목 아래
			}
			else if (puppy[1].neckbt >= -60 && puppy[1].necktp <= 20) {
				puppy[1].neckbt -= 20; //목 위
				puppy[1].necktp -= 20; //목 아래
			}
			puppy[1].frtLLegtp += 15; //앞왼쪽다리 위
			puppy[1].frtRLegtp -= 15; //앞오른쪽다리 위
			puppy[1].bkLLegtp -= 15; //앞왼쪽다리 위
			puppy[1].bkRLegtp += 15; //앞오른쪽다리 위
		}
		else if (puppy[1].frtLLegtp >= 90 && puppy[1].frtRLegtp <= 90 && puppy[1].bkLLegtp <= 90 && puppy[1].bkRLegtp >= 90) {
			if (puppy[1].neckbt <= -80 && puppy[1].necktp >= 0) {
				puppy[1].neckbt += 20; //목 위
				puppy[1].necktp += 20; //목 아래
			}
			else if (puppy[1].neckbt >= -60 && puppy[1].necktp <= 20) {
				puppy[1].neckbt -= 20; //목 위
				puppy[1].necktp -= 20; //목 아래
			}
			puppy[1].frtLLegtp -= 15; //앞왼쪽다리 위
			puppy[1].frtRLegtp += 15; //앞오른쪽다리 위
			puppy[1].bkLLegtp += 15; //앞왼쪽다리 위
			puppy[1].bkRLegtp -= 15; //앞오른쪽다리 위
		}
		posZ[1] -= 0.5;
		break;
	case 'l': //오른쪽으로 방향전환
	case 'L':
		puppy[1].x -= 10;
		break;
	case 'j': //왼쪽으로 방향전환
	case 'J':
		puppy[1].x += 10;
		break;
	}
	glutPostRedisplay(); //강제로 디스플레이
}

void MyColorMenu(int entryID) { //컬러메뉴
	if (entryID == 1) { R = 1.0, G = 0.0, B = 0.0; } //빨간색으로
	else if (entryID == 2) { R = 1.0, G = 1.0, B = 0.0; } //노란색으로
	else if (entryID == 3) { R = 1.0, G = 0.0, B = 1.0; } //보라색으로
	else if (entryID == 4) { R = 0.0, G = 0.0, B = 0.0; } //검은색으로
	else if (entryID == 5) exit(0); //exit를 추가해줌
	glutPostRedisplay();
}

void MyIdle() {  //아무 이벤트가 없을 시에 실행되는 콜백함수로 이 안에서 specialkeyboardcallback을 등록하면서 활용함
	glutSpecialFunc(MySpecial); //콜백함수 등록
	glutPostRedisplay(); //강제로 디스플레이
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //도형의 크기를 바꿔줌
	if (Button == GLUT_LEFT_BUTTON) { //마우스 왼쪽버튼이 눌린채로
		if (puppy[0].z <= 0) { //꼬리를 흔든다
			puppy[0].z += 3;
			puppy[1].z += 3;
		}
		else if (puppy[0].z >= 3) { //꼬리를 흔든다
			puppy[0].z -= 3;
			puppy[1].z -= 3;
		}
	}
}

void MyTimer(int Value) {
	if (bkR >= 0 && bkG >= 0 && bkB >= 0) {
		bkR -= 0.1;
		bkG -= 0.1;
		bkB -= 0.1;
	}
	glutPostRedisplay(); //재출력
	glutTimerFunc(400, MyTimer, 1); //콜백함수 등록
}

void MyInit() { //메뉴 초기화
	g_normalObject = gluNewQuadric();
	glClearColor(bkR, bkG, bkB, 0); //배경 색 초기화
	glMatrixMode(GL_PROJECTION); //평행 투영
	glLoadIdentity(); //항등행렬로 초기화
	glOrtho(-20.0 * Widthfactor, 20.0 * Widthfactor, -20.0 * Heightfactor, 20.0 * Heightfactor, 5, 50); //가시부피를 화면 비율로 설정

	GLint MyColorID = glutCreateMenu(MyColorMenu); //color메뉴
	glutAddMenuEntry(" Red", 1);
	glutAddMenuEntry(" Yellow", 2);
	glutAddMenuEntry(" Purple", 3);
	glutAddMenuEntry(" Black", 4);
	glutAddMenuEntry(" Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON); //오른쪽 마우스 클릭하면 메뉴 팝업
}

void InitLight() {
	GLfloat light0_ambient[] = { 0.0, 0.4, 0.0, 1.0 }; //주변광
	GLfloat light0_diffuse[] = { 1.0, 0.5, 1.0, 1.0 }; //확산광
	GLfloat light0_specular[] = { 0.4, 1.0, 0.8, 1.0 }; //경면광
	glEnable(GL_DEPTH_TEST); //깊이 버퍼 활성화
	glShadeModel(GL_SMOOTH); // Gouraud 쉐이딩으로 설정
	glEnable(GL_LIGHTING); //조명 활성화
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); //주변광
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); //반사광
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); //경면광
	glEnable(GL_COLOR_MATERIAL); //조명과 동시에 원래 색깔을 출력한다
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	Width = 1200; //창의 크기
	Height = 1000; //창의 크기
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); //디스플레이모드를 싱글, RGBA로 초기화
	glutInitWindowSize(Width, Height); //윈도우 사이즈 초기화
	glutInitWindowPosition(0, 0); //window좌표 초기화
	glutCreateWindow("horse in the hall"); //프로그램 이름
	MyInit(); //초기화함수
	InitLight(); //조명 함수
	glutDisplayFunc(MyDisplay); //디스플레이 함수 등록
	glutIdleFunc(MyIdle); //아이들 함수 등록
	glutKeyboardFunc(MyKeyboard); //키보드 함수 등록
	glutMouseFunc(MyMouseClick); //마우스클릭함수 등록
	glutReshapeFunc(MyReshape); //reshape콜백 함수 등록
	glutTimerFunc(400, MyTimer, 1); //타이머함수 등록
	InitVisibility();
	glutMainLoop(); //메인함수
	return 0;
}