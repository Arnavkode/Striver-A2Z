with singlenums AS(
    SELECT num from MyNumbers  GROUP BY num HAVING COUNT(num) =1 
) SELECT MAX(num) as num FROM singlenums;