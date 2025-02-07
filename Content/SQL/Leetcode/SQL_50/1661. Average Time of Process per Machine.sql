/*
1661. Average Time of Process per Machine

Link: https://leetcode.com/problems/average-time-of-process-per-machine/
*/

-- PostgreSQL query statement
SELECT T1.machine_id, ROUND(AVG(T2.timestamp - T1.timestamp)::numeric, 3) AS processing_time
FROM Activity AS T1 JOIN Activity AS T2
ON T1.machine_id=T2.machine_id AND T1.process_id=T2.process_id 
AND T1.activity_type<>T2.activity_type
AND T1.activity_type='start'
GROUP BY T1.machine_id;
