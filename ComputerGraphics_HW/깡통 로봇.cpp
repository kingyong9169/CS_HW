/***************************************************/
/*                HW#5-3 : 깡통 로봇               */
/*  작성자 : 김동용     날짜 : 2020년 11월 11일    */
/*                                                 */
/*문제 정의 : 팔 2개, 다리 2개를 가진 Can Robot 제작*/
/*                - - - - - - -                    */
/***************************************************/
#include <gl/glut.h>
#include <stdlib.h>
static int body = 0, head = 0, arm1 = 0, arm2 = 0, leg1 = 0, leg2 = 0, //몸통, 머리, 팔, 다리, 관절의 변수
arm1_2 = 0, arm2_2 = 0, leg1_2 = 0, leg2_2 = 0,
check1 = 0, check2 = 0; //45도 회전했는지 체크용
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix(); //body
		glTranslatef(0.0, -1.0, 0.0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)body, 0.0, 0.0, 1.0); //머리를 기준으로 회전
		glTranslatef(0.0, 1.0, 0.0); // Pivot 으로 지정할 위치를 원점으로 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
			glScalef(1.5, 2.0, 1.0);
			glutWireCube(1.0); // 몸통을 만들어준다
		glPopMatrix();
		//head
		glTranslatef(0.0, 1.0, 0.0); // Pivot 으로 지정할 위치를 원점으로 이동
		glRotatef((GLfloat)head, 0.0, 0.0, 1.0); //머리의 중앙을 기준으로 회전
		glTranslatef(0.0, 0.5, 0.0); // Pivot 으로 지정할 위치를 원점으로 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
			glScalef(1.0, 1.0, 1.0);
			glutWireCube(1.0); // 머리를 만들어준다
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //arm1
		glTranslatef(-0.75, 1.0, 0.0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)arm1, 0.0, 0.0, 1.0);  //어깨를 기준으로 회전
		glTranslatef(-0.25, -0.5, 0.0); // Pivot 지정 및 객체 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.5, 1.0, 1.0); //왼쪽팔의 첫 번째 관절
				glutWireCube(1.0);
			glPopMatrix();
			glTranslatef(0.0, -0.5, 0.0); // Pivot 지정 및 객체 이동
			glRotatef((GLfloat)arm1_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
			glTranslatef(0.0, -0.5, 0.0); // Pivot 지정 및 객체 이동
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.5, 1.0, 1.0); //왼쪽팔의 두 번째 관절
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //arm2
		glTranslatef(0.75, 1.0, 0.0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)arm2, 0.0, 0.0, 1.0); //어깨를 기준으로 회전
		glTranslatef(0.25, -0.5, 0.0); // Pivot 지정 및 객체 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.5, 1.0, 1.0); //오른팔의 첫 번째 관절
				glutWireCube(1.0);
			glPopMatrix();
			glTranslatef(0.0, -0.5, 0.0); // Pivot 지정 및 객체 이동
			glRotatef((GLfloat)arm2_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
			glTranslatef(0.0, -0.5, 0.0); // Pivot 지정 및 객체 이동
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.5, 1.0, 1.0); //오른팔의 두 번째 관절
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5, -1.0, 0.0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)leg1, 0.0, 0.0, 1.0); // 골반을 기준으로 회전
		glTranslatef(0.0, -0.5, 0.0); // Pivot 지정 및 객체 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.3, 1.0, 1.0);
				glutWireCube(1.0); //왼쪽 다리를 만들어준다
			glPopMatrix();
			glTranslatef(0.0, -0.5, 0.0); // Pivot 지정 및 객체 이동
			glRotatef((GLfloat)leg1_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
			glTranslatef(0.0, -0.2, 0.0); // Pivot 지정 및 객체 이동
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.5, 0.4, 1.0); //오른팔의 두 번째 관절
				glutWireCube(1.0);
			glPopMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
		glPopMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5, -1.0, 0.0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)leg2, 0.0, 0.0, 1.0); // 골반을 기준으로 회전
		glTranslatef(0.0, -0.5, 0.0); // Pivot 지정 및 객체 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.3, 1.0, 1.0);
				glutWireCube(1.0); //오른쪽 다리를 만들어준다
			glPopMatrix();
			glTranslatef(0.0, -0.5, 0.0); // Pivot 지정 및 객체 이동
			glRotatef((GLfloat)leg2_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
			glTranslatef(0.0, -0.2, 0.0); // Pivot 지정 및 객체 이동
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.5, 0.4, 1.0); //오른팔의 두 번째 관절
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glPopMatrix(); //원점으로 돌아감
	glutSwapBuffers();
}

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void MyTimer_left(int Value) { //좌클릭 타이머 함수
	if (check1==0&&arm1 == 45 && arm1_2 == 45 && arm2 == 45 && arm2_2 == 45) //모든 관절이 45도가 되면
		check1 = 1;
	if (check1 == 0 && arm1 < 45)
		arm1 = (arm1 + 5) % 180; //왼팔을 움직인다
	if (check1 == 0 && arm1_2 < 45)
		arm1_2 = (arm1_2 + 5) % 180; //왼팔의 관절을 움직인다
	if (check1 == 0 && arm2 < 45)
		arm2 = (arm2 + 5) % 180; //오른팔을 움직인다
	if (check1 == 0 && arm2_2 < 45)
		arm2_2 = (arm2_2 + 5) % 180; //오픈팔의 관절을 움직인다
	if (check1 == 1 && arm1 == 0 && arm1_2 == 0 && arm2 == 0 && arm2_2 == 0) { //모든 관절이 0도가 되면
		check1 = 0;
		return;
	}
	if (check1 == 1 && arm1 >0)
		arm1 = (arm1 - 5) % 180; //왼팔을 움직인다
	if (check1 == 1 && arm1_2 > 0)
		arm1_2 = (arm1_2 - 5) % 180; //왼팔의 관절을 움직인다
	if (check1 == 1 && arm2 > 0)
		arm2 = (arm2 - 5) % 180; //오른팔을 움직인다
	if (check1 == 1 && arm2_2 > 0)
		arm2_2 = (arm2_2 - 5) % 180; //오픈팔의 관절을 움직인다
	glutPostRedisplay(); //재출력
	glutTimerFunc(200, MyTimer_left, 1); //콜백함수 등록
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) { //마우스 왼쪽버튼이 눌린채로
		glutTimerFunc(200, MyTimer_left, 1); //콜백함수 등록
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Can Robot");
	MyInit();
	glutDisplayFunc(MyDisplay); //디스플레이 함수 등록
	glutReshapeFunc(MyReshape); //reshape함수 등록
	glutMouseFunc(MyMouseClick); //마우스클릭함수 등록
	glutMainLoop();
	return 0;
}