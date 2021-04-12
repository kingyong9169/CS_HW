/********************************************************/
/*               HW#4 : Callback 프로그램-마우스콜백(2) */
/*       작성자 : 김동용         날짜 : 2020년 10월 19일*/
/*              문제 정의 : 마우스 클릭으로 도형 그리기 */
/*                     - - - - - - -                    */
/********************************************************/
#include< GL/glut.h>
GLboolean IsSphere = true; //sphere, torus, teapot, small여부를 알려주는 변수
GLboolean IsTorus = true;
GLboolean IsTeapot= true;
GLboolean IsSmall = true;

GLfloat R=1.0, G=0.0, B=0.0;
void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(R, G, B);

	if ((IsSphere) && (IsSmall)&& (!IsTeapot)&& (!IsTorus)) // small sphere이면
		glutWireSphere(0.5, 30, 30); //small shpere출력
	else if ((IsSphere) && (!IsSmall)&&(!IsTeapot) && (!IsTorus)) // large sphere이면
		glutWireSphere(0.7, 30, 30); // large sphere출력
	else if ((IsTorus) && (IsSmall)&&(!IsSphere) && (!IsTeapot)) // small torus이면
		glutWireTorus(0.1, 0.3, 40, 20); // small torus출력
	else if ((IsTorus) && (!IsSmall) && (!IsSphere) && (!IsTeapot)) // large torus이면
		glutWireTorus(0.2, 0.5, 40, 20); // large torus출력
	else if (IsTeapot && (IsSmall) && (!IsSphere) && (!IsTorus)) // small teapot이면
		glutWireTeapot(0.3);  // small teapot출력
	else if (IsTeapot && (!IsSmall) && (!IsSphere) && (!IsTorus)) // large teapot이면
		glutWireTeapot(0.5); // large teapot출력
	glFlush();
}

void MySphereMenu(int entryID) { //sphere메뉴
	if (entryID == 1) { IsSphere = true; IsTeapot = false; IsTorus = false; IsSmall = true; } //small sphere
	else if (entryID == 2) { IsSphere = true; IsTeapot = false; IsTorus = false; IsSmall = false;} //large sphere
	glutPostRedisplay();
}

void MyTorusMenu(int entryID) { //torus메뉴
	if (entryID == 1) { IsSphere = false; IsTeapot = false; IsTorus = true; IsSmall = true; } //small torus
	else if (entryID == 2) { IsSphere = false; IsTeapot = false; IsTorus = true; IsSmall = false; } //large torus
	glutPostRedisplay();
}

void MyTeapotMenu(int entryID) { //teapot메뉴
	if (entryID == 1) { IsSphere = false; IsTeapot = true; IsTorus = false; IsSmall = true; } //small teapot
	else if (entryID == 2) { IsSphere = false; IsTeapot = true; IsTorus = false; IsSmall = false; } //large teapot
	glutPostRedisplay();
}

void MyMainMenu(int entryID) { //메인메뉴
	if (entryID == 4) exit(0); //exit를 추가해줌
	glutPostRedisplay();
}

void MyColorMenu(int entryID) { //컬러메뉴
	if (entryID == 1) { R = 1.0, G = 0.0, B = 0.0; } //빨간색으로
	else if (entryID == 2) { R = 0.0, G = 1.0, B = 0.0; } //초록색으로
	else if (entryID == 3) { R = 0.0, G = 0.0, B = 1.0; } //파란색으로
	glutPostRedisplay();
}

void MyInit(){ //메뉴 초기화
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	
	GLint MySphereID = glutCreateMenu(MySphereMenu); //sphere메뉴
	glutAddMenuEntry(" Small Sphere", 1);
	glutAddMenuEntry(" large Sphere", 2);

	GLint MyTorusID = glutCreateMenu(MyTorusMenu); //torus 메뉴
	glutAddMenuEntry(" Small Torus", 1);
	glutAddMenuEntry(" large Torus", 2);

	GLint MyTeapotID = glutCreateMenu(MyTeapotMenu); //teapot메뉴
	glutAddMenuEntry(" Small Teapot", 1);
	glutAddMenuEntry(" large Teapot", 2);

	GLint MyColorID = glutCreateMenu(MyColorMenu); //color메누
	glutAddMenuEntry(" Red", 1);
	glutAddMenuEntry(" Green", 2);
	glutAddMenuEntry(" Blue", 3);
	
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //메인메뉴 등록
	glutAddSubMenu(" Draw Sphere", MySphereID); //서브메뉴를 출력
	glutAddSubMenu(" Draw Torus", MyTorusID); //서브메뉴를 출력
	glutAddSubMenu(" Draw Teapot", MyTeapotID); //서브메뉴를 출력
	glutAddSubMenu(" Change Color", MyColorID); //서브메뉴를 출력
	glutAddMenuEntry(" Exit", 4); //메인메뉴의 exit출력
	glutAttachMenu(GLUT_RIGHT_BUTTON); //오른쪽 마우스 클릭하면 메뉴 팝업
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Menu Callback");
	MyInit();
	glutDisplayFunc(MyDisplay); //디스플레이 함수 등록
	glutMainLoop();
	return 0;
}