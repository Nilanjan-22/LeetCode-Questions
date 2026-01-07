# Write your MySQL query statement below
WITH ranked_logins AS (
    SELECT
        player_id,
        event_date,
        MIN(event_date) OVER (PARTITION BY player_id) AS first_login
    FROM Activity
)
select round(count(case when datediff(event_date, first_login)=1 then 1 else null end)/count(distinct player_id),2) as'fraction' from ranked_logins ;