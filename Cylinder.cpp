#include<stdlib.h> //표준 라이브러리 포함
#include<gl/glut.h> //glut 라이브러리 포함

GLUquadricObj* qobj = gluNewQuadric(); //새로운 quadric object 생성

int MyListID; //DisplayList는 정수 ID에 의해 식별

void MyCreateList() { //display list함수
	MyListID = glGenLists(1); //DIsplayList 선언
	//아이디를 가진 리스트1개를 새로 만들되,
	//실행하지 않고 컴파일 완료된 버전을 만든다.
	glNewList(MyListID, GL_COMPILE); //display list를 생성하기 위한 함수

	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };//주변광
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };//반사광
	GLfloat mat_shininess[] = { 50.0 };//선명도
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//조명위치
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; //모델의 주변광

	glClearColor(0.0, 0.0, 0.0, 0.0); //배경색 지정
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); //주변광을 만든다
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //반사광을 만든다
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); //선명도를 만든다
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); //조명의 위치를 정해준다
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient); //잔잔한 조명을 만든다

	glEnable(GL_LIGHTING); //조명 모드를 활성화
	glEnable(GL_LIGHT0); //light0값을 설정
	glEnable(GL_DEPTH_TEST); //깊이 버퍼를 업데이트

	glMatrixMode(GL_MODELVIEW); //배열 모드를 지정한다(현재는 모델뷰를 선택)
	glLoadIdentity(); //현재 모델뷰 행렬을 초기화(단위 행렬로)
	gluLookAt(0.5, 0.4, 1.4, 0.1, 0.0, -1.0, -5.0, -5.0, -5.0); //카메라 조정

	glShadeModel(GL_SMOOTH); //각 정점에 정한 색상을 보간하여 혼합하여 칠하게 설정
	gluQuadricDrawStyle(qobj, GLU_LINE); //Quadric을 위해 원하는 Draw Style 지정
	gluQuadricNormals(qobj, GLU_SMOOTH); //법선벡터 제어
	gluQuadricOrientation(qobj, GLU_OUTSIDE); //법선벡터 내부 및 외부 등과 같은 방향 지정
	gluQuadricTexture(qobj, GL_FALSE); //Texture 좌표 사용할 것인지에 대한 여부
	gluCylinder(qobj, 1.0, 0.3, 2.0, 20, 8); //실린더를 그린다.

	glEndList(); //리스트 종료
}

void MyDisplay() //display 콜백 함수
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //색버퍼와 깊이버퍼를 비워준다.
	glCallList(MyListID); //컴파일이 완료된 리스트가 실제로 실행
	glutSwapBuffers(); //전면버퍼와 후면버퍼를 통째로 교체한다.
}

void Reshape(int w, int h) { //윈도우 창을 재조정시에 호출되는 reshape 콜백 함수
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //윈도우 화면을 새로운 크기로 지정
	glMatrixMode(GL_PROJECTION); //변환 행렬을 투영변환으로 변경
	glLoadIdentity(); //행렬 초기화

	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); //가시 부피 변경
	glMatrixMode(GL_MODELVIEW); //배열 모드를 지정한다(현재는 모델뷰를 선택)
	glLoadIdentity(); //행렬 초기화
}

int main(int argc, char** argv) { //메인함수
	glutInit(&argc, argv); //glut 라이브러리 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //디스플레이 모드 설정, 버퍼2개, RGB, 깊이 버퍼
	glutInitWindowSize(800, 600); //윈도우 사이즈 조정
	glutInitWindowSize(0, 0); //윈도우 왼쪽 위 좌표(GLU좌표계 사용)
	glutCreateWindow("Cylinder"); //윈도우 이름 설정
	glutDisplayFunc(MyDisplay); //display 콜백 함수 등록
	glutReshapeFunc(Reshape); //reshape 콜백 함수 등록
	MyCreateList(); //DIsplay List생성
	glutMainLoop(); //loop 설정
	return 0;
}
