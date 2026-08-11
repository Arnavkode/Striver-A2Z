SELECT
(SELECT u.name FROM Users u LEFT JOIN MovieRating m ON u.user_id = m.user_id GROUP BY u.name HAVING COUNT(rating) >= ALL(SELECT COUNT(rating) FROM MovieRating GROUP BY user_id) ORDER BY u.name LIMIT 1) AS results
UNION ALL 
(SELECT m.title FROM Movies m LEFT JOIN MovieRating r ON m.movie_id = r.movie_id WHERE r.created_at <= '2020-02-29' AND r.created_at >= '2020-02-01' GROUP BY m.title HAVING AVG(rating) >= ALL(SELECT Avg(rating) FROM MovieRating WHERE created_at <= '2020-02-29' AND created_at >= '2020-02-01' GROUP BY movie_id) ORDER BY m.title LIMIT 1);