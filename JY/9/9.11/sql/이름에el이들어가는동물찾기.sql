SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME Like '%el%' and animal_type = 'Dog'
order by name