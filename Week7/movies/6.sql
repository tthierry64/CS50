--SELECT AVG(rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);

-- Fastest :

--SELECT AVG(rating) FROM movies JOIN ratings ON id = ratings.movie_id WHERE year = 2012;
--ou
SELECT AVG(rating) FROM ratings JOIN movies ON movie_id = movies.id WHERE movies.year = 2012;