use world;

SELECT Population, LifeExpectancy
FROM country
WHERE Continent = 'Asia'
AND Population > 1000000
ORDER BY Population ASC;

SELECT co.Name, c.Name, c.Population
FROM country AS co, city AS c
WHERE co.Code = c.CountryCode
GROUP BY c.CountryCode
ORDER BY c.Population DESC
LIMIT 1;

SELECT Name
FROM Country
WHERE Code IN (SELECT CountryCode
				FROM CountryLanguage
                WHERE Language = 'Greek');