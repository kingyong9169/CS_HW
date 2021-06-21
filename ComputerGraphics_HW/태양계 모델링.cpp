/***************************************************/
/*           HW#5-1 : 태양계 모델링 확장           */
/*  작성자 : 김동용     날짜 : 2020년 11월 10일    */
/*                                                 */
/* 문제 정의 : 태양, 수성, 금성, 지구, 달 4개의 행성 모델링*/
/*                - - - - - - -                    */
/***************************************************/

#include <gl/glut.h>

bool check;
static int Day = 0, Time1 = 0, Time2 = 0, Time3 = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); //항등행렬로 초기화

    glColor3f(1.0, 0.3, 0.3); //태양
    glutWireSphere(0.2, 20, 16); //태양을 그림
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0); //y축을 기준으로 Day만큼 회전
        glPushMatrix(); //0,0,0을 push
    
    glTranslatef(0.3, 0.0, 0.0); //좌표를 옮겨준다
    glColor3f(0.4, 0.4, 0.4); //수성
    glutWireSphere(0.06, 10, 8); //수성을 그림
    glRotatef((GLfloat)Time1, 0.0, 1.0, 0.0); //y축을 기준으로 Day만큼 회전
        glPopMatrix(); //0.3,0,0을 pop

    
        glPushMatrix(); //0.0,0,0을 push
    glTranslatef(0.5, 0.0, 0.0); //항등행렬로 초기화
    glColor3f(0.8, 0.8, 0.9); //금성
    glutWireSphere(0.11, 10, 8); //금성을 그림
    glRotatef((GLfloat)Time2, 0.0, 1.0, 0.0); //y축을 기준으로 Day만큼 회전
        glPopMatrix(); //0,0,0을 pop

        glPushMatrix(); //0,0,0을 push
    glTranslatef(0.8, 0.0, 0.0); //항등행렬로 초기화
    glColor3f(0.3, 0.8, 0.9); //지구
    glutWireSphere(0.1, 10, 8); //지구을 그림
            glPushMatrix(); //0.8,0,0을 push
    glRotatef((GLfloat)Time3, 0.0, 1.0, 0.0); //y를 Time3만큼 회전
    glTranslatef(0.15, 0.0, 0.0); //항등행렬로 초기화

    glColor3f(0.9, 0.5, 0.9);//달
    glutWireSphere(0.04, 10, 8); //달을 그림
            glPopMatrix(); //1.6,0,0을 pop
        glPopMatrix(); //0.8,0,0을 pop
    glutSwapBuffers(); //버퍼를 바꿔준다.
}

void MyMouseClick(GLint button, GLint state, GLint x, GLint y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        check = true;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        check = false;
    }
}

void MyTimer(int value) {
    if (check) { //왼쪽버튼을 누르면
        Day = (Day + 10) % 360; //태양의 자전속도
        Time1 = (Time1 + 10) % 360; //수성의 공전속도
        Time2 = (Time2 + 20) % 360; //금성의 공전속도
        Time3 = (Time3 + 30) % 360; //지구의 공전속도
    }
    glutPostRedisplay(); //화면 최신화
    glutTimerFunc(80, MyTimer, 1); //콜백함수 등록
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Solar System");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //가시부피 설정
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick); //마우스클릭함수 등록
    glutTimerFunc(80, MyTimer, 1); //콜백함수 등록
    glutMainLoop();
    return 0;
}