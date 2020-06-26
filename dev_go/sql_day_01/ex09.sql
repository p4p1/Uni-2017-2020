 SELECT min_duration FROM movies WHERE min_duration IS NOT NULL OR min_duration!=0 ORDER BY min_duration LIMIT 1;
