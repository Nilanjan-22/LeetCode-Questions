# Write your MySQL query statement below
select employee_id, department_id
from 
Employee
where
primary_flag = 'Y'
or 
employee_id 
in
(
    select e.employee_id
    from
    Employee e
    group by e.employee_id
    having count(department_id)=1
)