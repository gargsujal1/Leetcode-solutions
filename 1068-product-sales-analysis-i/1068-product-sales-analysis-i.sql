# Write your MySQL query statement below
# select
# p.product_name,s.year,s.price from
# sales s left join products p on s.product_id=p.product_id;

SELECT P.product_name ,S.year  ,S.price 
FROM Sales  S
LEFT JOIN Product P
ON S.product_id =P.product_id 