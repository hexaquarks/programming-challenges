SELECT
    name
FROM
    SalesPerson 
WHERE 
    name
NOT IN
(
    SELECT
        SalesPerson.name AS Name
    FROM 
        SalesPerson
    JOIN
        Orders
    ON
        Orders.sales_id  = SalesPerson.sales_id
    JOIN 
        Company
    ON 
        Orders.com_id = Company.com_id
    WHERE
        Company.name = "RED"
)