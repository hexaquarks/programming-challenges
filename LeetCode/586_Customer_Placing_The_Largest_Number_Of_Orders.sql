/* My answer */
SELECT 
    sub.customer_number AS customer_number
FROM (
    SELECT
        customer_number,
        COUNT(*) AS Counts
    FROM 
        Orders
    GROUP BY 
        customer_number
) sub
ORDER BY
    sub.Counts DESC
LIMIT 1

/* Shorter and better solution */
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;