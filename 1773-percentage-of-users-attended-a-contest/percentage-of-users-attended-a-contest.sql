select r.contest_id as 'contest_id', round(100*(count(distinct r.user_id)/count(distinct u.user_id)),2) as 'percentage'
from
register r
cross join
Users u
group by r.contest_id
order by percentage desc , r.contest_id asc;
