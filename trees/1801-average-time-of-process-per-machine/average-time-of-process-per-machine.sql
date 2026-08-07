-- Write your PostgreSQL query statement below
WITH start_times AS(
    SELECT machine_id, process_id, timestamp FROM Activity WHERE activity_type = 'start'
),
end_times AS(
    SELECT machine_id, process_id, timestamp FROM Activity WHERE activity_type = 'end'
) SELECT s.machine_id, ROUND(AVG(e.timestamp - s.timestamp)::numeric, 3) AS processing_time FROM start_times s JOIN end_times e ON s.machine_id = e.machine_id AND s.process_id = e.process_id GROUP BY s.machine_id;