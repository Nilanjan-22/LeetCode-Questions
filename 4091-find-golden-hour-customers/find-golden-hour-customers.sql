# Write your MySQL query statement below
with finalTable as
(
    select customer_id, count(order_id)as 'total_orders', count(case when time(order_timestamp) between '11:00:00' and '14:00:00' then 1 when time(order_timestamp) between '18:00:00' and '21:00:00' then 1 else null end) as 'golden_hour_orders' , round(avg(order_rating),2) as 'average_rating', count(case when order_rating is null then 1 else null end) as 'unrated_orders'
    from
    restaurant_orders
    group by customer_id
)

select customer_id , total_orders, round(100*(golden_hour_orders/total_orders),0) as 'peak_hour_percentage' , average_rating
from
finalTable
where 
total_orders>=3 and round(100*(golden_hour_orders/total_orders),0)>=60 and average_rating >=4 and round(100*(unrated_orders/total_orders),2)<=50
order by average_rating desc, customer_id desc;