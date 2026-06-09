# Write your MySQL query statement below
with rankedSalary as
(
    select *, dense_rank() over (order by salary desc) as salary_rank
    from
    Employee
    group by salary
)

select max(salary) as SecondHighestSalary
from
rankedSalary
where salary_rank=2
