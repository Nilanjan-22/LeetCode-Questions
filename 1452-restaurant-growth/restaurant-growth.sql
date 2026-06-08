# Write your MySQL query statement below
with cumulatedAmount as
(
    select distinct visited_on, sum(amount) over (order by visited_on) as sumAmount, dense_rank() over (order by visited_on) as day_rank
    from Customer
),

finalTable as (
    select a1.visited_on ,(case when a2.visited_on is null then a1.sumAmount else a1.sumAmount-a2.sumAmount end) as amount
    from
    cumulatedAmount a1
    left join 
    cumulatedAmount a2
    on
    a1.day_rank = a2.day_rank+7
    where a1.day_rank>=7
)

select * , round((amount/7),2) as average_amount
from finalTable;