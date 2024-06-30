SELECT 
    sub.Employee as Employee
FROM (
    SELECT 
        e1.name AS Employee,
        e1.salary AS EmployeeSalary,
        e2.salary AS ManagerSalary
    FROM 
        Employee e1
    LEFT JOIN 
        Employee e2
    ON 
        e1.managerId = e2.id
) sub 
WHERE 
    sub.ManagerSalary IS NOT NULL AND sub.EmployeeSalary > sub.ManagerSalary