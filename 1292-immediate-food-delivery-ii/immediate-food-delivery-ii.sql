# Write your MySQL query statement below
select round(100*(count(case when order_date = customer_pref_delivery_date then 1 else null end )/(count(order_date))),2) as 'immediate_percentage'
from
Delivery
where (customer_id, order_date) 
in
(
select d.customer_id, min(order_date)
from Delivery d
group by d.customer_id
)
