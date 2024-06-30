SELECT 
    s.product_id, 
    s.year AS first_year,
    s.quantity,
    s.price
FROM 
    Sales s
INNER JOIN (
    SELECT
        s.product_id,
        MIN(s.year) AS first_year
    FROM 
        Sales s
    GROUP BY 
        s.product_id
) sub 
ON 
    s.product_id = sub.product_id AND s.year = sub.first_year