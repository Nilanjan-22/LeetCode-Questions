# Write your MySQL query statement below
select max(M.num) as 'num'
from
(
select m.num
from
MyNumbers m
group by m.num
having count(m.num)=1
) as M