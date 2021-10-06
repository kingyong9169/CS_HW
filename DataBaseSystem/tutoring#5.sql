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
VALUES (2001, '강음악', 1801, 1);

INSERT INTO STUDENT(STUDENT_NO, NAME, FNO, TNO)
VALUES  (1801, '박수학', NULL, 2),
		(1901, '한영어', 1801, 1),
        (1902, '김국어', 1901, 2),
        (1701, '최사회', 1902, 1),
        (1702, '신과학', 1701, 1),
        (1601, '윤역사', 1902, 2);

/* 문제1 : 모든 선생님 출력 */
SELECT * FROM TEACHER;
SELECT * FROM STUDENT;

/* 문제2 : 이름이 ~~학 또는 ~~어로 끝나고 선생님번호(TNO)가 2 아닌 학생이름만 출력 */
SELECT NAME FROM STUDENT WHERE (NAME LIKE'%학' OR NAME LIKE '%어') AND NOT TNO='2';

/* 문제3 : 학번, 이름, 선생님번호(TNO), A(=학번x선생님번호) 출력 */
SELECT STUDENT_NO, NAME, TNO, STUDENT_NO * TNO AS A FROM STUDENT;

/* 문제1 : TNO가 1인 모든 STUDENT TABLE의 값들을 학번의 내림차순으로 정렬하여 출력 */
SELECT * FROM STUDENT WHERE TNO = 1 ORDER BY STUDENT_NO DESC;

/* 문제2 : STUDENT TABLE에 TNO와 TNO별 학번의 평균값, 학번의 최대값, 최소값을 출력 */
/* 학번의 평균값의 column명은 STDNO_AVG, 최대값은 STDNO_MAX, 최소값은 STDNO_MIN */
/* 이때, 그룹의 조건은 학번의 평균값이 1800이상 */
SELECT TNO, AVG(STUDENT_NO) as STDNO_AVG, MAX(STUDENT_NO) as STDNO_MAX, MIN(STUDENT_NO) as STDNO_MIN
FROM STUDENT
GROUP BY TNO
HAVING AVG(STUDENT_NO) >= 1800;

/* 문제3 : TNO가 2인 것을 3으로 수정 */
/* 테이블 삭제 후 테이블 제약조건 추가하여 다시 생성 */
UPDATE TEACHER SET TEACHER_NO = 3 WHERE TEACHER_NO = 2;

DROP TABLE STUDENT;

create table STUDENT(
	STUDENT_NO INTEGER NOT NULL,
	NAME CHAR(10) NOT NULL,
    FNO INTEGER,
	TNO INTEGER,
    constraint TEACHER_PK primary key(STUDENT_NO),
    constraint STUDENT_FK foreign key(TNO) references TEACHER(TEACHER_NO) ON UPDATE CASCADE
);