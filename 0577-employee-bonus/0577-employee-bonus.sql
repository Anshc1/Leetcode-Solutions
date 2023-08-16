# Write your MySQL query statement belowse

select Employee.name  , bonus.bonus from employee 
left join bonus on employee.empid = bonus.empid
where bonus.bonus < 1000 or bonus.bonus is NULL 