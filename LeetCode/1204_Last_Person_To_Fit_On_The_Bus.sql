SELECT
    sub.person_name AS person_name
FROM
(
    SELECT 
        person_name,
        SUM(weight) OVER (ORDER BY turn ASC) AS cum_sum
    FROM 
        Queue
) sub
WHERE 
    sub.cum_sum <= 1000
ORDER BY
    sub.cum_sum DESC
LIMIT 1