# Write your MySQL query statement below
select query_name, round(avg(rating/position),2) as 'quality' , round(100*(count(case when rating >= 3 then null else 1 end)/count(rating)),2) as 'poor_query_percentage'
from Queries 
group by query_name;