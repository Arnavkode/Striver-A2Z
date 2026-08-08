-- Write your PostgreSQL query statement below
SELECT customer_id from Customer GROUP BY customer_id HAVING count(DISTINCT product_key) = (select count(DISTINCT product_key) from Product);