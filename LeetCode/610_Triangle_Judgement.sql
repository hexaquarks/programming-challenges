SELECT 
    x,
    y,
    z,
    CASE 
        WHEN (x + y > z) AND (x + z > y) AND (z + y > x) THEN "Yes"
        ELSE "No"
    END AS triangle
FROM 
    Triangle

/* Much more simple and intuitive solution... */
SELECT 
    x,
    y,
    z,
    IF ( x + y > z AND x + z > y AND z + y > x, "Yes", "No")
    AS triangle
FROM 
    Triangle

/* Seems like CASE is inbuilt and more versatile */
/* Prefer CASE over IF */
