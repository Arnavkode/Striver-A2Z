-- Write your PostgreSQL query statement below
WITH first_years AS(
    select product_id, MIN(year) as first_year FROM Sales GROUP BY product_id
)SELECT s.product_id, f.first_year, s.quantity, s.price FROM Sales s LEFT JOIN first_years f on s.product_id = f.product_id WHERE s.year = f.first_year; 