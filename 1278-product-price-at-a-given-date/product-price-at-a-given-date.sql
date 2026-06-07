# Write your MySQL query statement below
with changeTable as
(
    select p.product_id, max(p.change_date) as last_date
    from
    Products p
    where p.change_date <='2019-08-16'
    group by p.product_id
) 
select p.product_id , (case when ct.last_date is null then 10 else new_price end) as price
from
Products p
left join
changeTable ct
on p.product_id = ct.product_id
where p.change_date = ct.last_date or ct.product_id is null
group by p.product_id
