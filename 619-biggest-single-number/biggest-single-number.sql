# Write your MySQL query statement below
select max(num) as 'num'
from
MyNumbers
where num in
(select m.num
from MyNumbers as m
group by m.num
having count(m.num)=1)