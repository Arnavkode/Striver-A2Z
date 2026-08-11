-- Write your PostgreSQL query statement below
WITH salary_categories AS(
    SELECT CASE 
    WHEN income < 20000 THEN 'Low Salary'
    WHEN income <= 50000 THEN 'Average Salary'
    ELSE 'High Salary' END AS category, account_id FROM Accounts
), categories AS(
    SELECT 'Low Salary' as category
    UNION ALL SELECT 'Average Salary'
    UNION ALL SELECT 'High Salary'
)SELECT c.category, coalesce(COUNT(s.account_id), 0) AS accounts_count FROM salary_categories s RIGHT JOIN categories c ON s.category = c.category GROUP BY c.category;