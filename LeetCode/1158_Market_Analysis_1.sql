SELECT
    Users.user_id AS buyer_id,
    Users.join_date,
    COUNT(
        CASE 
            WHEN Orders.order_date >= "2019-01-01" AND Orders.order_date <= "2019-12-31"
            THEN Orders.order_id 
        END 
    ) AS orders_in_2019
FROM 
    Users
LEFT JOIN 
    Orders
ON
    Users.user_id = Orders.buyer_id
WHERE 
    Users.join_date <= DATE("2020-01-01") 
GROUP BY
    Users.user_id, Orders.buyer_id