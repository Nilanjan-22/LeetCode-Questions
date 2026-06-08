# Write your MySQL query statement below
with finalTable as
(
    select e.name as Employee ,e.salary as Salary ,d.name as Department, dense_rank() over (partition by e.departmentId order by e.salary desc) as department_rank
    from
    Employee e
    left join
    Department d
    on e.departmentId=d.id
)

select Department,Employee,Salary
from
finalTable
where department_rank<4