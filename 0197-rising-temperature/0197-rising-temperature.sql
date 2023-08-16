# Write your MySQL query statement below
SELECT WEATHER.ID AS 'Id' FROM Weather
JOIN Weather W ON DATEDIFF(WEATHER.RECORDDATE , W.RECORDDATE) = 1 
AND WEATHER.TEMPERATURE > W.TEMPERATURE