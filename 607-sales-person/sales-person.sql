# Write your MySQL query statement below
select name
from
SalesPerson
where 
sales_id not in
(
    select distinct s.sales_id 
    from
    SalesPerson s
    left join
    Orders o
    on s.sales_id = o.sales_id
    left join
    Company c
    on o.com_id = c.com_id
    where c.name = 'RED'
)