#include<GL/glut.h> //glut불러오기
#include<stdlib.h>// rand() 함수사용용도

/***************************************************/
/*                        HW#3 : 3D 가스켓 프로그램*/
/*  작성자 : 김동용         날짜 : 2020년 10월 07일*/
/* 문제 정의 : 2D를 3D로 3-3가스켓 프로그램 만들기 */
/*                - - - - - - -                    */
/***************************************************/

void MyReshape(int NewWidth, int NewHeight) { //Reshape callback을 통한 왜곡 현상 해결
	glViewport(0, 0, NewWidth, NewHeight); //그림이 그려지는 디스플레이 장치에서의 사각 영역
	// 이벤트를통해뷰포트를새롭게받은가로와세로길이로설정합니다.
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)300;
	// 이벤트를통해새롭게받은가로와세로를통하여비율을새로정합니다.
	glMatrixMode(GL_PROJECTION); //투영 행렬 선택
	glLoadIdentity(); //단위행렬로 초기화
	glMatrixMode(GL_MODELVIEW); //모델뷰 행렬 선택
	glLoadIdentity(); //단위행렬로 초기화
	glOrtho(-100.0 * Widthfactor, 500.0 * Widthfactor, -100.0 * Heightfactor, 500.0 * Heightfactor, 500.0, -500.0); //직교투영 변환 함수
	//인자 값에 따라 가시부피가 변하므로 회전 전에 선언
	glRotatef(10.0, 1.0, 0.0, 0.0); //x축으로 10도 회전
	glRotatef(30.0, 0.0, 1.0, 0.0); //y축으로 30도 회전
}

void MyDisplay(void) //디스플레이함수
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // 하얀배경으로세팅
	glColor3f(0.0, 0.0, 0.0); // 검은점으로세팅
	float vertices[4][3] = { { 0.0,0.0 },{ 250.0,500.0 },
		{ 500.0,0.0 }, {0.0,0.0,500.0} }; //초기세모
	int i, j;
	float p[3] = { 50.0, 50.0, 50.0 }; // 찍힐 포인트
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //색버퍼와 깊이버퍼를 비워준다.
	
	for (j = 0; j < 50000; j++) //50000번 반복
	{
		i = rand() % 4; // 임의의점선택. 0-3의값
		
		p[0] = (p[0] + vertices[i][0]) / 2.0;
		p[1] = (p[1] + vertices[i][1]) / 2.0;
		p[2] = (p[2] + vertices[i][2]) / 2.0;
		// 새로선택된좀과현재점을기준으로새로운점위치계산( 중점의위치계산)
		glBegin(GL_POINTS); //점으로 glbegin
		glVertex3fv(p); // 찍힐위치에점찍기
		glEnd(); //glend
	}
	glFlush(); //실행되지 않은 것들을 전부 다 실행시켜준다.
}

void main(int argc, char** argv) //메인함수
{
	glutInit(&argc, argv); //glut 라이브러리 초기화
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //디스플레이모드 초기화
	glutInitWindowSize(500, 500); //윈도우 화면 크기 초기화
	glutInitWindowPosition(0, 0); //윈도우포지션 초기화
	glutCreateWindow("SierpinskiGasket"); //프로그램 제목
	glutDisplayFunc(MyDisplay); //디스플레이 콜백함수등록
	glutReshapeFunc(MyReshape); // reshape 콜백함수등록
	glutMainLoop(); //메인루프 실행
}