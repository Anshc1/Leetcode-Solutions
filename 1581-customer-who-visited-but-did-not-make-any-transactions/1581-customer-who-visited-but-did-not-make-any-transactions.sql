SELECT customer_id, COUNT(customer_id) as count_no_trans
FROM visits AS v
LEFT JOIN transactions AS t ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
Group BY customer_id

