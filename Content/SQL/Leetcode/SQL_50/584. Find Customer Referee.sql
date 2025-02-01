/*
584. Find Customer Referee

Link: https://leetcode.com/problems/find-customer-referee/
*/

-- PostgreSQL query statement
SELECT name FROM Customer WHERE referee_id!=2 OR referee_id IS NULL;
