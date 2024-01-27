# Write your MySQL query statement belSEKE
SELECT c.class 
from courses as c 
group by c.class
having count(c.student) >= 5 