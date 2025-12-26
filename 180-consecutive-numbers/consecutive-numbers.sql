# Write your MySQL query statement below
with temp as (
    select *,
    id-cast(row_number() over(partition by num order by id) as signed) as grp
    from Logs
)

select distinct num as 'ConsecutiveNums' from temp group by grp, num having count(id)>=3 ;