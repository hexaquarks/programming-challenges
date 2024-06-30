SELECT 
    d.name AS Department,
    sub.Employee,
    sub.Salary
FROM (
    SELECT 
        e.name AS Employee,
        e.salary AS Salary,
        e.departmentId as DepartmentId
    FROM
        Employee e
    JOIN (
        SELECT 
            departmentId,
            MAX(salary) AS MaxSalary
        FROM
            Employee
        GROUP BY 
            departmentId
    ) maxSalaries
    ON 
        e.departmentId = maxSalaries.departmentId
        AND e.salary = maxSalaries.MaxSalary
) sub
JOIN 
    Department d
ON 
    sub.DepartmentId = d.id;
