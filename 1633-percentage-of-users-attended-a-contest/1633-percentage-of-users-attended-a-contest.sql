# Write your MySQL query statement belo

select r.contest_id as contest_id ,round(count(distinct(u.user_id))*100/
(select count(distinct user_id  ) from users ) , 2) as percentage

from register r join users u

on u.user_id = r.user_id

group by r.contest_id

order by percentage desc , contest_id asc 


    