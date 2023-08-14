# Write your MySQL query statement below

select e.name as name, b.bonus as bonus
from Employee e left join Bonus b on e.empId = b.empId
WHERE COALESCE(b.bonus, 0) < 1000; 
