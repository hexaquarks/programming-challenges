SELECT
    p.email AS EMAIL
FROM 
    Person p
GROUP BY 
    EMAIL
HAVING 
    COUNT(EMAIL) > 1