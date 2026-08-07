-- Write your PostgreSQL query statement below
WITH tab AS(
    SELECT p.project_id, e.experience_years FROM Project p LEFT JOIN Employee e ON p.employee_id = e.employee_id
) SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years FROM tab GROUP BY project_id;