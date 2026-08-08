-- Write your PostgreSQL query statement below
WITH first_order AS(
    SELECT customer_id, MIN(order_date) as order, MIN(customer_pref_delivery_date) as delivered FROM Delivery GROUP BY customer_id 
)SELECT ROUND(COUNT(f.order)*100/(SELECT COUNT(*) FROM first_order)::NUMERIC, 2) as immediate_percentage FROM first_order f WHERE f.order = f.delivered; 