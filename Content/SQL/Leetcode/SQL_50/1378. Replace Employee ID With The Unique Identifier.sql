/*
1378. Replace Employee ID With The Unique Identifier

Link: https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/
*/

-- PostgreSQL query statement
SELECT EmployeeUNI.unique_id, Employees.name
FROM Employees LEFT JOIN EmployeeUNI
ON Employees.id=EmployeeUNI.id;
