-- Write your PostgreSQL query statement below
with prev_row as(
    SELECT id,recordDate, temperature,LAG(recordDate, 1, NULL) OVER(ORDER BY recordDate) as prev_date ,LAG(temperature, 1, NULL) OVER(ORDER BY recordDate) as prev_temp FROM Weather
)
SELECT id FROM prev_row WHERE recordDate - prev_date = 1 AND temperature > prev_temp;