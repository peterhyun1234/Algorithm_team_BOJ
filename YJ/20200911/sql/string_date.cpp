1. SELECT ANIMAL_ID,NAME,SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME IN("Lucy","Ella","Pickle","Rogan","Sabrina","Mitty")
ORDER BY ANIMAL_ID ASC;

2. SELECT ANIMAL_ID,NAME
FROM ANIMAL_INS
WHERE NAME LIKE "%el%"
AND ANIMAL_TYPE="DOG"
ORDER BY NAME;

3. SELECT ANIMAL_ID,NAME,IF(SEX_UPON_INTAKE LIKE "%Neutered%" OR SEX_UPON_INTAKE LIKE "%Spayed%","O","X")
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;

4. SELECT A.ANIMAL_ID, A.NAME
FROM ANIMAL_OUTS AS A
JOIN ANIMAL_INS AS B
WHERE A.ANIMAL_ID = B.ANIMAL_ID
ORDER BY A.DATETIME - B.DATETIME DESC
LIMIT 2;

5. SELECT ANIMAL_ID,NAME,date_format(DATETIME, "%Y-%m-%d") AS "날짜"
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;
