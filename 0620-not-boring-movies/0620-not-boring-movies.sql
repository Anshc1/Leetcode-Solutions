# Write your MySQL query statement below
select * from cinema where cinema.description != 'boring' and cinema.id%2 =1 
order by rating desc