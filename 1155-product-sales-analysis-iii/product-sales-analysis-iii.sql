# Write your MySQL query statement below
select product_id, year as first_year , quantity, price
from
Sales
where (product_id, year) in
(
    select s.product_id, min(s.year)
    from
    Sales s
    group by s.product_id
)