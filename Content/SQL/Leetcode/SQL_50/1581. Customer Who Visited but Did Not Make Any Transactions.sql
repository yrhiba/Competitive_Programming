/*
1581. Customer Who Visited but Did Not Make Any Transactions

Link: https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions
*/

-- PostgreSQL query statement
SELECT Visits.customer_id, COUNT(Visits.customer_id) AS count_no_trans
FROM Visits LEFT JOIN Transactions
ON Visits.visit_id=Transactions.visit_id AND amount IS NOT NULL
WHERE amount IS NULL
GROUP BY customer_id;
