# Write your MySQL query statement below
with weightPerTurn as
(
    select person_name, turn, sum(weight) over (order by turn) as weightInTurns
    from
    Queue
    order by turn
)

select person_name
from weightPerTurn
where turn  = (
    select max(w.turn)
    from weightPerTurn w
    where weightInTurns<=1000
)
