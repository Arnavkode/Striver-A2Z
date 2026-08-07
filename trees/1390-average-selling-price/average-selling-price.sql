-- Write your PostgreSQL query statement below
WITH tab AS(SELECT p.product_id, units, price FROM Prices p LEFT JOIN UnitsSold u ON p.product_id  = u.product_id AND u.purchase_date BETWEEN p.start_date AND p.end_date)
SELECT product_id, COALESCE(ROUND(SUM(units*price)/SUM(units)::numeric, 2),0) AS average_price FROM tab GROUP BY product_id;