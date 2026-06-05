# Write your MySQL query statement below
select s.user_id as 'user_id' , 
round(
    (count(case
        when c.action is null then null
        when c.action = 'timeout' then null
        else  1
        end
    )/count(case 
        when c.action is null then 1
        else 1
        end
    )),2) as 'confirmation_rate'
from
Signups s
left join
Confirmations c
on 
s.user_id = c.user_id
group by s.user_id;