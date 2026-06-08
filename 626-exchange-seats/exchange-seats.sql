# Write your MySQL query statement below
select (case when s.id%2 = 0 then s.id-1 when s.id <> (select max(s1.id) from Seat s1) then s.id+1 else s.id end) as 'id' , s.student
from Seat s
order by id;