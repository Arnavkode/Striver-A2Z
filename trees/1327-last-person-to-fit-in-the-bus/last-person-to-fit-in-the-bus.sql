-- Write your PostgreSQL query statement below
WITH running_total AS(
    SELECT person_name, SUM(weight) OVER(ORDER BY turn) AS running  FROM Queue ORDER BY running DESC
) SELECT person_name FROM running_total WHERE running <= 1000 LIMIT 1;