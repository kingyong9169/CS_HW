use DBMS_tutoring;

INSERT INTO TEACHER
VALUES (3, '윤선생'),
	   (4, '최선생');
       
/* 문제 1 : WHERE을 써서 INNER JOIN
			TEACHER 테이블의 별칭은 T, STUDENT 테이블의 별칭은 S,
            TEACHER_NO와 선생님이름, 학생이름, 학생의 선생님번호(TNO) 출력
*/
SELECT T.TEACHER_NO T_TNO, T.NAME TEACHER, S.NAME STUDENT, S.TNO S_TNO
FROM TEACHER T, STUDENT S
WHERE T.TEACHER_NO = S.TNO;

/* 문제 2 : LEFT JOIN (TEACHER TABLE의 왼쪽)
			TEACHER 테이블의 별칭은 T, STUDENT 테이블의 별칭은 S,
            TEACHER_NO와 선생님이름, 학생이름, 학생의 선생님번호(TNO) 출력
*/
SELECT T.TEACHER_NO T_TNO, T.NAME TEACHER, S.NAME STUDENT, S.TNO S_TNO
FROM TEACHER T LEFT JOIN STUDENT S
ON T.TEACHER_NO = S.TNO;

/* 문제 3 : 이름이 김선생인 사람의 TEACHER_NO와 같은 TNO를 가진 학생의 이름을 출력해라 */
SELECT TNO, NAME
FROM STUDENT
WHERE TNO = (SELECT TEACHER_NO
			FROM TEACHER
            WHERE NAME = '김선생');