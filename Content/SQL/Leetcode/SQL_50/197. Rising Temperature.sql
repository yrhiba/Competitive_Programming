/*
197. Rising Temperature

Link: https://leetcode.com/problems/rising-temperature
*/

-- PostgreSQL query statement
SELECT W1.id AS Id FROM Weather AS W1 JOIN Weather AS W2
ON W1.recordDate = W2.recordDate + INTERVAL '1 day'
WHERE W1.temperature>W2.temperature;
