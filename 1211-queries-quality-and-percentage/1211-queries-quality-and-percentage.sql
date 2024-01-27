SELECT 
    q.query_name, 
    ROUND(AVG(q.rating / q.position), 2) AS quality,
    ROUND(100.0 * SUM(CASE WHEN q.rating < 3 THEN 1 ELSE 0 END) / COUNT(*), 2) AS poor_query_percentage
FROM 
    queries AS q
WHERE 
    q.query_name is NOT NULL 
GROUP BY 
    q.query_name;
