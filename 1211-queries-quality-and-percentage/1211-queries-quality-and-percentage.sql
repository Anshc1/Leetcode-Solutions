# Write your MySQL query statement below


SELECT Q.QUERY_NAME AS query_name , ROUND(SUM(Q.RATING/Q.POSITION)/COUNT(*) , 2) AS quality , 
ROUND ( (100* SUM( CASE WHEN Q.RATING <  3 THEN 1 ELSE 0 END) ) /COUNT(*) ,2 ) AS poor_query_percentage
FROM QUERIES Q  
GROUP BY QUERY_NAME 