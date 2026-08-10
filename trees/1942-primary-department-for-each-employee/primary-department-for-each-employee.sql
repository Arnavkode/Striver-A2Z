-- Write your PostgreSQL query statement below
WITH primary_depts AS(
    SELECT employee_id, department_id, RANK() OVER(PARTITION BY employee_id ORDER BY primary_flag DESC) as rnk FROM Employee
) SELECT employee_id, department_id FROM primary_depts WHERE rnk  =1;