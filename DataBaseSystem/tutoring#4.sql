create schema DBMS_tutoring;

use DBMS_tutoring;

CREATE table TEACHER(
	TEACHER_NO INTEGER NOT NULL,
    NAME CHAR(10) NOT NULL,
    constraint TEACHER_PK primary key(TEACHER_NO)
);

create table STUDENT(
	STUDENT_NO INTEGER NOT NULL,
	NAME CHAR(10) NOT NULL,
    FNO INTEGER,
	TNO INTEGER,
    constraint STUDENT_PK primary key(STUDENT_NO)
);

INSERT INTO TEACHER
VALUES  (1, '김선생'),
		(2, '박선생');

INSERT INTO STUDENT(STUDENT_NO, NAME, FNO, TNO)
VALUES  (1801, '박수학', NULL, 2),
		(1901, '한영어', 1801, 1),
        (1902, '김국어', 1901, 2),
        (1701, '최사회', 1902, 1),
        (1702, '신과학', 1701, 1),
        (1601, '윤역사', 1902, 2);

/* 문제1 : 모든 선생님 출력 */
SELECT * FROM TEACHER;

/* 문제2 : 이름이 ~~학 또는 ~~어로 끝나고 선생님번호(TNO)가 2 아닌 학생이름만 출력 */
SELECT NAME FROM STUDENT WHERE (NAME LIKE'%학' OR NAME LIKE '%어') AND NOT TNO='2';

/* 문제3 : 학번, 이름, 선생님번호(TNO), A(=학번x선생님번호) 출력 */
SELECT STUDENT_NO, NAME, TNO, STUDENT_NO * TNO AS A FROM STUDENT;
