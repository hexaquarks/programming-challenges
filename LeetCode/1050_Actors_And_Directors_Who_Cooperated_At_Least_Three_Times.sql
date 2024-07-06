SELECT
    actor_id,
    director_id
FROM
    ActorDirector    
GROUP BY
    actor_id, director_id
HAVING 
    COUNT(*) >= 3

/* Cool, we use composite columns in the group clause! */