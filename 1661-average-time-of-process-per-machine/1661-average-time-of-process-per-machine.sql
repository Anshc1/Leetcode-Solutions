# Write your MySQL query statement below
select activity.machine_id , 
round( sum(case when activity.activity_type = 'end' then timestamp else 0 end - case when activity.activity_type = 'start' then timestamp else 0 end )/count(distinct process_id) ,3 ) as processing_time
from activity 
group by machine_id
  