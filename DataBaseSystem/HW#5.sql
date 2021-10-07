use world;

SELECT Name, InDepYear 
FROM country 
WHERE InDepYear = 
		(SELECT InDepYear
        FROM country
        WHERE name = 'Uzbekistan');
        
SELECT c.code, cl.CountryCode, cl.Language, c.Name, cl.Percentage
FROM country AS c
JOIN countrylanguage AS cl
ON c.code = cl.CountryCode
WHERE cl.Language = 'English'
AND cl.percentage >= 90
ORDER BY cl.percentage DESC;

SELECT c.Name
FROM country c JOIN City
ON c.code = City.CountryCode
WHERE c.continent = 'Europe'
AND City.Population > 5000000;