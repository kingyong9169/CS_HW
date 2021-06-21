/***************************************************/
/*           HW#5-1 : �¾�� �𵨸� Ȯ��           */
/*  �ۼ��� : �赿��     ��¥ : 2020�� 11�� 10��    */
/*                                                 */
/* ���� ���� : �¾�, ����, �ݼ�, ����, �� 4���� �༺ �𵨸�*/
/*                - - - - - - -                    */
/***************************************************/

#include <gl/glut.h>

bool check;
static int Day = 0, Time1 = 0, Time2 = 0, Time3 = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); //�׵���ķ� �ʱ�ȭ

    glColor3f(1.0, 0.3, 0.3); //�¾�
    glutWireSphere(0.2, 20, 16); //�¾��� �׸�
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0); //y���� �������� Day��ŭ ȸ��
        glPushMatrix(); //0,0,0�� push
    
    glTranslatef(0.3, 0.0, 0.0); //��ǥ�� �Ű��ش�
    glColor3f(0.4, 0.4, 0.4); //����
    glutWireSphere(0.06, 10, 8); //������ �׸�
    glRotatef((GLfloat)Time1, 0.0, 1.0, 0.0); //y���� �������� Day��ŭ ȸ��
        glPopMatrix(); //0.3,0,0�� pop

    
        glPushMatrix(); //0.0,0,0�� push
    glTranslatef(0.5, 0.0, 0.0); //�׵���ķ� �ʱ�ȭ
    glColor3f(0.8, 0.8, 0.9); //�ݼ�
    glutWireSphere(0.11, 10, 8); //�ݼ��� �׸�
    glRotatef((GLfloat)Time2, 0.0, 1.0, 0.0); //y���� �������� Day��ŭ ȸ��
        glPopMatrix(); //0,0,0�� pop

        glPushMatrix(); //0,0,0�� push
    glTranslatef(0.8, 0.0, 0.0); //�׵���ķ� �ʱ�ȭ
    glColor3f(0.3, 0.8, 0.9); //����
    glutWireSphere(0.1, 10, 8); //������ �׸�
            glPushMatrix(); //0.8,0,0�� push
    glRotatef((GLfloat)Time3, 0.0, 1.0, 0.0); //y�� Time3��ŭ ȸ��
    glTranslatef(0.15, 0.0, 0.0); //�׵���ķ� �ʱ�ȭ

    glColor3f(0.9, 0.5, 0.9);//��
    glutWireSphere(0.04, 10, 8); //���� �׸�
            glPopMatrix(); //1.6,0,0�� pop
        glPopMatrix(); //0.8,0,0�� pop
    glutSwapBuffers(); //���۸� �ٲ��ش�.
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
    if (check) { //���ʹ�ư�� ������
        Day = (Day + 10) % 360; //�¾��� �����ӵ�
        Time1 = (Time1 + 10) % 360; //������ �����ӵ�
        Time2 = (Time2 + 20) % 360; //�ݼ��� �����ӵ�
        Time3 = (Time3 + 30) % 360; //������ �����ӵ�
    }
    glutPostRedisplay(); //ȭ�� �ֽ�ȭ
    glutTimerFunc(80, MyTimer, 1); //�ݹ��Լ� ���
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
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //���ú��� ����
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick); //���콺Ŭ���Լ� ���
    glutTimerFunc(80, MyTimer, 1); //�ݹ��Լ� ���
    glutMainLoop();
    return 0;
}