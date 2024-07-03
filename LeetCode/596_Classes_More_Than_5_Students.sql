SELECT 
    sub.class
FROM (
    SELECT 
        class,
        COUNT(*) AS counts
    FROM 
        Courses
    GROUP BY
        class
) as sub
WHERE 
    sub.counts >= 5

/* Much more concise solution */
SELECT  
    class 
FROM 
    Courses
GROUP BY    
    class HAVING COUNT(class) >= 5