use world;

CREATE VIEW cityInfo_view
AS SELECT ID, CountryCode, NAME, District, Population
FROM city
WHERE CountryCode = "KOR";

SELECT *
FROM cityInfo_view;

INSERT INTO cityInfo_view
VALUES (8500, 'KOR', 'Cheongju', 'Chungchungbuk', 850000),
(6500, 'KOR', 'Cheonan', 'Chungchungnam', 650000);


CREATE VIEW AsiaMillionView
AS SELECT Code, Name, Continent, Population
FROM country
WHERE Population >= 1000000 AND Continent = 'Asia'
ORDER BY Population DESC;

SELECT *
FROM AsiaMillionView;

INSERT INTO AsiaMillionView
VALUES ('SEO', 'Seoul', 'Asia', 10000000),
('GYU', 'Gyunggi', 'Asia', 3700000);


CREATE VIEW KoreanLangView
AS SELECT CountryCode, Language, Percentage
FROM countrylanguage
WHERE Language = 'korean'
ORDER BY Percentage DESC;

SELECT *
FROM KoreanLangView;

INSERT INTO KoreanLangView
VALUES ('RUS', 'Korean', 99.9),
('CHN', 'Korean', 99.9);