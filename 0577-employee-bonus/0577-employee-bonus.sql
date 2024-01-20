# Write your MySQL query statement belo


SELECT 
    Employee.name as name , 
    COALESCE(Bonus.bonus, null) AS bonus
FROM 
    Employee
LEFT JOIN 
    Bonus ON Employee.empId = Bonus.empId
WHERE 
    Bonus.bonus < 1000 OR Bonus.bonus IS NULL;

