# Write your MySQL query statement below
(select u.name as results
from
Users u
left join 
MovieRating mr
on u.user_id = mr.user_id
group by u.user_id
order by count(mr.movie_id) desc, u.name asc
limit 1)

union all

(select m.title as results
from 
MovieRating mr
left join
Movies m
on mr.movie_id = m.movie_id
where mr.created_at >='2020-02-01' and mr.created_at <= '2020-02-29'
group by mr.movie_id
order by avg(mr.rating) desc, m.title asc
limit 1)
