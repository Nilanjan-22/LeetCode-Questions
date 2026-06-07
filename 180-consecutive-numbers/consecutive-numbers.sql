# Write your MySQL query statement below
with newLogs as (
select num, lag(num,1,null) over (order by id) as prev , lead(num,1,null) over (order by id) as next
from
Logs)

select distinct num as 'ConsecutiveNums'
from newLogs 
where num=prev and num=next;