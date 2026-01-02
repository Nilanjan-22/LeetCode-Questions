# Write your MySQL query statement below
select e2.name as 'name' from Employee as e1 left join Employee as e2 on e1.managerId=e2.id where e2.id is not null group by e2.id having count(e1.id)>=5;