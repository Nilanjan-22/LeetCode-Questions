# Write your MySQL query statement below
select s.user_id as 'user_id' , 
round(
    (sum(case
        when c.action is null then 0
        when c.action = 'timeout' then 0
        else  1
        end
    )/sum(case 
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