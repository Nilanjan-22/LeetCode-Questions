# Write your MySQL query statement below
select round((count(a2.event_date)/count(a1.event_date)),2) as 'fraction'
from 
Activity a1
left join
Activity a2
on date_add(a1.event_date, interval 1 day) = a2.event_date and a1.player_id=a2.player_id
where 
(a1.player_id, a1.event_date)
in
(
    select a.player_id, min(a.event_date)
    from
    Activity a
    group by a.player_id
);
