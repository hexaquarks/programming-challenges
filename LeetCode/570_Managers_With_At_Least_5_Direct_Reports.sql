SELECT 
    name
FROM 
    Employee
JOIN (
    SELECT
        managerId,
        COUNT(*) as Counts
    FROM 
        Employee
    GROUP BY
        managerId
) sub
ON 
    id = sub.managerId AND sub.Counts >= 5
