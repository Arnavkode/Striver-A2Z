-- Write your PostgreSQL query statement below
WITH ranked AS(
    SELECT product_id, new_price, ROW_NUMBER() OVER(PARTITION BY product_id ORDER BY change_date DESC) AS rnk FROM Products WHERE change_date <= '2019-08-16'
), ans AS(SELECT product_id, new_price as price from ranked WHERE rnk = 1)
SELECT p.product_id, COALESCE(a.price, 10) as price FROM (SELECT DISTINCT product_id FROM Products) p LEFT JOIN ans a ON p.product_id = a.product_id;