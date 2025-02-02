/*
1068. Product Sales Analysis I

Link: https://leetcode.com/problems/product-sales-analysis-i
*/

-- PostgreSQL query statement
SELECT Product.product_name, Sales.year, Sales.price
FROM Sales INNER JOIN Product
ON Sales.product_id=Product.product_id;
