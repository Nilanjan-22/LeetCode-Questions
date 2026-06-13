# Write your MySQL query statement below
select u.name as 'name' , sum(case when r.distance is not null then r.distance else 0 end) as 'travelled_distance' 
from
Users u
left join
Rides r
on
u.id = r.user_id
group by u.id
order by travelled_distance desc, u.name asc;