# Write your MySQL query statement below
with finalTable as
(
    select distinct visited_on, sum(amount) over (order by visited_on RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW) as amount, dense_rank() over (order by visited_on) as day_rank
    from Customer
)

select visited_on, amount , round((amount/7),2) as average_amount
from finalTable
where day_rank>=7