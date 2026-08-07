-- Write your PostgreSQL query statement below
SELECT * FROM Cinema WHERE MOD(id::numeric,2.0) = 1 AND description <> 'boring' ORDER BY rating DESC; 