/*
577. Employee Bonus

Link: https://leetcode.com/problems/employee-bonus
*/

-- PostgreSQL query statement
SELECT Employee.name, Bonus.bonus
FROM Employee LEFT JOIN Bonus
ON Employee.empId=Bonus.empId
WHERE Bonus.bonus<1000 OR Bonus.bonus IS NULL;
