SELECT
    (
        CASE 
            WHEN (SELECT COUNT(DISTINCT salary) FROM Employee) < 2 THEN NULL 
            ELSE sub.salary 
        END
    ) AS SecondHighestSalary
FROM 
(
    SELECT
        DISTINCT salary
    FROM 
        Employee
    ORDER BY
        salary DESC
    LIMIT 2
) sub
ORDER BY
    sub.salary ASC
LIMIT 1 