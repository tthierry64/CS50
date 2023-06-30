SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE people.name IN ("Helena Bonham Carter")
INTERSECT
SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE people.name IN ("Johnny Depp");


-- OR
-- SELECT title FROM movies
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON people.id = stars.person_id
-- WHERE people.name IN ("Helena Bonham Carter")
-- AND
-- title IN (
-- SELECT title FROM movies
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON people.id = stars.person_id
-- WHERE people.name IN ("Johnny Depp"));

