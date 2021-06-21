/***************************************************/
/*              HW#5-2 : 로봇 팔 응용              */
/*  작성자 : 김동용     날짜 : 2020년 11월 11일    */
/*                                                 */
/*   문제 정의 : 손가락 3개를 가진 Robot Arm 제작  */
/*                - - - - - - -                    */
/***************************************************/
#include <gl/glut.h>
#include <stdlib.h>
static int shoulder = 0, elbow = 0, finger1 = 0, finger2 = 0, finger3 = 0, 
check1=0, check2 = 0, check3 = 0, check4=0, check5=0; //회전횟수 체크용
void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix(); //finger1
		glTranslatef(-1.0, 0.0, 0.0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat )shoulder, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
		glTranslatef(1.0, 0.0, 0.0); // Pivot 으로 지정할 위치를 원점으로 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소 확대
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(1.0);
		glPopMatrix();

		glTranslatef(1.0, 0.0, 0.0);// Pivot 지정 및 객체 이동
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);// 원점을 기준으로 회전
		glTranslatef(1.0, 0.0, 0.0);// Pivot 으로 지정할 위치를 원점으로 이동

		glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
			glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(2.0, 0.4, 1.0);
				glutWireCube(1.0);
			glPopMatrix();
			glTranslatef(1.0, 0.0, -0.5);// Pivot 지정 및 객체 이동
			glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);// 첫 번째 손가락 첫 번째 마디
			glTranslatef(0.2, 0.0, 0.0);// Pivot 으로 지정할 위치를 원점으로 이동
			glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.3, 0.2, 0.2); // 첫 번째 손가락 첫 번째 마디의 크기를 정하고 그린다
				glutWireCube(1.0);
			glPopMatrix();
				glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);// 첫 번째 손가락 두 번째 마디
				glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
				glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
					glScalef(0.3, 0.2, 0.2); // 첫 번째 손가락 두 번째 마디의 크기를 정하고 그린다
					glutWireCube(1.0);
				glPopMatrix();
				glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
					glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);// 첫 번째 손가락 세 번째 마디
					glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
					glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
						glScalef(0.3, 0.2, 0.2); // 첫 번째 손가락 세 번째 마디의 크기를 정하고 그린다
						glutWireCube(1.0);
					glPopMatrix();
		glPopMatrix();

		glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
			glTranslatef(1.0, 0.0, 0.0);// Pivot 지정 및 객체 이동
			glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);// 두 번째 손가락 첫 번째 마디
			glTranslatef(0.2, 0, 0.0);// Pivot 으로 지정할 위치를 원점으로 이동
			glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.3, 0.2, 0.2); // 두 번째 손가락 첫 번째 마디의 크기를 정하고 그린다
				glutWireCube(1.0); 
			glPopMatrix();
			glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
			glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);// 두 번째 손가락 두 번째 마디
			glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
				glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
					glScalef(0.3, 0.2, 0.2); // 두 번째 손가락 두 번째 마디의 크기를 정하고 그린다
					glutWireCube(1.0);
				glPopMatrix();
				glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);// 두 번째 손가락 세 번째 마디
				glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
					glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
						glScalef(0.3, 0.2, 0.2); // 두 번째 손가락 세 번째 마디의 크기를 정하고 그린다
						glutWireCube(1.0);
					glPopMatrix();
		glPopMatrix();

		glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
			glTranslatef(1.0, 0.0, 0.5);// Pivot 지정 및 객체 이동
			glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);// 세 번째 손가락 첫 번째 마디
			glTranslatef(0.2, 0.0, 0.0);// Pivot 으로 지정할 위치를 원점으로 이동
			glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
				glScalef(0.3, 0.2, 0.2); // 세 번째 손가락 첫 번째 마디의 크기를 정하고 그린다
				glutWireCube(1.0);
			glPopMatrix();
			glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
			glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);// 세 번째 손가락 두 번째 마디
			glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
				glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
					glScalef(0.3, 0.2, 0.2); // 세 번째 손가락 두 번째 마디의 크기를 정하고 그린다
					glutWireCube(1.0);
				glPopMatrix();
				glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);// 세 번째 손가락 세 번째 마디
				glTranslatef(0.2, 0.0, 0.0);// Pivot 지정 및 객체 이동
					glPushMatrix();// 원점을 기준으로 객체 생성 및 축소 확대
						glScalef(0.3, 0.2, 0.2); // 세 번째 손가락 세 번째 마디의 크기를 정하고 그린다
						glutWireCube(1.0);
					glPopMatrix();
		glPopMatrix();
	
	glPopMatrix(); //원점으로 돌아감
	glutSwapBuffers();
}

void MyInit(void){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}

void MyReshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void MyTimer1(int Value) { //회전을 총 38번 하게 된다.
	if (check1 > 37) //회전을 38번 이상하면
	{
		check1 = 0; //회전 횟수 0
		return;
	}
	else if (check1 <= 18) //회전을 18번 이하로 하게 되면
	{
		check1 += 1; //회전 횟수 증가
		finger1 = (finger1 + 5) % 180; //손을 구부린다
		glutPostRedisplay(); //재출력
		glutTimerFunc(200, MyTimer1, 1); //콜백함수 등록
	}
	else if (check1 > 18) //회전 횟수가 19이상이면
	{
		check1 += 1; //회전 횟수 증가
		finger1 = (finger1 - 5) % 180; //손을 핀다
		glutPostRedisplay(); //재출력
		glutTimerFunc(200, MyTimer1, 1); //콜백함수 등록
	}
}

void MyTimer2(int Value) { //회전을 총 38번 하게 된다.
	if (check2 > 37) //회전을 38번 이상하면
	{
		check2 = 0; //회전 횟수 0
		return;
	}
	else if (check2 <= 18) //회전을 18번 이하로 하게 되면
	{
		check2 += 1; //회전 횟수 증가
		finger2 = (finger2 + 5) % 180; //손을 구부린다
		glutPostRedisplay(); //재출력
		glutTimerFunc(200, MyTimer2, 1); //콜백함수 등록
	}
	else if (check2 > 18) //회전 횟수가 19이상이면
	{
		check2 += 1; //회전 횟수 증가
		finger2 = (finger2 - 5) % 180; //손을 핀다
		glutPostRedisplay(); //재출력
		glutTimerFunc(200, MyTimer2, 1); //콜백함수 등록
	}
}

void MyTimer3(int Value) { //회전을 총 38번 하게 된다.
	if (check3 > 37) //회전을 38번 이상하면
	{
		check3 = 0; //회전 횟수 0
		return;
	}
	else if (check3 <= 18) //회전을 18번 이하로 하게 되면
	{
		check3 += 1; //회전 횟수 증가
		finger3 = (finger3 + 5) % 180; //손을 구부린다
		glutPostRedisplay(); //재출력
		glutTimerFunc(200, MyTimer3, 1); //콜백함수 등록
	}
	else if (check3 > 18) //회전 횟수가 19이상이면
	{
		check3 += 1; //회전 횟수 증가
		finger3 = (finger3 - 5) % 180; //손을 핀다
		glutPostRedisplay(); //재출력
		glutTimerFunc(200, MyTimer3, 1); //콜백함수 등록
	}
}

void MyTimer_left(int Value) { //좌클릭 타이머 함수
	if (finger1 == 90 && finger2 == 90 && finger3 == 90 && shoulder == 90 && elbow == 90) //모든 관절이 90도가 되면
		return; //멈춘다
	if (finger1 < 90)
		finger1 = (finger1 + 5) % 180; //손가락을 구부린다
	if (finger2 < 90)
		finger2 = (finger2 + 5) % 180; //손가락을 구부린다
	if (finger3 < 90)
		finger3 = (finger3 + 5) % 180; //손가락을 구부린다
	if (shoulder < 90)
		shoulder = (shoulder + 5) % 180; //어깨를 구부린다
	if (elbow < 90)
		elbow = (elbow + 5) % 180; //팔꿈치를 구부린다
	glutPostRedisplay(); //재출력
	glutTimerFunc(200, MyTimer_left, 1); //콜백함수 등록
}

void MyTimer_right(int Value) { //우클릭 타이머 함수
	if (finger1 == 0&& finger2 == 0&& finger3 == 0 && shoulder == 0 && elbow==0) //모든 관절이 0도가 되면
		return; //멈춘다
	if(finger1>0)
		finger1 = (finger1 - 5) % 180; //손가락을 구부린다
	if (finger2 > 0)
		finger2 = (finger2 - 5) % 180; //손가락을 구부린다
	if (finger3 > 0)
		finger3 = (finger3 - 5) % 180; //손가락을 구부린다
	if (shoulder > 0)
		shoulder = (shoulder - 5) % 180; //어깨를 구부린다
	if (elbow > 0)
		elbow = (elbow - 5) % 180; //팔꿈치를 구부린다
	glutPostRedisplay(); //재출력
	glutTimerFunc(200, MyTimer_right, 1); //콜백함수 등록
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case'1':
		glutTimerFunc(200, MyTimer1, 1); //콜백함수 등록
		break;
	case'2':
		glutTimerFunc(200, MyTimer2, 1); //콜백함수 등록
		break;
	case'3':
		glutTimerFunc(200, MyTimer3, 1); //콜백함수 등록
		break;
	case's':
		shoulder = (shoulder + 5) % 180; //어깨를 구부린다
		break;
	case'S':
		shoulder = (shoulder - 5) % 180; //어깨를 핀다
		break;
	case'e':
		elbow = (elbow + 5) % 180; //팔꿈치를 구부린다
		break;
	case'E':
		elbow = (elbow - 5) % 180; //팔꿈치를 핀다
		break;
	case 27: 
		exit(0); //종료한다
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { //마우스 왼쪽버튼이 눌린채로
		glutTimerFunc(200, MyTimer_left, 1); //콜백함수 등록
	}
	else if(Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN)//아니면
		glutTimerFunc(200, MyTimer_right, 1); //콜백함수 등록
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot Arm");
	MyInit();
	glutDisplayFunc(MyDisplay); //디스플레이 함수 등록
	glutReshapeFunc(MyReshape); //reshape함수 등록
	glutKeyboardFunc(MyKeyboard); //키보드함수 등록
	glutMouseFunc(MyMouseClick); //마우스클릭함수 등록
	glutMainLoop();
	return 0;
}