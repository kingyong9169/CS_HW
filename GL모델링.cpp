#include <GL/glut.h> //openGL Utility Toolkit 라이브러리를 포함

void Points() { //점을 그리는 함수
	GLfloat Size[2], Angle; //점의 크기와 점이 위치할 각도 선언
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //점의 색상을 정한다
	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
	glPointSize(Size[0] * 10); //점의 크기를 10배 곱한다
	glBegin(GL_POINTS); //각 vertex들을 하나의 point로 표현한다.
	glVertex3f(0.2, 0.5, 0.0); //점의 좌표
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void Lines() { //선을 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 5.0, 5.0); //선의 색상을 정한다.
	glBegin(GL_LINES); //vertex들을 두 개씩 묶어서 line을 만든다.
	glVertex3f(0.0, 0.5, 0.0); //좌료1
	glVertex3f(-0.5, 0.25, 0.0); //좌료2
	glVertex3f(-0.5, -0.25, 0.0); //좌료3
	glVertex3f(0.0, -0.5, 0.0); //좌료4
	glVertex3f(0.5, -0.25, 0.0); //좌료5
	glVertex3f(0.5, 0.25, 0.0); //좌료6
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void LineStrip() { //선 strip을 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //도형의 색 지정
	glBegin(GL_LINE_STRIP); //line들을 한 줄로 연결한다.
	glVertex3f(0.0, 0.5, 0.0); //좌표1
	glVertex3f(-0.5, 0.25, 0.0); //좌표2
	glVertex3f(-0.5, -0.25, 0.0); //좌표3
	glVertex3f(0.0, -0.5, 0.0); //좌표4
	glVertex3f(0.5, -0.25, 0.0); //좌표5
	glVertex3f(0.5, 0.25, 0.0); //좌표6
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void LineLoop() { //선loop를 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //도형의 색 지정
	glBegin(GL_LINE_LOOP); //마지막 vertex와 첫 번재 vertex를 연결하는 line이 추가된 GL_LINE_STRIP
	glVertex3f(0.0, 0.5, 0.0); //좌표1
	glVertex3f(-0.5, 0.25, 0.0); //좌표2
	glVertex3f(-0.5, -0.25, 0.0); //좌표3
	glVertex3f(0.0, -0.5, 0.0); //좌표4
	glVertex3f(0.5, -0.25, 0.0); //좌표5
	glVertex3f(0.5, 0.25, 0.0); //좌표6
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void TriangleFan() { //삼각형fan을 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //도형의 색 지정
	glBegin(GL_TRIANGLE_FAN); //삼각형들을 부채 모양으로 연결한다.
	glVertex3f(0.0, 0.0, 0.0); //좌표1
	glVertex3f(-0.5, 0.25, 0.0); //좌표2
	glVertex3f(-0.5, -0.25, 0.0); //좌표3
	glVertex3f(0.0, -0.5, 0.0); //좌표4
	glVertex3f(0.5, -0.25, 0.0); //좌표5
	glVertex3f(0.5, 0.25, 0.0); //좌표6
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void Triangles() { //삼각형을 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //도형의 색 지정
	glBegin(GL_TRIANGLES); //세 개의 vertex를 묶어서 삼각형을 만든다.
	glVertex3f(0.0, 0.0, 0.0); //좌표1
	glVertex3f(-0.5, 0.25, 0.0); //좌표2
	glVertex3f(-0.5, -0.25, 0.0); //좌표3
	glVertex3f(0.0, -0.5, 0.0); //좌표4
	glVertex3f(0.5, -0.25, 0.0); //좌표5
	glVertex3f(0.5, 0.25, 0.0); //좌표6
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void TriangleStrip() { //삼각형strip을 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //도형의 색 지정
	glBegin(GL_TRIANGLE_STRIP); //삼각형들을 길게 연결한다
	glVertex3f(0.0, 0.0, 0.0); //좌표1
	glVertex3f(-0.5, 0.25, 0.0); //좌표2
	glVertex3f(-0.5, -0.25, 0.0); //좌표3
	glVertex3f(0.0, -0.5, 0.0); //좌표4
	glVertex3f(0.5, -0.25, 0.0); //좌표5
	glVertex3f(0.5, 0.25, 0.0); //좌표6
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void Polygons() { //polygon을 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //도형의 색 지정
	glBegin(GL_POLYGON); //단순, 블록 polygon
	glVertex3f(0.0, 0.5, 0.0); //좌표1
	glVertex3f(-0.5, 0.25, 0.0); //좌표2
	glVertex3f(-0.5, -0.25, 0.0); //좌표3
	glVertex3f(0.0, -0.5, 0.0); //좌표4
	glVertex3f(0.5, -0.25, 0.0); //좌표5
	glVertex3f(0.5, 0.25, 0.0); //좌표6
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void Quads() { //quad를 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //도형의 색 지정
	glBegin(GL_QUADS); //vertex들을 네 개씩 묶어서 만든 네 개의 모서리를 가진 polygon을 만든다.
	glVertex3f(0.0, 0.5, 0.0); //좌표1
	glVertex3f(-0.5, 0.25, 0.0); //좌표2
	glVertex3f(-0.5, -0.25, 0.0); //좌표3
	glVertex3f(0.0, -0.5, 0.0); //좌표4
	glVertex3f(0.5, -0.25, 0.0); //좌표5
	glVertex3f(0.5, 0.25, 0.0); //좌표6
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

void QuadStrip() { //quadstrip을 그리는 함수
	glClear(GL_COLOR_BUFFER_BIT); //색 버퍼 제거
	glColor3f(1.0, 1.0, 1.0); //도형의 색 지정
	glBegin(GL_QUAD_STRIP); //사각형들을 길게 연결한다.
	glVertex3f(0.0, 0.5, 0.0); //좌표1
	glVertex3f(-0.5, 0.25, 0.0); //좌표2
	glVertex3f(-0.5, -0.25, 0.0); //좌표3 
	glVertex3f(0.0, -0.5, 0.0); //좌표4
	glVertex3f(0.5, -0.25, 0.0); //좌표5
	glVertex3f(0.5, 0.25, 0.0); //좌표6
	glVertex3f(0.1, 0.0, 0.0); //좌표7
	glVertex3f(0.5, 0.1, 0.0); //좌표8
	glEnd(); //GL을 마침
	glFlush(); //큐 삭제하기 : 아직 실행되지 않은 명령을 실행되도록 함
}

int main(int argc, char** argv) { //메인함수
	glutInit(&argc, argv); //window os와 session 연결, GLUT Library를 초기화
	glutInitDisplayMode(GLUT_RGB); //Display Mode 설정
	glutInitWindowSize(500, 500); //window의 크기 설정
	glutCreateWindow("My First OpenGL Code"); //새로운 window생성
	glutDisplayFunc(QuadStrip); //해당 함수를 실행
	glutMainLoop(); //GLUT Event처리 Loop 입력
	return 0;
}