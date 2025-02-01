/*
1683. Invalid Tweets

Link: https://leetcode.com/problems/invalid-tweets
*/

-- PostgreSQL query statement
SELECT tweet_id FROM Tweets WHERE LENGTH(content)>15;
