# Write your MySQL query statement below
SELECT USER_ID AS user_id , COUNT(follower_id) AS followers_count  FROM Followers
GROUP BY USER_ID
ORDER BY USER_ID ASC 