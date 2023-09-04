# Write your MySQL query statement below
SELECT name FROM Customer WHERE id NOT IN(
SELECT id from Customer where referee_id=2);