# Write your MySQL query statement below
select project.project_id as project_id , round(sum(Employee.experience_years)/(count(distinct Project.employee_id)) , 2) as average_years
from Project 
join employee 
on project.employee_id = Employee.employee_id
group by project.project_id