select contest_id , round(100*(count(user_id)/(select count(u.user_id) from Users u)),2) as 'percentage'
from
Register
group by contest_id
order by percentage desc , contest_id asc;
