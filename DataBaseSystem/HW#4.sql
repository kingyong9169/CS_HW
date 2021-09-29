USE world;

SELECT name, population FROM country WHERE name = 'south korea';

SELECT name, population FROM country WHERE Continent ='Asia' ORDER BY population DESC LIMIT 1;

SELECT continent, COUNT(name) AS country_num FROM country GROUP BY continent HAVING COUNT(name)>=5;

