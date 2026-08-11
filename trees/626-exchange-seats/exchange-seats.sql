-- Write your PostgreSQL query statement below
WITH nexts AS(
    SELECT * , lag(student, 1, student) OVER(ORDER BY id) AS last_seat FROM Seat 
)SELECT s.id, CASE
WHEN MOD(s.id, 2) = 0 THEN last_seat
WHEN MOD(s.id, 2) = 1 THEN COALESCE((SELECT student FROM Seat WHERE id = s.id  +1), student)
END AS student FROM nexts s;