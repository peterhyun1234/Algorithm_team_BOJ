SELECT HOUR(DATETIME) AS HOUR, COUNT(HOUR(DATETIME)) AS COUNT
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME)<20 AND HOUR(DATETIME)>=9
GROUP BY HOUR(DATETIME)

ORDER BY HOUR(DATETIME)