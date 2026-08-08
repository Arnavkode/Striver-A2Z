-- Write your PostgreSQL query statement below
with freq AS(
    SELECT num, COUNT(num) as fre FROM MyNumbers GROUP BY num
) SELECT MAX(num) as num FROM freq WHERE fre = 1;