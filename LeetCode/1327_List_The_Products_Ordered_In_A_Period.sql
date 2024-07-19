
SELECT
    Products.product_name,
    SUM(unit) AS unit
FROM
    Products
JOIN
    Orders
ON
    Products.product_id = Orders.product_id
WHERE
    Orders.order_date >= "2020-02-00" AND Orders.order_date < "2020-03-01"
GROUP BY 
    Products.product_name
HAVING 
    unit >= 100
ORDER BY
    Orders.product_id ASC