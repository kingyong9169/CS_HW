///********************************************************/
///*                                term project : �渶�� */
///*        �ۼ��� : �赿��         ��¥ : 2020�� 12�� 8��*/
///*             ���� ���� : ��� ������ �̿��� �� �𵨸� */
///*                     - - - - - - -                    */
///********************************************************/
#include<gl/glut.h>

int Width, Height; //ȭ�� ���� ��, ����
GLfloat x = 0.0, y = 0.0, z = 0.0; //ī�޶� ��ġ�� ���� ����
GLfloat fx = 0.0, fy = 0.0, fz = 0.0; //ī�޶� ������ ���� ����
GLfloat Widthfactor, Heightfactor; //ȭ�� ���� ��, ������ ����
GLfloat posX = 0.0, posY = 0.0, posZ[2] = { 0 }; //���� ��ġ
GLfloat R = 0, G = 0, B = 0; //���� ����
GLfloat bkR = 0.529412, bkG = 0.807843, bkB = 0.980392; //��� ��
GLfloat pos[4] = { 5.0 , 5.0 , 5.0 , 1.0 };//���� ��ġ

struct joint { //���� �κ�
	GLfloat x = 0, y = 0, z = 0; //���� ���� ��ȯ
	GLfloat neckbt = -80; //�� ��
	GLfloat necktp = 0; //�� �Ʒ�
	GLfloat head = 90; //�Ӹ�

	GLfloat frtLLegtp = 90; //�տ��ʴٸ� ��
	GLfloat frtLLegbt = 10; //�տ��ʴٸ� �Ʒ�
	GLfloat frtRLegtp = 90; //�տ����ʴٸ� ��
	GLfloat frtRlegbt = 10; //�տ����ʴٸ� �Ʒ�

	GLfloat bkLLegtp = 90; //�ڿ��ʴٸ� ��
	GLfloat bkLLegbt = 10; //�ڿ��ʴٸ� �Ʒ�
	GLfloat bkRLegtp = 90; //�ڿ����ʴٸ� ��
	GLfloat bkRLegbt = 10; //�ڿ����ʴٸ� �Ʒ�

	GLfloat tail = -50; //����
}puppy[3];

GLUquadricObj* g_normalObject = NULL;
GLfloat horsex = 0, horsey = 1;
void DrawHorse1(int i) {
	//���� ����
	glPushMatrix();
	glRotated(puppy[i].x, 0, 1, 0);
	glTranslated(i, 1, -(i + .7) + posZ[i]);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glColor3f(R + i - 0.3, G + i - 0.3, B + i - 0.3);
	gluCylinder(g_normalObject, 0.35, 0.4, 1.4, 20, 8);
	glPushMatrix(); //���� ���� �պκ�, �޺κп� ��ũ �׸���
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);
	glPopMatrix();

	//���� �� �Ʒ��κ�
	glPushMatrix();
	glTranslatef(0, .4, 1.2);
	glRotated(puppy[i].neckbt, 1, 0, 0);
	gluCylinder(g_normalObject, 0.2, 0.19, 0.5, 20, 8);

	//���� �� ���κ�
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].necktp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.19, 0.10, 0.5, 20, 8);

	//���� �Ӹ�
	glPushMatrix();
	glTranslatef(0, 0, .5);
	glRotated(puppy[i].head, 1, 0, 0);
	gluCylinder(g_normalObject, 0.2, 0.1, 0.6, 20, 8);

	//���� ��
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

	//���� �մٸ� ���κ�
	glPushMatrix();
	glTranslatef(0.15, -.3, 1.3);
	glRotated(puppy[i].frtLLegtp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.1, 0.6, 20, 8);

	//���� �մٸ� �Ʒ��κ�
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].frtLLegbt, 10, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.13, 0.67, 20, 8);
	glPopMatrix();
	glPopMatrix();

	//������ �մٸ� ���κ�
	glPushMatrix();
	glTranslatef(-.15, -.3, 1.3);
	glRotated(puppy[i].frtRLegtp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.1, 0.6, 20, 8);

	//������ �մٸ� �Ʒ��κ�
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].frtRlegbt, 10, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.13, 0.67, 20, 8);
	glPopMatrix();
	glPopMatrix();

	//���� �޴ٸ� ���κ�
	glPushMatrix();
	glTranslatef(0.15, -.3, 0.15);
	glRotated(puppy[i].bkLLegtp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.15, 0.1, 0.6, 20, 8);

	//���� �޴ٸ� �Ʒ��κ�
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].bkLLegbt, -10, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.13, 0.67, 20, 8);
	glPopMatrix();
	glPopMatrix();

	//������ �޴ٸ� ���κ�
	glPushMatrix();
	glTranslatef(-0.15, -.3, 0.15);
	glRotated(puppy[i].bkRLegtp, 1, 0, 0);
	gluCylinder(g_normalObject, 0.15, 0.1, 0.6, 20, 8);

	//������ �޴ٸ� �Ʒ��κ�
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotated(puppy[i].bkRLegbt, -10, 0, 0);
	gluCylinder(g_normalObject, 0.1, 0.13, 0.67, 20, 8);
	glPopMatrix();
	glPopMatrix();

	//���� ����
	glPushMatrix();
	glRotated(puppy[i].tail, 1, puppy[i].z, 0);
	glTranslated(0, 0.07, -0.5);
	gluCylinder(g_normalObject, 0.1, 0.1, 0.8, 40, 18);
	glPopMatrix();
	glPopMatrix(); //�� ����� ��
}
void DrawWood(int i) {
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(5 + 2 * i, 1, -(5 + .7 + 2 * i));
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glColor3f(0.647059, 0.164706, 0.164706);
	glPushMatrix(); //���� ���� �պκ�, �޺κп� ��ũ �׸���
	gluCylinder(g_normalObject, 0.4, 0.4, 1.4, 20, 8);
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);

	glPushMatrix(); //���� ���� �պκ�, �޺κп� ��ũ �׸���
	gluCylinder(g_normalObject, 0.4, 0.4, 1.4, 20, 8);
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);
	glPushMatrix(); //���� ���� �պκ�, �޺κп� ��ũ �׸���
	gluCylinder(g_normalObject, 0.4, 0.4, 1.4, 20, 8);
	gluDisk(g_normalObject, 0, 0.35, 20, 8);
	glTranslated(0, 0, 1.4);
	gluDisk(g_normalObject, 0, 0.4, 20, 8);
	glPushMatrix(); //���� ���� �պκ�, �޺κп� ��ũ �׸���
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
void Draw() { //���� �� ����, �� 2���� �׸���
	glColor3f(0, 1, 0.498039);
	glPushMatrix(); //��� ����
	glTranslatef(0.0, 0, 0.0);
	glBegin(GL_QUADS); //���� �׸���
	glVertex3f(20.0, 0.0, 20.0); //������ ��ǥ��
	glVertex3f(20.0, 0.0, -20.0);
	glVertex3f(-20.0, 0.0, -20.0);
	glVertex3f(-20.0, 0.0, 20.0);
	glEnd();
	glPopMatrix(); //��� ��

	DrawWood(5); //���� �׸���
	DrawHorse1(0); //��1 �׸���
	DrawHorse1(1); //��2 �׸���
}

void MyDisplay() { //���÷��� �Լ�
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //���� ����
	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); //��� ����
	glLoadIdentity(); //�׵���ķ� �ʱ�ȭ
	gluPerspective(30, 1.0 * Widthfactor / Heightfactor, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix(); //��� ����
	gluLookAt(25.0 + x, 30.0 + y, 15.0 + z, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 20.0, 0.0); //�� ��ǥ�� ���� ��ȯ
	Draw(); //drawscene�Լ� ȣ��
	glPopMatrix(); //��� ��

	glMatrixMode(GL_PROJECTION);
	glPopMatrix(); //��� ��

	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) { //reshape �Լ�
	glViewport(0, 0, NewWidth, NewHeight); //���ο� ȭ�� ��ǥ�� ���� ��ȯ
	Width = NewWidth; //width�� ���ο� width ����
	Height = NewHeight; //height�� ���ο� height ����
	// �̺�Ʈ�����غ���Ʈ�����ӰԹ������οͼ��α��̷μ����մϴ�.
	Widthfactor = (GLfloat)NewWidth / (GLfloat)500; //���ο� width�� ����
	Heightfactor = (GLfloat)NewHeight / (GLfloat)500; //���ο� height�� ����
	// �̺�Ʈ�����ػ��ӰԹ������οͼ��θ����Ͽ��������������մϴ�.
}

void InitVisibility() {
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_FILL);
	glCullFace(GL_FRONT);
	glEnable(GL_DEPTH_TEST);
}

void MySpecial(int key, int pos1, int pos2) { //ī�޶� ��ġ�� �ٲ���
	switch (key) {
	case GLUT_KEY_RIGHT: //������ ����Ű
		x += 0.3; //ī�޶��� ��ġx�� 0.1����
		break;
	case GLUT_KEY_LEFT: //���� ����Ű
		x -= 0.3; //ī�޶��� ��ġx�� 0.1����
		break;
	case GLUT_KEY_UP: //���� ����Ű
		y += 0.3; //ī�޶��� ��ġy�� 0.1����
		break;
	case GLUT_KEY_DOWN: //�Ʒ��� ����Ű
		y -= 0.3; //ī�޶��� ��ġy�� 0.1����
		break;
	}
	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int pos1, int pos2) { //ī�޶� ������ �ٲ���
	switch (key) {
	case 'q': //q, QŰ ������ 
	case 'Q':
		fx += 0.3; //ī�޶� �ٶ󺸴� ���� x�� ��ġ�� 0.3����
		break;
	case 'f': //f, FŰ ������ 
	case 'F':
		fx -= 0.3; //ī�޶� �ٶ󺸴� ���� x�� ��ġ�� 0.3����
		break;
	case 'r': //r, RŰ ������
	case 'R':
		fy += 0.3; //ī�޶� �ٶ󺸴� ���� y�� ��ġ�� 0.3����
		break;
	case 'v': //b, BŰ ������
	case 'V':
		fy -= 0.3; //ī�޶� �ٶ󺸴� ���� y�� ��ġ�� 0.3����
		break;
	case 'z': //b, BŰ ������
	case 'Z':
		fz += 0.3; //ī�޶� �ٶ󺸴� ���� z�� ��ġ�� 0.3����
		break;
	case 't': //t, TŰ ������
	case 'T':
		fz -= 0.3; //ī�޶� �ٶ󺸴� ���� z�� ��ġ�� 0.3����
		break;
	case 'w': //����
	case 'W':
		if (puppy[0].frtLLegtp <= 105 && puppy[0].frtRLegtp >= 75 && puppy[0].bkLLegtp >= 75 && puppy[0].bkRLegtp <= 115) {
			if (puppy[0].neckbt <= -80 && puppy[0].necktp >= 0) {
				puppy[0].neckbt += 20; //�� ��
				puppy[0].necktp += 20; //�� �Ʒ�
			}
			else if (puppy[0].neckbt >= -60 && puppy[0].necktp <= 20) {
				puppy[0].neckbt -= 20; //�� ��
				puppy[0].necktp -= 20; //�� �Ʒ�
			}
			puppy[0].frtLLegtp += 15; //�տ��ʴٸ� ��
			puppy[0].frtRLegtp -= 15; //�տ����ʴٸ� ��
			puppy[0].bkLLegtp -= 15; //�տ��ʴٸ� ��
			puppy[0].bkRLegtp += 15; //�տ����ʴٸ� ��
		}
		else if (puppy[0].frtLLegtp >= 90 && puppy[0].frtRLegtp <= 90 && puppy[0].bkLLegtp <= 90 && puppy[0].bkRLegtp >= 90) {
			if (puppy[0].neckbt <= -80 && puppy[0].necktp >= 0) {
				puppy[0].neckbt += 20; //�� ��
				puppy[0].necktp += 20; //�� �Ʒ�
			}
			else if (puppy[0].neckbt >= -60 && puppy[0].necktp <= 20) {
				puppy[0].neckbt -= 20; //�� ��
				puppy[0].necktp -= 20; //�� �Ʒ�
			}
			puppy[0].frtLLegtp -= 15; //�տ��ʴٸ� ��
			puppy[0].frtRLegtp += 15; //�տ����ʴٸ� ��
			puppy[0].bkLLegtp += 15; //�տ��ʴٸ� ��
			puppy[0].bkRLegtp -= 15; //�տ����ʴٸ� ��
		}
		posZ[0] += 0.5;
		break;
	case 's': //����
	case 'S':
		if (puppy[0].frtLLegtp <= 105 && puppy[0].frtRLegtp >= 75 && puppy[0].bkLLegtp >= 75 && puppy[0].bkRLegtp <= 115) {
			if (puppy[0].neckbt <= -80 && puppy[0].necktp >= 0) {
				puppy[0].neckbt += 20; //�� ��
				puppy[0].necktp += 20; //�� �Ʒ�
			}
			else if (puppy[0].neckbt >= -60 && puppy[0].necktp <= 20) {
				puppy[0].neckbt -= 20; //�� ��
				puppy[0].necktp -= 20; //�� �Ʒ�
			}
			puppy[0].frtLLegtp += 15; //�տ��ʴٸ� ��
			puppy[0].frtRLegtp -= 15; //�տ����ʴٸ� ��
			puppy[0].bkLLegtp -= 15; //�տ��ʴٸ� ��
			puppy[0].bkRLegtp += 15; //�տ����ʴٸ� ��
		}
		else if (puppy[0].frtLLegtp >= 90 && puppy[0].frtRLegtp <= 90 && puppy[0].bkLLegtp <= 90 && puppy[0].bkRLegtp >= 90) {
			if (puppy[0].neckbt <= -80 && puppy[0].necktp >= 0) {
				puppy[0].neckbt += 20; //�� ��
				puppy[0].necktp += 20; //�� �Ʒ�
			}
			else if (puppy[0].neckbt >= -60 && puppy[0].necktp <= 20) {
				puppy[0].neckbt -= 20; //�� ��
				puppy[0].necktp -= 20; //�� �Ʒ�
			}
			puppy[0].frtLLegtp -= 15; //�տ��ʴٸ� ��
			puppy[0].frtRLegtp += 15; //�տ����ʴٸ� ��
			puppy[0].bkLLegtp += 15; //�տ��ʴٸ� ��
			puppy[0].bkRLegtp -= 15; //�տ����ʴٸ� ��
		}
		posZ[0] -= 0.5;
		break;
	case 'd': //���������� ������ȯ
	case 'D':
		puppy[0].x -= 10;
		break;
	case 'a': //�������� ������ȯ
	case 'A':
		puppy[0].x += 10;
		break;
	case 'i': //����
	case 'I':
		if (puppy[1].frtLLegtp <= 105 && puppy[1].frtRLegtp >= 75 && puppy[1].bkLLegtp >= 75 && puppy[1].bkRLegtp <= 115) {
			if (puppy[1].neckbt <= -80 && puppy[1].necktp >= 0) {
				puppy[1].neckbt += 20; //�� ��
				puppy[1].necktp += 20; //�� �Ʒ�
			}
			else if (puppy[1].neckbt >= -60 && puppy[1].necktp <= 20) {
				puppy[1].neckbt -= 20; //�� ��
				puppy[1].necktp -= 20; //�� �Ʒ�
			}
			puppy[1].frtLLegtp += 15; //�տ��ʴٸ� ��
			puppy[1].frtRLegtp -= 15; //�տ����ʴٸ� ��
			puppy[1].bkLLegtp -= 15; //�տ��ʴٸ� ��
			puppy[1].bkRLegtp += 15; //�տ����ʴٸ� ��
		}
		else if (puppy[1].frtLLegtp >= 90 && puppy[1].frtRLegtp <= 90 && puppy[1].bkLLegtp <= 90 && puppy[1].bkRLegtp >= 90) {
			if (puppy[1].neckbt <= -80 && puppy[1].necktp >= 0) {
				puppy[1].neckbt += 20; //�� ��
				puppy[1].necktp += 20; //�� �Ʒ�
			}
			else if (puppy[1].neckbt >= -60 && puppy[1].necktp <= 20) {
				puppy[1].neckbt -= 20; //�� ��
				puppy[1].necktp -= 20; //�� �Ʒ�
			}
			puppy[1].frtLLegtp -= 15; //�տ��ʴٸ� ��
			puppy[1].frtRLegtp += 15; //�տ����ʴٸ� ��
			puppy[1].bkLLegtp += 15; //�տ��ʴٸ� ��
			puppy[1].bkRLegtp -= 15; //�տ����ʴٸ� ��
		}
		posZ[1] += 0.5;
		break;
	case 'k': //����
	case 'K':
		if (puppy[1].frtLLegtp <= 105 && puppy[1].frtRLegtp >= 75 && puppy[1].bkLLegtp >= 75 && puppy[1].bkRLegtp <= 115) {
			if (puppy[1].neckbt <= -80 && puppy[1].necktp >= 0) {
				puppy[1].neckbt += 20; //�� ��
				puppy[1].necktp += 20; //�� �Ʒ�
			}
			else if (puppy[1].neckbt >= -60 && puppy[1].necktp <= 20) {
				puppy[1].neckbt -= 20; //�� ��
				puppy[1].necktp -= 20; //�� �Ʒ�
			}
			puppy[1].frtLLegtp += 15; //�տ��ʴٸ� ��
			puppy[1].frtRLegtp -= 15; //�տ����ʴٸ� ��
			puppy[1].bkLLegtp -= 15; //�տ��ʴٸ� ��
			puppy[1].bkRLegtp += 15; //�տ����ʴٸ� ��
		}
		else if (puppy[1].frtLLegtp >= 90 && puppy[1].frtRLegtp <= 90 && puppy[1].bkLLegtp <= 90 && puppy[1].bkRLegtp >= 90) {
			if (puppy[1].neckbt <= -80 && puppy[1].necktp >= 0) {
				puppy[1].neckbt += 20; //�� ��
				puppy[1].necktp += 20; //�� �Ʒ�
			}
			else if (puppy[1].neckbt >= -60 && puppy[1].necktp <= 20) {
				puppy[1].neckbt -= 20; //�� ��
				puppy[1].necktp -= 20; //�� �Ʒ�
			}
			puppy[1].frtLLegtp -= 15; //�տ��ʴٸ� ��
			puppy[1].frtRLegtp += 15; //�տ����ʴٸ� ��
			puppy[1].bkLLegtp += 15; //�տ��ʴٸ� ��
			puppy[1].bkRLegtp -= 15; //�տ����ʴٸ� ��
		}
		posZ[1] -= 0.5;
		break;
	case 'l': //���������� ������ȯ
	case 'L':
		puppy[1].x -= 10;
		break;
	case 'j': //�������� ������ȯ
	case 'J':
		puppy[1].x += 10;
		break;
	}
	glutPostRedisplay(); //������ ���÷���
}

void MyColorMenu(int entryID) { //�÷��޴�
	if (entryID == 1) { R = 1.0, G = 0.0, B = 0.0; } //����������
	else if (entryID == 2) { R = 1.0, G = 1.0, B = 0.0; } //���������
	else if (entryID == 3) { R = 1.0, G = 0.0, B = 1.0; } //���������
	else if (entryID == 4) { R = 0.0, G = 0.0, B = 0.0; } //����������
	else if (entryID == 5) exit(0); //exit�� �߰�����
	glutPostRedisplay();
}

void MyIdle() {  //�ƹ� �̺�Ʈ�� ���� �ÿ� ����Ǵ� �ݹ��Լ��� �� �ȿ��� specialkeyboardcallback�� ����ϸ鼭 Ȱ����
	glutSpecialFunc(MySpecial); //�ݹ��Լ� ���
	glutPostRedisplay(); //������ ���÷���
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //������ ũ�⸦ �ٲ���
	if (Button == GLUT_LEFT_BUTTON) { //���콺 ���ʹ�ư�� ����ä��
		if (puppy[0].z <= 0) { //������ ����
			puppy[0].z += 3;
			puppy[1].z += 3;
		}
		else if (puppy[0].z >= 3) { //������ ����
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
	glutPostRedisplay(); //�����
	glutTimerFunc(400, MyTimer, 1); //�ݹ��Լ� ���
}

void MyInit() { //�޴� �ʱ�ȭ
	g_normalObject = gluNewQuadric();
	glClearColor(bkR, bkG, bkB, 0); //��� �� �ʱ�ȭ
	glMatrixMode(GL_PROJECTION); //���� ����
	glLoadIdentity(); //�׵���ķ� �ʱ�ȭ
	glOrtho(-20.0 * Widthfactor, 20.0 * Widthfactor, -20.0 * Heightfactor, 20.0 * Heightfactor, 5, 50); //���ú��Ǹ� ȭ�� ������ ����

	GLint MyColorID = glutCreateMenu(MyColorMenu); //color�޴�
	glutAddMenuEntry(" Red", 1);
	glutAddMenuEntry(" Yellow", 2);
	glutAddMenuEntry(" Purple", 3);
	glutAddMenuEntry(" Black", 4);
	glutAddMenuEntry(" Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON); //������ ���콺 Ŭ���ϸ� �޴� �˾�
}

void InitLight() {
	GLfloat light0_ambient[] = { 0.0, 0.4, 0.0, 1.0 }; //�ֺ���
	GLfloat light0_diffuse[] = { 1.0, 0.5, 1.0, 1.0 }; //Ȯ�걤
	GLfloat light0_specular[] = { 0.4, 1.0, 0.8, 1.0 }; //��鱤
	glEnable(GL_DEPTH_TEST); //���� ���� Ȱ��ȭ
	glShadeModel(GL_SMOOTH); // Gouraud ���̵����� ����
	glEnable(GL_LIGHTING); //���� Ȱ��ȭ
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); //�ֺ���
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); //�ݻ籤
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); //��鱤
	glEnable(GL_COLOR_MATERIAL); //����� ���ÿ� ���� ������ ����Ѵ�
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	Width = 1200; //â�� ũ��
	Height = 1000; //â�� ũ��
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); //���÷��̸�带 �̱�, RGBA�� �ʱ�ȭ
	glutInitWindowSize(Width, Height); //������ ������ �ʱ�ȭ
	glutInitWindowPosition(0, 0); //window��ǥ �ʱ�ȭ
	glutCreateWindow("horse in the hall"); //���α׷� �̸�
	MyInit(); //�ʱ�ȭ�Լ�
	InitLight(); //���� �Լ�
	glutDisplayFunc(MyDisplay); //���÷��� �Լ� ���
	glutIdleFunc(MyIdle); //���̵� �Լ� ���
	glutKeyboardFunc(MyKeyboard); //Ű���� �Լ� ���
	glutMouseFunc(MyMouseClick); //���콺Ŭ���Լ� ���
	glutReshapeFunc(MyReshape); //reshape�ݹ� �Լ� ���
	glutTimerFunc(400, MyTimer, 1); //Ÿ�̸��Լ� ���
	InitVisibility();
	glutMainLoop(); //�����Լ�
	return 0;
}