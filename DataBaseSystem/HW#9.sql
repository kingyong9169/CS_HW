use practice11;

SELECT * FROM employees where last_name = 'Peron';

CREATE INDEX last_name_index ON employees (last_name);
SELECT * FROM employees where last_name = 'Peron';

SELECT first_name, COUNT(first_name) AS total
FROM employees GROUP BY first_name;

CREATE INDEX first_name_index ON employees (first_name);
SELECT first_name, COUNT(first_name) AS total
FROM employees GROUP BY first_name;

SELECT hire_date, gender FROM employees
ORDER BY birth_date DESC;

CREATE INDEX hire_date_index ON employees (hire_date);
SELECT hire_date, gender FROM employees
ORDER BY birth_date DESC;