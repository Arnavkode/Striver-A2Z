-- Write your PostgreSQL query statement below
WITH reporting AS(
    SELECT employee_id as under, reports_to, age FROM Employees
)SELECT e.employee_id, e.name, COUNT(r.under) as reports_count, ROUND(AVG(r.age)) as average_age  FROM Employees e LEFT JOIN reporting r ON e.employee_id = r.reports_to GROUP BY e.employee_id, e.name HAVING COUNT(r.under) > 0 ORDER BY e.employee_id;